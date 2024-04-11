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

int n, ans;
string s;

inline bool Check(int l, int r) {
  if (l > r) {
    return true;
  }
  if (s[l] != s[r]) {
    return false;
  }
  return Check(l + 1, r - 1);
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  cin >> s;
  n = s.length();
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      if (!Check(i, j)) {
        CheckMax(ans, j - i + 1);
      }
    }
  }
  printf("%d\n", ans);
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}