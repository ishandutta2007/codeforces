#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define Debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long LL;
typedef long double LD;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef unsigned long long uLL;

template <typename T> inline void Read(T &x) {
  char c = getchar();
  bool f = false;
  for (x = 0; !isdigit(c); c = getchar()) {
    if (c == '-') {
      f = true;
    }
  }
  for (; isdigit(c); c = getchar()) {
    x = x * 10 + c - '0';
  }
  if (f) {
    x = -x;
  }
}

template <typename T> inline bool CheckMax(T &a, const T &b) {
  return a < b ? a = b, true : false;
}

template <typename T> inline bool CheckMin(T &a, const T &b) {
  return a > b ? a = b, true : false;
}

const int N = 60;

vector <LL> ans, a[N];
int n;

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n);
  for (int i = 0, j; i < n; ++i) {
    LL x;
    Read(x);
    for (j = N - 1; ~j; --j) {
      if (x >> j & 1) {
        a[j].pb(x);
        break;
      }
    }
  }
  for (int i = N - 1; ~i; --i) {
    if (!a[i].empty()) {
      vector <LL> nxt;
      int cur = 0;
      nxt.pb(a[i][cur++]);
      for (auto x : ans) {
        nxt.pb(x);
        if ((x >> i & 1) && cur < a[i].size()) {
          nxt.pb(a[i][cur++]);
        }
      }
      if (cur < a[i].size()) {
        puts("No");
        return 0;
      }
      ans = nxt;
    }
  }
  puts("Yes");
  for (int i = 0; i < n; ++i) {
    printf("%lld%c", ans[i], i == n - 1 ? '\n' : ' ');
  }
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}