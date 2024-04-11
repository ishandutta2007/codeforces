#line 2 "lib/prelude.hpp"

#ifndef LOCAL
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")
#define NDEBUG
#endif

#include <bits/stdc++.h>
using namespace std;

using uint = unsigned;
using ll = long long;
using ull = unsigned long long;
template <class T> using vec = vector<T>;
#line 3 "lib/io.hpp"

namespace io_detail {

constexpr int SZ = 1 << 25;
char in[SZ], out[SZ], *s, *t;

struct Pre {
  char num[40000];
  constexpr Pre() : num() {
    for (int i = 0; i < 10000; i++) {
      for (int n = i, j = 4; j--;) num[i * 4 + j] = n % 10 + '0', n /= 10;
    }
  }
} constexpr pre;

void read(char& x) {
  while (*s <= ' ') s++;
  x = *s++;
}
void read(char *str) {
  while (*s <= ' ') s++;
  char *s0 = s; while (*s > ' ') s++;
  memcpy(str, s0, s - s0); str[s - s0] = 0;
}
template <class T> enable_if_t<is_integral_v<T>, void> read(T& x) {
  bool neg = false; while (*s <= ' ') s++;
  if constexpr (is_signed_v<T>) neg = *s == '-' ? s++, true : false;
  x = 0; while (*s > ' ') x = x * 10 + (*s++ & 0x0F);
  if constexpr (is_signed_v<T>) { if (neg) x = -x; }
}
template <class T> auto read(T& v) -> decltype(v.val(), void()) { uint x; read(x); v = x; }
void read(vector<char>& v) {
  while (*s <= ' ') s++;
  char *s0 = s; while (*s > ' ') s++;
  v.assign(s0, s);
}
template <class T, size_t... I> void read_tuple(T& v, index_sequence<I...>) { (read(get<I>(v)), ...); }
template <class T> auto read(T& v) -> decltype(tuple_size<T>::value, void()) {
  read_tuple(v, make_index_sequence<tuple_size_v<T>>());
}
template <class T, int N> void read(array<T, N>& v) { for (auto& e : v) read(e); }
template <class T> auto read(T& v) -> decltype(begin(v), void()) { for (auto& e : v) read(e); }
template <class T, class T2, class... Rest>
void read(T& x, T2& y, Rest& ... rest) { read(x); read(y, rest...); }
void write(char x) { *t++ = x; }
template <class T> enable_if_t<is_integral_v<T>, void> write(T x) {
  if (!x) { *t++ = '0'; return; }
  if constexpr (is_signed_v<T>) { if (x < 0) *t++ = '-', x = -x; }
  int i = 12; static char buf[16];
  while (x >= 10000) {
    memcpy(buf + i, pre.num + (x % 10000) * 4, 4); x /= 10000; i -= 4;
  }
  if (x < 100) {
    if (x < 10) *t++ = '0' + x;
    else {
      uint32_t q = (uint32_t(x) * 205) >> 11, r = uint32_t(x) - q * 10;
      *t++ = '0' + q, *t++ = '0' + r;
    }
  } else {
    if (x < 1000) memcpy(t, pre.num + (x << 2) + 1, 3), t += 3;
    else memcpy(t, pre.num + (x << 2), 4), t += 4;
  }
  memcpy(t, buf + i + 4, 12 - i); t += 12 - i;
}
template <class T> auto write(T x) -> decltype(x.val(), void()) { write(x.val()); }
void write(const string& str) { memcpy(t, str.c_str(), str.size()), t += str.size(); }
void write(const vector<char>& str) { memcpy(t, &*str.begin(), str.size()), t += str.size(); }
void write(const char* str) { int len = strlen(str); memcpy(t, str, len), t += len; }
template <class T, size_t I, size_t... Is>
void write_tuple(const T& v, index_sequence<I, Is...>) {
  write(get<I>(v)); (void)(int []){ (write(' '), write(get<Is>(v)), 0)... };
}
template <class T>
auto write(const T& v) -> decltype(tuple_size<T>::value, void()) {
  write_tuple(v, make_index_sequence<tuple_size_v<T>>{});
}
template <class T> void prtln(T x) { write(x); write('\n'); }
template <class T, class... Rest>
void prtln(T x, Rest... rest) { write(x), write(' '), prtln(rest...); }
template <class T, enable_if_t<!is_same_v<T, char>>* = nullptr>
void prtln(const vector<T>& v, char sep = ' ') {
  for (auto&& e : v) write(e), write(sep);
  *(t - 1) = '\n';
}

class IO {
 public:
  IO() { s = in, t = out, in[fread(in, 1, sizeof(in), stdin)] = 0; }
  ~IO() { fwrite(out, 1, t - out, stdout); }
} io_dummy;

}  // namespace io_detail

using io_detail::prtln;
using io_detail::read;
using io_detail::write;
#line 3 "main.cpp"

int main() {
  int n, q; read(n, q);
  vec<int> a(n); read(a);
  vec<int> pos(100001, -1);
  vec<int> lpf(100001, INT_MAX);
  for (int i = 2; i < lpf.size(); i++) {
    if (lpf[i] == INT_MAX) {
      for (int j = i; j < lpf.size(); j += i)
        lpf[j] = min(lpf[j], i);
    }
  }
  vector nxt(18, vector(n + 1, n));
  for (int i = 0; i < n; i++) {
    for (int d = 1; d <= 1000; d++) {
      if (a[i] % d == 0) {
        for (auto d2 : {d, a[i] / d}) if (d2 != 1 && pos[d2] != i) {
          if (pos[d2] != -1)
            nxt[0][pos[d2]] = min(nxt[0][pos[d2]], i);
          pos[d2] = i;
        }
      }
    }
  }
  // fill(pos.begin(), pos.end(), -1);
  // for (int i = 0; i < n; i++) {
  //   while (a[i] > 1) {
  //     int d = lpf[a[i]];
  //     if (pos[d] != -1) nxt[0][pos[d]] = min(nxt[0][pos[d]], i);
  //     pos[d] = i;
  //     while (a[i] % d == 0) a[i] /= d;
  //   }
  // }
  for (int i = n - 1; i--;)
    nxt[0][i] = min(nxt[0][i], nxt[0][i + 1]);
  for (int s = 0; s < 17; s++)
    for (int i = 0; i < n; i++)
      nxt[s + 1][i] = nxt[s][nxt[s][i]];
  for (int t = 0; t < q; t++) {
    int l, r; read(l, r); --l;
    int ans = 0;
    for (int t = 18; t--;)
      if (nxt[t][l] < r) {
        ans += (1 << t);
        l = nxt[t][l];
      }
    prtln(ans + 1);
  }
}