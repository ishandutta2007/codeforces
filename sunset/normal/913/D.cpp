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

const int N = 200005;

int n, m, a[N], t[N];
vector <pii> v;

inline bool Check(int x) {
  v.clear();
  for (int i = 1; i <= n; ++i) {
    if (a[i] >= x) {
      v.pb(mp(t[i], i));
    }
  }
  if (v.size() < x) {
    return false;
  }
  sort(v.begin(), v.end());
  LL sum = 0;
  for (int i = 0; i < x; ++i) {
    sum += v[i].X;
  }
  if (sum > m) {
    return false;
  } else {
    return true;
  }
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n), Read(m);
  for (int i = 1; i <= n; ++i) {
    Read(a[i]), Read(t[i]);
  }
  int l = 1, r = n, ret = 0;
  while (l <= r) {
    int mid = l + r >> 1;
    if (Check(mid)) {
      ret = mid, l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  printf("%d\n%d\n", ret, ret);
  if (!ret) {
    putchar(10);
  } else {
    Check(ret);
    for (int i = 0; i < ret; ++i) {
      printf("%d%c", v[i].Y, i == ret - 1 ? '\n' : ' ');
    }
  }
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}