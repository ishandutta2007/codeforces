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

const int N = 300005;

vector <int> g, r[N], b[N];
int n, m, ans;
char opt[2];

inline int Solve(int lef, int rig, const vector <int> &r, const vector <int> &b) {
  if (!~lef && !~rig) {
    return (!r.empty() ? r.back() - r[0] : 0) + (!b.empty() ? b.back() - b[0] : 0);
  } else if (!~lef) {
    return (!r.empty() ? rig - r[0] : 0) + (!b.empty() ? rig - b[0] : 0);
  } else if (!~rig) {
    return (!r.empty() ? r.back() - lef : 0) + (!b.empty() ? b.back() - lef : 0);
  } else {
    int x, y;
    if (r.empty()) {
      x = rig - lef;
    } else {
      x = max(r[0] - lef, rig - r.back());
      for (int i = 1; i < r.size(); ++i) {
        CheckMax(x, r[i] - r[i - 1]);
      }
    }
    if (b.empty()) {
      y = rig - lef;
    } else {
      y = max(b[0] - lef, rig - b.back());
      for (int i = 1; i < b.size(); ++i) {
        CheckMax(y, b[i] - b[i - 1]);
      }
    }
    return min(rig - lef << 1, (rig - lef) * 3 - x - y);
  }
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n);
  for (int i = 1, x; i <= n; ++i) {
    Read(x), scanf("%s", opt);
    if (opt[0] == 'G') {
      g.pb(x), ++m;
    } else if (opt[0] == 'R') {
      r[m].pb(x);
    } else {
      b[m].pb(x);
    }
  }
  for (int i = 0; i <= m; ++i) {
    ans += Solve(i ? g[i - 1] : -1, i < m ? g[i] : -1, r[i], b[i]);
  }
  printf("%d\n", ans);
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}