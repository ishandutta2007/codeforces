#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
#include <map>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define LOG(f...) fprintf(stderr, f)
#define DBG(f...) printf("%3d: ", __LINE__), printf(f)
// #define DBG(f...) void()
#define all(cont) begin(cont), end(cont)
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif

template <class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while(isdigit(ch = getchar()));
  x *= f;
}
template <class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

const ll MIN = -3e18;

map<ll, ll> s;

void update(ll p, ll v) {
  auto it = s.lower_bound(p);
  if (it == s.end() || it->first != p)
    it = s.emplace_hint(it, p, MIN);
  it->second = max(it->second, v);
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  ll x;
  read(n);
  read(x);
  s.emplace(x, 0);
  for (int i = 1; i < n; ++i) {
    read(x);
    ll mx = MIN;
    auto lb = s.upper_bound(x);
    for (auto it = lb; it != s.end(); ++it) {
      lldiv_t d = lldiv(it->first, x);
      mx = max(mx, (d.quot - 1) * i * x + it->second);
      if (d.rem)
        update(d.rem, d.quot * i * x + it->second);
    }
    s.erase(lb, s.end());
    if (mx != MIN)
      update(x, mx);
  }
  ll ans = 0;
  for (auto p : s)
    ans = max(ans, n * (p.first - 1) + p.second);
  printf("%lld\n", ans);
  return 0;
}