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

const int N = 100005;
const int inf = 0x3f3f3f3f;

bitset <N> cur, pos[26];
char s[N];
int n, m;

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  scanf("%s", s), n = strlen(s), Read(m);
  for (int i = 0; i < n; ++i) {
    pos[s[i] - 'a'][i] = true;
  }
  for (int i = 0, k; i < m; ++i) {
    vector <int> all;
    Read(k), --k, scanf("%s", s), cur.set();
    int ans = inf, len = strlen(s);
    for (int j = 0; j < len; ++j) {
      cur &= pos[s[j] - 'a'] >> j;
    }
    for (int j = cur._Find_first(); j < n; all.pb(j), j = cur._Find_next(j));
    for (int j = 0; j + k < all.size(); ++j) {
      CheckMin(ans, all[j + k] - all[j] + len);
    }
    if (ans == inf) {
      ans = -1;
    }
    printf("%d\n", ans);
  }
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}