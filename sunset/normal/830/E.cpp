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

vector <int> seq, tmp[3], adj[N];
int n, m, v, e, c[3], ans[N];
bool vis[N];

inline void DFS(int x) {
  seq.pb(x), ++v, e += adj[x].size(), vis[x] = true;
  for (auto y : adj[x]) {
    if (!vis[y]) {
      DFS(y);
    }
  }
}

inline void DFS(int x, int p, int t) {
  tmp[t].pb(x);
  for (auto y : adj[x]) {
    if (y != p) {
      DFS(y, x, t);
    }
  }
}

inline int LCM(int x, int y) {
  return x * y / __gcd(x, y);
}

int Main() {
  Read(n), Read(m);
  for (int i = 1; i <= n; ++i) {
    ans[i] = 0, vis[i] = false, adj[i].clear();
  }
  for (int i = 1, x, y; i <= m; ++i) {
    Read(x), Read(y);
    adj[x].pb(y), adj[y].pb(x);
  }
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      v = e = 0, seq.clear(), DFS(i), e >>= 1;
      if (e >= v) {
        for (auto x : seq) {
          ans[x] = 1;
        }
        puts("YES");
        for (int j = 1; j <= n; ++j) {
          printf("%d%c", ans[j], j == n ? '\n' : ' ');
        }
        return 0;
      }
      int cnt = 0;
      for (auto x : seq) {
        if (adj[x].size() == 1) {
          ++cnt;
        }
      }
      if (cnt >= 4) {
        for (auto x : seq) {
          if (adj[x].size() == 1) {
            ans[x] = 1;
          } else {
            ans[x] = 2;
          }
        }
        puts("YES");
        for (int j = 1; j <= n; ++j) {
          printf("%d%c", ans[j], j == n ? '\n' : ' ');
        }
        return 0;
      }
      if (cnt == 3) {
        int p = 0;
        for (auto x : seq) {
          if (adj[x].size() == 3) {
            p = x;
          }
        }
        for (int j = 0; j < adj[p].size(); ++j) {
          tmp[j].clear(), DFS(adj[p][j], p, j);
        }
        sort(tmp, tmp + 3, [&](const vector <int> &a, const vector <int> &b) {
          return a.size() < b.size();
        });
        for (int j = 0; j < 3; ++j) {
          c[j] = tmp[j].size() + 1;
        }
        if (c[0] >= 3) {
          c[0] = c[1] = c[2] = 3;
        } else if (c[1] == 2) {
          continue;
        } else if (c[1] == 3) {
          if (c[2] < 6) {
            continue;
          }
          c[2] = 6;
        } else {
          c[1] = c[2] = 4;
        }
        int all = LCM(c[0], LCM(c[1], c[2]));
        ans[p] = all;
        for (int j = 0; j < 3; ++j) {
          int t = all / c[j];
          for (int k = 0; k < tmp[j].size(); ++k) {
            ans[tmp[j][k]] = max(t, all - t * (k + 1));
          }
        }
        puts("YES");
        for (int j = 1; j <= n; ++j) {
          printf("%d%c", ans[j], j == n ? '\n' : ' ');
        }
        return 0;
      }
    }
  }
  puts("NO");
  return 0;
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  int T;
  for (Read(T); T; --T) {
    Main();
  }
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}