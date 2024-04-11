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

bitset <N> one, tmp, pos[26];
char s[N], t[N];
int n, m;

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  scanf("%s", s), n = strlen(s), one.set();
  for (int i = 0; i < n; ++i) {
    pos[s[i] - 'a'][i] = true;
  }
  Read(m);
  while (m--) {
    int opt, x, y, len;
    Read(opt);
    if (opt == 1) {
      Read(x), scanf("%s", t);
      --x, pos[s[x] - 'a'][x] = false, s[x] = t[0], pos[s[x] - 'a'][x] = true;
    } else {
      Read(x), Read(y), scanf("%s", t), len = strlen(t), --x, --y;
      tmp = one >> N - y + len - 2 & one << x;
      for (int i = 0; i < len; ++i) {
        tmp &= pos[t[i] - 'a'] >> i;
      }
      printf("%d\n", tmp.count());
    }
  }
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}