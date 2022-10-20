#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
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

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, d;
  read(n, d);
  vector<pair<int, int>> a(n);
  for (auto &[x, y] : a)
    read(x, y);
  auto p = partition(all(a), [&](const pair<int, int> &a) { return a.second <= d; });
  sort(p, a.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
    if (max(a.first, a.second) == max(b.first, b.second))
      return a.first < b.first;
    return max(a.first, a.second) < max(b.first, b.second);
  });
  int ans = 0;
  for (auto [x, y] : a) {
    if (x >= d) {
      ++ans;
      d = max(d, y);
    }
  }
  printf("%d\n", ans);
  return 0;
}