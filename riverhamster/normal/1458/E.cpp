#include <cstdio>
#include <cctype>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
using ll = long long;

const int INF = 2000000000;

namespace io {
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
  const int SIZE = (1 << 21) + 1;
  char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1;
  inline char getc () {return (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++);}
  inline void flush () {fwrite (obuf, 1, oS - obuf, stdout); oS = obuf;}
  inline void putc (char x) {*oS ++ = x; if (oS == oT) flush ();}
  template<class T>
  inline void read(T &x) {
    char ch; int f = 1;
    x = 0;
    while(isspace(ch = getc()));
    if(ch == '-') ch = getc(), f = -1;
    do x = x * 10 + ch - '0'; while(isdigit(ch = getc()));
    x *= f;
  }
  template<class T, class ...Args>
  inline void read(T &x, Args&... args) {read(x); read(args...);}
  template<class T>
  inline void write(T x) {
    static char stk[128];
    int top = 0;
    if(x == 0) {putc('0'); return;}
    if(x < 0) putc('-'), x = -x;
    while(x) stk[top++] = x % 10, x /= 10;
    while(top) putc(stk[--top] + '0');
  }
  template<class T, class ...Args>
  inline void write(T x, Args... args) {write(x); putc(' '); write(args...);}
  inline void space() {putc(' ');}
  inline void endl() {putc('\n');}
  struct _flush {~_flush() {flush();}} __flush;
};
using io::read; using io::write; using io::flush; using io::space; using io::endl; using io::getc; using io::putc;

#define all(A) A.begin(), A.end()
#define LOG(f...) fprintf(stderr, f)

vector<int> dx, dy;
vector<int> xp[100005], yp[100005];
vector<pair<int, int>> lose;
vector<tuple<int, int, int>> segment; // xr, xl, yl

int main() {
  int n, m;
  read(n, m);
  for (int i = 1; i <= n; ++i) {
    int x, y;
    read(x, y);
    lose.emplace_back(x, y);
    dx.push_back(x); dy.push_back(y);
  }
  sort(all(dx));; dx.erase(unique(all(dx)), dx.end());
  sort(all(dy)); dy.erase(unique(all(dy)), dy.end());
  sort(all(lose));
  dx.push_back(INF); dy.push_back(INF);
  for (auto [x, y] : lose) {
    int idx = lower_bound(all(dx), x) - dx.begin();
    int idy = lower_bound(all(dy), y) - dy.begin();
    xp[idx].push_back(y); yp[idy].push_back(x);
  }
  for (size_t i = 0; i < dx.size(); ++i) sort(all(xp[i]));
  for (size_t i = 0; i < dy.size(); ++i) sort(all(yp[i]));
  
  int x = 0, y = 0;
  while (true) {
    if (binary_search(all(lose), make_pair(x, y))) {
      ++x; ++y;
      continue;
    }
    auto itx = lower_bound(all(dx), x);
    auto ity = lower_bound(all(dy), y);
    if (*itx == INF && *ity == INF) {
      segment.emplace_back(INF, x, y);
      break;
    }
    if (*itx == x) {
      int id = itx - dx.begin();
      if (upper_bound(all(xp[id]), y) != begin(xp[id])) { ++x; continue; }
      else ++itx;
    }
    if (*ity == y) {
      int id = ity - dy.begin();
      if (upper_bound(all(yp[id]), x) != begin(yp[id])) { ++y; continue; }
      else ++ity;
    }

    int d = min(*itx - x, *ity - y);
    segment.emplace_back(x - 1 + d, x, y);
    x += d; y += d;
  }

  while (m--) {
    int x, y;
    read(x, y);
    if (binary_search(all(lose), make_pair(x, y))) puts("LOSE");
    else {
      auto it = lower_bound(all(segment), make_tuple(x, 0, 0));
      int x0, y0;
      if (it != segment.end()) {
        tie(ignore, x0, y0) = *it;
        if (x0 <= x && x0 - y0 == x - y) puts("LOSE");
        else puts("WIN");
      }
      else puts("WIN");
    }
  }
  return 0;
}