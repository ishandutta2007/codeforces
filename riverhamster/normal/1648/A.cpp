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

map<int, vector<int>> dx, dy;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, m;
  read(n, m);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      int c; read(c);
      dx[c].push_back(i); dy[c].push_back(j);
    }
  ll ans = 0;
  for (auto p : {dx, dy}) {
    // puts("===");
    for (auto q : p) {
      // printf("q.first = %d\n", q.first);
      ll c = 0, s = 0;
      sort(all(q.second));
      for (int x : q.second) {
        ans += c * x - s;
        // printf("x = %d s = %lld\n", x, s);
        s += x; ++c;
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}