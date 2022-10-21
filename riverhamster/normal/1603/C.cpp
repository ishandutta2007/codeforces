#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
#include <map>
using namespace std;

#define LOG(f...) fprintf(stderr, f)
#define DBG(f...) printf("%3d: ", __LINE__), printf(f)
// #define DBG(f...) void()
#define all(cont) begin(cont), end(cont)
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif

using ll = long long;

template <class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while(isdigit(ch = getchar()));
  x *= f;
}
template <class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

const int N = 100005;
const int M = 998244353;

void reduceR(int &x) { x += M & (x >> 31); }
int reduceN(int x) { return x + (M & (x >> 31)); }
int add(int x, int y) { return reduceN(x + y - M); }
int sub(int x, int y) { return reduceN(x - y); }
void inc(int &x, int y) { reduceR(x += y - M); }
void dec(int &x, int y) { reduceR(x -= y); }
int power(int x, int y) {
  int p = 1;
  for (; y; y >>= 1, x = (ll)x * x % M)
    if (y & 1) p = (ll)p * x % M;
  return p;
}
int inv(int x) { return power(x, M - 2); }

int a[N];
struct pr { int c, s; };
// map<int, pr> dp, tp;
vector<pair<int, pr>> dp, tp;

int Div(int x, int y) { return (x + y - 1) / y; }

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int T;
  read(T);
  while (T--) {
    int n;
    read(n);
    for (int i = 1; i <= n; ++i)
      read(a[i]);
    dp.clear();
    int res = 0;
    for (int i = n; i >= 1; --i) {
      auto it = upper_bound(all(dp), a[i], [](int a, const pair<int, pr> &b) { return a < b.first; });
      pr s = {1, 0};
      for (auto p = it; p != dp.end(); ++p) {
        inc(s.c, p->second.c);
        inc(s.s, p->second.s);
      }
      dp.erase(it, dp.end());
      if (dp.empty() || dp.back().first != a[i])
        dp.emplace_back(a[i], pr{0, 0});
      inc(dp.back().second.c, s.c);
      inc(dp.back().second.s, s.s);
      tp.clear();
      tp.reserve(640);
      for (auto [j, p] : dp) {
        int c = Div(a[i], j);
        int nj = a[i] / c;
        assert(nj);
        int V = ((ll)c * p.c + p.s) % M;
        if (tp.empty() || tp.back().first != nj)
          tp.emplace_back(nj, pr{p.c, V});
        else {
          inc(tp.back().second.c, p.c);
          inc(tp.back().second.s, V);
        }
        inc(res, V);
      }
      dp = move(tp);
    }
    for (int i = 1; i <= n; ++i)
      res = (res - (ll)i * (n - i + 1)) % M;
    res = (res + M) % M;
    printf("%d\n", res);
  }
  return 0;
}