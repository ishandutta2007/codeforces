#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
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

const int N = 5005;

int tag[N], s[N];
ll f[N], upd[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int T;
  read(T);
  while (T--) {
    int n;
    read(n);
    fill(f + 1, f + 1 + n, 0);
    fill(upd + 1, upd + 1 + n, 0);
    for (int i = 1; i <= n; ++i) read(tag[i]);
    for (int i = 1; i <= n; ++i) read(s[i]);
    for (int i = 2; i <= n; ++i) {
      for (int j = i - 1; j >= 1; --j)
        if (tag[i] != tag[j]) {
          f[i] = max(f[i], f[j] + abs(s[i] - s[j]));
          upd[j] = f[i];
        }
        else upd[j] = 0;
      ll mx = 0;
      for (int j = i; j > 1; --j) {
        mx = max(mx, upd[j]);
        if (tag[j - 1] != tag[i])
          f[j - 1] = max(f[j - 1], mx + abs(s[i] - s[j - 1]));
      }
    }
    printf("%lld\n", *max_element(f + 1, f + 1 + n));
  }
  return 0;
}