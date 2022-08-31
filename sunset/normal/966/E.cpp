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
const int M = 512;

int n, m, tim, add[N], cnt[N], dfn[N], par[N], ptr[N], qry[N], seq[N], siz[N], val[N], vpr[N];
vector <int> adj[N], anc[N];
bool ont[N], vac[N];

inline void DFS(int x) {
  seq[dfn[x] = ++tim] = x;
  for (auto y : adj[x]) {
    DFS(y);
  }
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n), Read(m);
  for (int i = 2; i <= n; ++i) {
    Read(par[i]), adj[par[i]].pb(i);
  }
  DFS(1);
  for (int i = 1; i <= n; ++i) {
    Read(val[i]);
  }
  for (int i = 1; i <= m; ++i) {
    Read(qry[i]), qry[i] = abs(qry[i]);
  }
  for (int l = 1, r = min(M, m); l <= m; l = r + 1, r = min(r + M, m)) {
    int cur = 0;
    for (int i = 1; i <= n; ++i) {
      siz[i] = 0;
    }
    for (int i = n; i; --i) {
      int x = seq[i];
      if (vac[x]) {
        ++siz[x];
      } else if (siz[x] > val[x]) {
        ++cur;
      }
      siz[par[x]] += siz[x];
    }
    for (int i = 1; i <= n; ++i) {
      ont[i] = false, add[i] = cnt[i] = ptr[i] = 0, anc[i].clear();
    }
    for (int i = l; i <= r; ++i) {
      ont[qry[i]] = true;
    }
    for (int i = n; i; --i) {
      int x = seq[i];
      if (ont[x] || cnt[x]) {
        ++cnt[par[x]];
      }
    }
    for (int i = 1; i <= n; ++i) {
      if (cnt[i] >= 2) {
        ont[i] = true;
      }
    }
    for (int i = 1; i <= n; ++i) {
      if (ont[seq[i]]) {
        int x = seq[i], y = par[x];
        for (; y && !ont[y]; y = par[y]) {
          if (!vac[y]) {
            int t = val[y] - siz[y];
            if (t < 0) {
              ++ptr[x];
            }
            anc[x].pb(t);
          }
        }
        vpr[x] = y;
        sort(anc[x].begin(), anc[x].end());
      }
    }
    for (int i = l; i <= r; ++i) {
      int x = qry[i], d = vac[x] ? -1 : 1;
      vac[x] = !vac[x];
      if (val[x] < add[x] + siz[x]) {
        cur -= d;
      }
      for (; x; x = vpr[x]) {
        if (!vac[x] && val[x] < add[x] + siz[x]) {
          --cur;
        }
        add[x] += d;
        if (!vac[x] && val[x] < add[x] + siz[x]) {
          ++cur;
        }
        cur -= ptr[x];
        ptr[x] = lower_bound(anc[x].begin(), anc[x].end(), add[x]) - anc[x].begin();
        cur += ptr[x];
      } 
      printf("%d%c", cur, i == m ? '\n' : ' ');
    }
  }
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}