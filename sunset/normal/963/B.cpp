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

int n, h, r, t, d[N], p[N], ans[N];
vector <int> seq, adj[N];

inline void DFS(int x) {
  seq.pb(x);
  for (auto y : adj[x]) {
    DFS(y);
  }
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n), t = n + 1;
  if (!(n & 1)) {
    puts("NO");
    return 0;
  }
  puts("YES");
  for (int i = 1; i <= n; ++i) {
    Read(p[i]);
    if (p[i]) {
      adj[p[i]].pb(i), ++d[i], ++d[p[i]];
    } else {
      r = i;
    }
  }
  DFS(r);
  reverse(seq.begin(), seq.end());
  for (auto x : seq) {
    if (d[x] & 1) {
      ans[--t] = x;
    } else {
      ans[++h] = x, --d[p[x]];
    }
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d\n", ans[i]);
  }
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}