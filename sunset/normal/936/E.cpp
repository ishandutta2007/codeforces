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
const int inf = 0x3f3f3f3f;

int n, m, tim, f[N], ans[N], bel[N], cnt[N], fir[N], siz[N], vis[N], bit_u[N], bit_v[N];
vector <int> seq, adv[N], qry[N];
vector <pii> all, upd;
map <pii, int> idx;
set <int> adj[N];
pii a[N], dis[N];
queue <int> q;

inline void DFS(int x, int p) {
  seq.pb(x), siz[x] = 1, f[x] = 0, vis[x] = tim;
  for (auto y : adj[x]) {
    if (y != p) {
      DFS(y, x), siz[x] += siz[y], CheckMax(f[x], siz[y]);
    }
  }
}

inline void Solve(int x) {
  int c = 0;
  seq.clear(), ++tim, DFS(x, 0);
  for (auto i : seq) {
    CheckMax(f[i], siz[x] - siz[i]);
    if (f[c] > f[i]) {
      c = i;
    }
  }
  x = c;
  for (auto i : seq) {
    if (i == x) {
      for (int j = 0; j < cnt[i]; ++j) {
        dis[i + j] = mp(0, j + 1), q.push(i + j);
      }
    } else {
      for (int j = 0; j < cnt[i]; ++j) {
        dis[i + j] = mp(inf, 0);
      }
    }
  }
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (auto y : adv[x]) {
      if (vis[bel[y]] == tim && CheckMin(dis[y], mp(dis[x].X + 1, dis[x].Y))) {
        q.push(y);
      }
    }
  }
  upd.clear(), all.clear();
  for (auto i : seq) {
    for (int j = 0; j < cnt[i]; ++j) {
      if (fir[i + j] != inf) {
        upd.pb(mp(fir[i + j], i + j));
      }
      for (auto k : qry[i + j]) {
        all.pb(mp(k, i + j));
      }
    }
  }
  sort(upd.begin(), upd.end()), sort(all.begin(), all.end());
  for (int i = 1; i <= cnt[x]; ++i) {
    bit_u[i] = bit_v[i] = inf;
  }
  int cur = 0;
  for (auto q : all) {
    for (; cur < upd.size() && upd[cur].X < q.X; ++cur) {
      for (int i = dis[upd[cur].Y].Y; i <= cnt[x]; i += i & -i) {
        CheckMin(bit_u[i], dis[upd[cur].Y].X - dis[upd[cur].Y].Y);
      }
      for (int i = dis[upd[cur].Y].Y; i; i -= i & -i) {
        CheckMin(bit_v[i], dis[upd[cur].Y].X + dis[upd[cur].Y].Y);
      }
    }
    for (int i = dis[q.Y].Y; i; i -= i & -i) {
      CheckMin(ans[q.X], bit_u[i] + dis[q.Y].X + dis[q.Y].Y);
    }
    for (int i = dis[q.Y].Y; i <= cnt[x]; i += i & -i) {
      CheckMin(ans[q.X], bit_v[i] + dis[q.Y].X - dis[q.Y].Y);
    }
  }
  for (auto y : adj[x]) {
    adj[y].erase(x);
  }
  for (auto y : adj[x]) {
    Solve(y);
  }
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n), f[0] = inf;
  for (int i = 1; i <= n; ++i) {
    Read(a[i].X), Read(a[i].Y), fir[i] = inf;
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) {
    idx[a[i]] = i;
  }
  for (int i = 1; i <= n; ++i) {
    if (a[i].X == a[i - 1].X && a[i].Y == a[i - 1].Y + 1) {
      bel[i] = bel[i - 1];
      adv[i].pb(i - 1), adv[i - 1].pb(i);
    } else {
      bel[i] = i;
    }
    if (idx.find(mp(a[i].X - 1, a[i].Y)) != idx.end()) {
      int j = idx[mp(a[i].X - 1, a[i].Y)];
      adv[i].pb(j), adv[j].pb(i);
      adj[bel[i]].insert(bel[j]), adj[bel[j]].insert(bel[i]);
    }
    ++cnt[bel[i]];
  }
  Read(m);
  for (int i = 1, opt, x, y, z; i <= m; ++i) {
    Read(opt), Read(x), Read(y), z = idx[mp(x, y)];
    if (opt == 1) {
      CheckMin(fir[z], i), ans[i] = -1;
    } else {
      qry[z].pb(i), ans[i] = inf;
    }
  }
  Solve(1);
  for (int i = 1; i <= m; ++i) {
    if (~ans[i]) {
      if (ans[i] > n) {
        puts("-1");
      } else {
        printf("%d\n", ans[i]);
      }
    }
  }
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}