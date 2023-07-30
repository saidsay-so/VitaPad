#ifndef NET_HPP
#define NET_HPP

#include <psp2/net/net.h>

#include <array>
#include <cstdint>
#include <optional>
#include <vector>

typedef struct {
  SceUID ev_flag_connect_state;
} NetThreadMessage;

enum ConnectionState {
  DISCONNECT = 1,
  CONNECT = 2,
};

constexpr const char *sce_net_strerror(unsigned int error_code) {
  switch (error_code) {
  case SCE_NET_ERROR_RESOLVER_EALIGNMENT:
    return "SCE_NET_ERROR_RESOLVER_EALIGNMENT";
  case SCE_NET_ERROR_RESOLVER_ENORECORD:
    return "SCE_NET_ERROR_RESOLVER_ENORECORD";
  case SCE_NET_ERROR_RESOLVER_ESERVERREFUSED:
    return "SCE_NET_ERROR_RESOLVER_ESERVERREFUSED";
  case SCE_NET_ERROR_RESOLVER_ENOTIMPLEMENTED:
    return "SCE_NET_ERROR_RESOLVER_ENOTIMPLEMENTED";
  case SCE_NET_ERROR_RESOLVER_ENOHOST:
    return "SCE_NET_ERROR_RESOLVER_ENOHOST";
  case SCE_NET_ERROR_RESOLVER_ESERVERFAILURE:
    return "SCE_NET_ERROR_RESOLVER_ESERVERFAILURE";
  case SCE_NET_ERROR_RESOLVER_EFORMAT:
    return "SCE_NET_ERROR_RESOLVER_EFORMAT";
  case SCE_NET_ERROR_RESOLVER_ENOSUPPORT:
    return "SCE_NET_ERROR_RESOLVER_ENOSUPPORT";
  case SCE_NET_ERROR_RESOLVER_ETIMEDOUT:
    return "SCE_NET_ERROR_RESOLVER_ETIMEDOUT";
  case SCE_NET_ERROR_RESOLVER_ENODNS:
    return "SCE_NET_ERROR_RESOLVER_ENODNS";
  case SCE_NET_ERROR_RESOLVER_ERESERVED22:
    return "SCE_NET_ERROR_RESOLVER_ERESERVED22";
  case SCE_NET_ERROR_RESOLVER_EPACKET:
    return "SCE_NET_ERROR_RESOLVER_EPACKET";
  case SCE_NET_ERROR_RESOLVER_ENOSPACE:
    return "SCE_NET_ERROR_RESOLVER_ENOSPACE";
  case SCE_NET_ERROR_RESOLVER_EBUSY:
    return "SCE_NET_ERROR_RESOLVER_EBUSY";
  case SCE_NET_ERROR_RESOLVER_EINTERNAL:
    return "SCE_NET_ERROR_RESOLVER_EINTERNAL";
  case SCE_NET_ERROR_ERETURN:
    return "SCE_NET_ERROR_ERETURN";
  case SCE_NET_ERROR_EINTERNAL:
    return "SCE_NET_ERROR_EINTERNAL";
  case SCE_NET_ERROR_ECALLBACK:
    return "SCE_NET_ERROR_ECALLBACK";
  case SCE_NET_ERROR_ERESERVED202:
    return "SCE_NET_ERROR_ERESERVED202";
  case SCE_NET_ERROR_ENOLIBMEM:
    return "SCE_NET_ERROR_ENOLIBMEM";
  case SCE_NET_ERROR_ENOTINIT:
    return "SCE_NET_ERROR_ENOTINIT";
  case SCE_NET_ERROR_ERESUME:
    return "SCE_NET_ERROR_ERESUME";
  case SCE_NET_ERROR_EDISABLEDIF:
    return "SCE_NET_ERROR_EDISABLEDIF";
  case SCE_NET_ERROR_EADHOC:
    return "SCE_NET_ERROR_EADHOC";
  case SCE_NET_ERROR_ETIME:
    return "SCE_NET_ERROR_ETIME";
  case SCE_NET_ERROR_ENOSTR:
    return "SCE_NET_ERROR_ENOSTR";
  case SCE_NET_ERROR_ENOSR:
    return "SCE_NET_ERROR_ENOSR";
  case SCE_NET_ERROR_ENODATA:
    return "SCE_NET_ERROR_ENODATA";
  case SCE_NET_ERROR_EBADMSG:
    return "SCE_NET_ERROR_EBADMSG";
  case SCE_NET_ERROR_ECANCELED:
    return "SCE_NET_ERROR_ECANCELED";
  case SCE_NET_ERROR_ENOTSUP:
    return "SCE_NET_ERROR_ENOTSUP";
  case SCE_NET_ERROR_EILSEQ:
    return "SCE_NET_ERROR_EILSEQ";
  case SCE_NET_ERROR_EOVERFLOW:
    return "SCE_NET_ERROR_EOVERFLOW";
  case SCE_NET_ERROR_ENOMS:
    return "SCE_NET_ERROR_ENOMS";
  case SCE_NET_ERROR_EIDRM:
    return "SCE_NET_ERROR_EIDRM";
  case SCE_NET_ERROR_ENEEDAUTH:
    return "SCE_NET_ERROR_ENEEDAUTH";
  case SCE_NET_ERROR_EAUTH:
    return "SCE_NET_ERROR_EAUTH";
  case SCE_NET_ERROR_EFTYPE:
    return "SCE_NET_ERROR_EFTYPE";
  case SCE_NET_ERROR_ENOSYS:
    return "SCE_NET_ERROR_ENOSYS";
  case SCE_NET_ERROR_ENOLCK:
    return "SCE_NET_ERROR_ENOLCK";
  case SCE_NET_ERROR_EPROCUNAVAIL:
    return "SCE_NET_ERROR_EPROCUNAVAIL";
  case SCE_NET_ERROR_EPROGMISMATCH:
    return "SCE_NET_ERROR_EPROGMISMATCH";
  case SCE_NET_ERROR_EPROGUNAVAIL:
    return "SCE_NET_ERROR_EPROGUNAVAIL";
  case SCE_NET_ERROR_ERPCMISMATCH:
    return "SCE_NET_ERROR_ERPCMISMATCH";
  case SCE_NET_ERROR_EBADRPC:
    return "SCE_NET_ERROR_EBADRPC";
  case SCE_NET_ERROR_EREMOTE:
    return "SCE_NET_ERROR_EREMOTE";
  case SCE_NET_ERROR_ESTALE:
    return "SCE_NET_ERROR_ESTALE";
  case SCE_NET_ERROR_EDQUOT:
    return "SCE_NET_ERROR_EDQUOT";
  case SCE_NET_ERROR_EUSERS:
    return "SCE_NET_ERROR_EUSERS";
  case SCE_NET_ERROR_EPROCLIM:
    return "SCE_NET_ERROR_EPROCLIM";
  case SCE_NET_ERROR_ENOTEMPTY:
    return "SCE_NET_ERROR_ENOTEMPTY";
  case SCE_NET_ERROR_EHOSTUNREACH:
    return "SCE_NET_ERROR_EHOSTUNREACH";
  case SCE_NET_ERROR_EHOSTDOWN:
    return "SCE_NET_ERROR_EHOSTDOWN";
  case SCE_NET_ERROR_ENAMETOOLONG:
    return "SCE_NET_ERROR_ENAMETOOLONG";
  case SCE_NET_ERROR_ELOOP:
    return "SCE_NET_ERROR_ELOOP";
  case SCE_NET_ERROR_ECONNREFUSED:
    return "SCE_NET_ERROR_ECONNREFUSED";
  case SCE_NET_ERROR_ETIMEDOUT:
    return "SCE_NET_ERROR_ETIMEDOUT";
  case SCE_NET_ERROR_ETOOMANYREFS:
    return "SCE_NET_ERROR_ETOOMANYREFS";
  case SCE_NET_ERROR_ESHUTDOWN:
    return "SCE_NET_ERROR_ESHUTDOWN";
  case SCE_NET_ERROR_ENOTCONN:
    return "SCE_NET_ERROR_ENOTCONN";
  case SCE_NET_ERROR_EISCONN:
    return "SCE_NET_ERROR_EISCONN";
  case SCE_NET_ERROR_ENOBUFS:
    return "SCE_NET_ERROR_ENOBUFS";
  case SCE_NET_ERROR_ECONNRESET:
    return "SCE_NET_ERROR_ECONNRESET";
  case SCE_NET_ERROR_ECONNABORTED:
    return "SCE_NET_ERROR_ECONNABORTED";
  case SCE_NET_ERROR_ENETRESET:
    return "SCE_NET_ERROR_ENETRESET";
  case SCE_NET_ERROR_ENETUNREACH:
    return "SCE_NET_ERROR_ENETUNREACH";
  case SCE_NET_ERROR_ENETDOWN:
    return "SCE_NET_ERROR_ENETDOWN";
  case SCE_NET_ERROR_EADDRNOTAVAIL:
    return "SCE_NET_ERROR_EADDRNOTAVAIL";
  case SCE_NET_ERROR_EADDRINUSE:
    return "SCE_NET_ERROR_EADDRINUSE";
  case SCE_NET_ERROR_EAFNOSUPPORT:
    return "SCE_NET_ERROR_EAFNOSUPPORT";
  case SCE_NET_ERROR_EPFNOSUPPORT:
    return "SCE_NET_ERROR_EPFNOSUPPORT";
  case SCE_NET_ERROR_EOPNOTSUPP:
    return "SCE_NET_ERROR_EOPNOTSUPP";
  case SCE_NET_ERROR_ESOCKTNOSUPPORT:
    return "SCE_NET_ERROR_ESOCKTNOSUPPORT";
  case SCE_NET_ERROR_EPROTONOSUPPORT:
    return "SCE_NET_ERROR_EPROTONOSUPPORT";
  case SCE_NET_ERROR_ENOPROTOOPT:
    return "SCE_NET_ERROR_ENOPROTOOPT";
  case SCE_NET_ERROR_EPROTOTYPE:
    return "SCE_NET_ERROR_EPROTOTYPE";
  case SCE_NET_ERROR_EMSGSIZE:
    return "SCE_NET_ERROR_EMSGSIZE";
  case SCE_NET_ERROR_EDESTADDRREQ:
    return "SCE_NET_ERROR_EDESTADDRREQ";
  case SCE_NET_ERROR_ENOTSOCK:
    return "SCE_NET_ERROR_ENOTSOCK";
  case SCE_NET_ERROR_EALREADY:
    return "SCE_NET_ERROR_EALREADY";
  case SCE_NET_ERROR_EINPROGRESS:
    return "SCE_NET_ERROR_EINPROGRESS";
  case SCE_NET_ERROR_EWOULDBLOCK:
    return "SCE_NET_ERROR_EWOULDBLOCK";
  case SCE_NET_ERROR_ERANGE:
    return "SCE_NET_ERROR_ERANGE";
  case SCE_NET_ERROR_EDOM:
    return "SCE_NET_ERROR_EDOM";
  case SCE_NET_ERROR_EPIPE:
    return "SCE_NET_ERROR_EPIPE";
  case SCE_NET_ERROR_EMLINK:
    return "SCE_NET_ERROR_EMLINK";
  case SCE_NET_ERROR_EROFS:
    return "SCE_NET_ERROR_EROFS";
  case SCE_NET_ERROR_ESPIPE:
    return "SCE_NET_ERROR_ESPIPE";
  case SCE_NET_ERROR_ENOSPC:
    return "SCE_NET_ERROR_ENOSPC";
  case SCE_NET_ERROR_EFBIG:
    return "SCE_NET_ERROR_EFBIG";
  case SCE_NET_ERROR_ETXTBSY:
    return "SCE_NET_ERROR_ETXTBSY";
  case SCE_NET_ERROR_ENOTTY:
    return "SCE_NET_ERROR_ENOTTY";
  case SCE_NET_ERROR_EMFILE:
    return "SCE_NET_ERROR_EMFILE";
  case SCE_NET_ERROR_ENFILE:
    return "SCE_NET_ERROR_ENFILE";
  case SCE_NET_ERROR_EINVAL:
    return "SCE_NET_ERROR_EINVAL";
  case SCE_NET_ERROR_EISDIR:
    return "SCE_NET_ERROR_EISDIR";
  case SCE_NET_ERROR_ENOTDIR:
    return "SCE_NET_ERROR_ENOTDIR";
  case SCE_NET_ERROR_ENODEV:
    return "SCE_NET_ERROR_ENODEV";
  case SCE_NET_ERROR_EXDEV:
    return "SCE_NET_ERROR_EXDEV";
  case SCE_NET_ERROR_EEXIST:
    return "SCE_NET_ERROR_EEXIST";
  case SCE_NET_ERROR_EBUSY:
    return "SCE_NET_ERROR_EBUSY";
  case SCE_NET_ERROR_ENOTBLK:
    return "SCE_NET_ERROR_ENOTBLK";
  case SCE_NET_ERROR_EFAULT:
    return "SCE_NET_ERROR_EFAULT";
  case SCE_NET_ERROR_EACCES:
    return "SCE_NET_ERROR_EACCES";
  case SCE_NET_ERROR_ENOMEM:
    return "SCE_NET_ERROR_ENOMEM";
  case SCE_NET_ERROR_EDEADLK:
    return "SCE_NET_ERROR_EDEADLK";
  case SCE_NET_ERROR_ECHILD:
    return "SCE_NET_ERROR_ECHILD";
  case SCE_NET_ERROR_EBADF:
    return "SCE_NET_ERROR_EBADF";
  case SCE_NET_ERROR_ENOEXEC:
    return "SCE_NET_ERROR_ENOEXEC";
  case SCE_NET_ERROR_E2BIG:
    return "SCE_NET_ERROR_E2BIG";
  case SCE_NET_ERROR_ENXIO:
    return "SCE_NET_ERROR_ENXIO";
  case SCE_NET_ERROR_EIO:
    return "SCE_NET_ERROR_EIO";
  case SCE_NET_ERROR_EINTR:
    return "SCE_NET_ERROR_EINTR";
  case SCE_NET_ERROR_ESRCH:
    return "SCE_NET_ERROR_ESRCH";
  case SCE_NET_ERROR_ENOENT:
    return "SCE_NET_ERROR_ENOENT";
  case SCE_NET_ERROR_EPERM:
    return "SCE_NET_ERROR_EPERM";
  }

  return "";
}

namespace net {
class NetException : public std::exception {
  constexpr static size_t max_error_msg_size = 256;

public:
  NetException(int error_code) : error_code_(error_code) {
    snprintf(msg_, max_error_msg_size, "network error occured: %s (%d)",
             sce_net_strerror((unsigned)error_code_), error_code_);
  }
  const char *what() const noexcept override { return msg_; }
  int error_code() const noexcept { return error_code_; }

private:
  int error_code_;
  char msg_[max_error_msg_size];
};

} // namespace net

int net_thread(unsigned int arglen, void *argp);

#endif // NET_HPP
