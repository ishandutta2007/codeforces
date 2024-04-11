#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
#include <random>
#include <chrono>
using namespace std;

#define LOG(f...) fprintf(stderr, f)

using ll = long long;

template<class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while(isdigit(ch = getchar()));
  x *= f;
}
template<class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

const int N = 200005, V = 5000005;
pair<int, int> a[N], b[N];
pair<int, int> last[V][4];
int lc[V];

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  read(n);
  for (int i = 1; i <= n; ++i)
    read(b[i].first), b[i].second = i;
  sort(b + 1, b + 1 + n);
  for (int i = 4; i <= n; ++i)
    if (b[i].first == b[i - 1].first && b[i].first == b[i - 2].first && b[i].first == b[i - 3].first) {
      printf("YES\n%d %d %d %d\n", b[i].second, b[i - 1].second, b[i - 2].second, b[i - 3].second);
      return 0;
    }
  a[1] = b[1]; a[2] = b[2];
  int ac = 2;
  for (int i = 3; i <= n; ++i) {
    if (b[i].first != b[i - 2].first)
      a[++ac] = b[i];
  }
  ac = min(ac, 3500);
  for (int i = 1; i <= ac; ++i) {
    for (int j = i + 1; j <= ac; ++j) {
      int sum = a[i].first + a[j].first;
      for (int k = 0; k < lc[sum]; ++k)
        if (last[sum][k].first != a[i].second && last[sum][k].first != a[j].second && last[sum][k].second != a[i].second && last[sum][k].second != a[j].second) {
          printf("YES\n%d %d %d %d\n", last[sum][k].first, last[sum][k].second, a[i].second, a[j].second);
          return 0;
        }
      last[sum][lc[sum]++] = {a[i].second, a[j].second};
    }
  }
  puts("NO");
  return 0;
}