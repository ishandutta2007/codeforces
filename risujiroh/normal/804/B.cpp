#include <bits/stdc++.h>
using namespace std;

char readchar() {
  static char buf[1 << 15], *ptr = buf, *end = buf;
  if (ptr == end) ptr = buf, end = buf + fread(buf, 1, 1 << 15, stdin);
  return *ptr++;
}
void writechar(char c = 0) {
  static char buf[1 << 15], *ptr = buf;
  if (ptr == end(buf) or c == 0) fwrite(buf, 1, ptr - buf, stdout), ptr = buf;
  *ptr++ = c;
}
template <class Z = int> Z getint() {
  char c = readchar();
  bool neg = c == '-';
  Z res = neg ? 0 : c - '0';
  while (isdigit(c = readchar())) res = res * 10 + (c - '0');
  return neg ? -res : res;
}
template <class Z> void putint(Z a, char delim = '\n') {
  if (a < 0) writechar('-'), a = -a;
  int d[40], i = 0;
  do d[i++] = a % 10; while (a /= 10);
  while (i--) writechar('0' + d[i]);
  writechar(delim);
}
string getstring(char delim = '\n') {
  string res;
  for (char c; (c = readchar()) != delim; ) res += c;
  return res;
}
void putstring(string s, char delim = '\n') {
  for (char c : s) writechar(c);
  writechar(delim);
}

template <unsigned M> struct modular {
  using m = modular;
  unsigned v;
  modular(long long x = 0) : v((x %= M) < 0 ? x + M : x) {}
  m operator-() const { return m() -= *this; }
  m& operator+=(m b) { if ((v += b.v) >= M) v -= M; return *this; }
  m& operator-=(m b) { if (v < b.v) v += M; v -= b.v; return *this; }
  m& operator*=(m b) {
    auto x = (uint64_t)v * b.v;
    unsigned xu = x >> 32, xl = x, d;
    asm("divl %4; \n\t" : "=a" (d), "=d" (v) : "d" (xu), "a" (xl), "r" (M));
    return *this;
  }
  m& operator/=(m b) { return *this *= power(b, M - 2); }
  friend m operator+(m a, m b) { return a += b; }
  friend m operator-(m a, m b) { return a -= b; }
  friend m operator*(m a, m b) { return a *= b; }
  friend m operator/(m a, m b) { return a /= b; }
  friend bool operator==(m a, m b) { return a.v == b.v; }
  friend string to_string(m a) { return to_string(a.v); }
};

constexpr long long mod = 1e9 + 7;
using mint = modular<mod>;

int main() {
  auto s = getstring();
  reverse(begin(s), end(s));
  mint res, cur;
  for (char c : s) {
    if (c == 'a') {
      res += cur;
      cur *= 2;
    } else {
      cur += 1;
    }
  }
  putint(res.v);
  writechar();
}