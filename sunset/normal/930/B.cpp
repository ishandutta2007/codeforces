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

const int N = 5005;

vector <int> p[N];
int n, ans, c[N];
char s[N << 1];

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  scanf("%s", s), n = strlen(s);
  for (int i = 0; i < n; ++i) {
    p[s[i] - 'a'].pb(i), s[i + n] = s[i];
  }
  for (int i = 0; i < 26; ++i) {
    int val = 0;
    for (int j = 0; j < n; ++j) {
      int ret = 0;
      for (int k = 0; k < 26; ++k) {
        c[k] = 0;
      }
      for (auto x : p[i]) {
        ++c[s[j + x] - 'a'];
      }
      for (int k = 0; k < 26; ++k) {
        if (c[k] == 1) {
          ++ret;
        }
      }
      CheckMax(val, ret);
    }
    ans += val;
  }
  printf("%lf\n", (double)ans / n);
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}