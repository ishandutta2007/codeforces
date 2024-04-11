#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class T> struct dinic {
  struct edge {
    int to, rev;
    T cap;
    int id;
  };
  const T inf = numeric_limits<T>::max();
  vector<vector<edge>> g;
  vector<int> dist, i;
  dinic(int n) : g(n), dist(n), i(n) {}
  void add(int from, int to, T cap, int id = -1) {
    assert(cap >= 0);
    if (from == to or cap == 0) return;
    g[from].push_back({to, (int)g[to].size(), cap, id});
    g[to].push_back({from, (int)g[from].size() - 1, 0, -1});
  }
  void bfs(int s) {
    fill(begin(dist), end(dist), -1);
    queue<int> que;
    dist[s] = 0, que.push(s);
    while (not que.empty()) {
      int v = que.front();
      que.pop();
      for (auto&& e : g[v])
        if (e.cap and dist[e.to] == -1)
          dist[e.to] = dist[v] + 1, que.push(e.to);
    }
  }
  T dfs(int v, int s, T f) {
    if (v == s) return f;
    for (; i[v] < (int)g[v].size(); ++i[v]) {
      edge &e = g[v][i[v]];
      if (g[e.to][e.rev].cap and dist[e.to] < dist[v])
        if (T d = dfs(e.to, s, min(f, g[e.to][e.rev].cap)))
          return g[e.to][e.rev].cap -= d, e.cap += d, d;
    }
    return 0;
  }
  T max_flow(int s, int t) {
    assert(s != t);
    T res = 0;
    while (true) {
      bfs(s);
      if (dist[t] == -1) return res;
      fill(begin(i), end(i), 0);
      while (T f = dfs(t, s, inf)) res += f;
    }
  }
};

auto chmin = [](auto&& a, auto b) { return b < a ? a = b, 1 : 0; };

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  using ll = long long;
  ll r, b;
  cin >> r >> b;
  bool swapped = false;
  if (r > b) {
    swap(r, b);
    swapped = true;
  }
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }
  auto vx = x, vy = y;
  sort(begin(vx), end(vx));
  vx.erase(unique(begin(vx), end(vx)), end(vx));
  sort(begin(vy), end(vy));
  vy.erase(unique(begin(vy), end(vy)), end(vy));
  auto zipx = [&](int e) {
    return lower_bound(begin(vx), end(vx), e) - begin(vx);
  };
  auto zipy = [&](int e) {
    return lower_bound(begin(vy), end(vy), e) - begin(vy);
  };
  int h = size(vx), w = size(vy);
  vector<int> dh(h, n), dw(w, n);
  while (m--) {
    int t, l, d;
    cin >> t >> l >> d;
    if (t == 1) {
      int i = zipx(l);
      if (i == h or vx[i] != l) continue;
      chmin(dh[i], d);
    } else {
      int j = zipy(l);
      if (j == w or vy[j] != l) continue;
      chmin(dw[j], d);
    }
  }
  int s = h + w, t = s + 1, ss = t + 1, tt = ss + 1;
  dinic<int> g(h + w + 4);
  vector<int> degh(h), degw(w);
  for (int k = 0; k < n; ++k) {
    int i = zipx(x[k]);
    int j = zipy(y[k]);
    g.add(i, h + j, 1, k);
    ++degh[i];
    ++degw[j];
  }
  vector<int> bal(h + w + 2);
  auto add = [&](int from, int to, int lcap, int ucap) {
    if (lcap > ucap) {
      cout << "-1\n";
      exit(0);
    }
    g.add(from, to, ucap - lcap);
    bal[from] -= lcap;
    bal[to] += lcap;
  };
  for (int i = 0; i < h; ++i) {
    chmin(dh[i], degh[i]);
    add(s, i, (degh[i] - dh[i] + 1) / 2, (degh[i] + dh[i]) / 2);
  }
  for (int j = 0; j < w; ++j) {
    chmin(dw[j], degw[j]);
    add(h + j, t, (degw[j] - dw[j] + 1) / 2, (degw[j] + dw[j]) / 2);
  }
  g.add(t, s, g.inf, n);
  for (int v = 0; v < h + w + 2; ++v) {
    g.add(ss, v, max(+bal[v], 0));
    g.add(v, tt, max(-bal[v], 0));
  }
  g.max_flow(ss, tt);
  for (auto&& e : g.g[ss]) {
    if (e.cap) {
      cout << "-1\n";
      exit(0);
    }
  }
  // ll flow = g.es[ts].cap;
  // g.es[ts ^ 1].cap = 0;
  // g.s = t, g.t = s;
  // flow -= g.max_flow();
  for (auto&& e : g.g[t]) {
    if (e.id == n) {
      e.cap = 0;
      break;
    }
  }
  g.max_flow(t, s);
  ll cost = r * n;;
  string res(n, 'r');
  for (int v = 0; v < (int)size(g.g); ++v) {
    for (auto&& e : g.g[v]) {
      if (0 <= e.id and e.id < n) {
        if (e.cap == 0) {
          res[e.id] = 'b';
          cost += b - r;
        }
      }
    }
  }
  if (swapped) {
    for (auto&& e : res) {
      e ^= 'r' ^ 'b';
    }
  }
  cout << cost << '\n';
  cout << res << '\n';
}