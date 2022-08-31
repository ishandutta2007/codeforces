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

vector <int> lef, adj[N];
int n;

inline void DFS(int x, int p = 0) {
  bool f = false;
  for (auto y : adj[x]) {
    if (y != p) {
      DFS(y, x), f = true;
    }
  }
  if (!f) {
    lef.pb(x);
  }
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n);
  for (int i = 1, x, y; i < n; ++i) {
    Read(x), Read(y);
    adj[x].pb(y), adj[y].pb(x);
  }
  int r = 0;
  for (int i = 1; i <= n; ++i) {
    if (adj[i].size() > 2) {
      if (r) {
        puts("No");
        return 0;
      }
      r = i;
    }
  }
  if (!r) {
    r = 1;
  }
  DFS(r);
  puts("Yes");
  printf("%d\n", lef.size() + 1 >> 1);
  for (int i = 0; i + 1 < lef.size(); i += 2) {
    printf("%d %d\n", lef[i], lef[i + 1]);
  }
  if (lef.size() & 1) {
    printf("%d %d\n", r, lef.back());
  }
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}