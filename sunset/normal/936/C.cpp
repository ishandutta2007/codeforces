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

const int N = 2005;

vector <int> ans;
char s[N], t[N];
int n;

inline void Solve(int x) {
  reverse(s, s + n);
  reverse(s + x, s + n);
  ans.pb(x);
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n), scanf("%s%s", s, t);
  for (int i = n - 1, j; ~i; --i) {
    for (j = n - i - 1; j < n && t[i] != s[j]; ++j);
    if (j == n) {
      puts("-1");
      return 0;
    }
    Solve(n), Solve(j), Solve(1);
  }
  printf("%d\n", n * 3);
  for (int i = 0; i < n * 3; ++i) {
    printf("%d%c", ans[i], i == n * 3 - 1 ? '\n' : ' ');
  }
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}