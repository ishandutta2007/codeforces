#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

constexpr lint inf = 1e18;
struct edge { int to; lint cost; edge(int to, lint cost) : to(to), cost(cost) {} };

template<class T> V<T> dijkstra(int s, const VV<edge>& g) {
  V<T> d(g.size(), inf);
  using P = pair<T, int>;
  priority_queue<P, V<P>, greater<P> > pq;
  pq.emplace(d[s] = 0, s);
  while (!pq.empty()) {
    T dv; int v; tie(dv, v) = pq.top(); pq.pop();
    if (dv > d[v]) continue;
    for (auto&& e : g[v]) {
      if (d[e.to] < d[v] + e.cost) continue;
      pq.emplace(d[e.to] = d[v] + e.cost, e.to);
    } 
  }
  return d;
}

struct QU {
  V<> par, rank, _size;

  QU(int n) { 
    par.resize(n);
    iota(par.begin(), par.end(), 0);
    rank.resize(n);
    _size.assign(n, 1);
  }

  int find(int a) {
    if (par[a] == a) return a;
    return par[a] = find(par[a]);
  }

  bool same(int a, int b) { return find(a) == find(b); }

  int size(int a) { return _size[find(a)]; }

  void unite(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return;
    if (rank[a] < rank[b]) {
      par[a] = b;
      _size[b] += _size[a];
    } else {
      par[b] = a;
      _size[a] += _size[b];
    }
    if (rank[a] == rank[b]) rank[a]++;
  }
};

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  VV<edge> g(n), tree(n);
  V<> vs;
  QU qu(n);
  for (int i = 0; i < m; i++) {
    int u, v, d; cin >> u >> v >> d, u--, v--;
    g[u].emplace_back(v, d);
    g[v].emplace_back(u, d);
    if (!qu.same(u, v)) {
      tree[u].emplace_back(v, d);
      tree[v].emplace_back(u, d);
      qu.unite(u, v);
    } else {
      vs.push_back(u);
      vs.push_back(v);
    }
  }

  V<> depth(n, -1);
  VV<> par; assign(par, __lg(n) + 2, n, -1);
  VV<lint> dist; assign(dist, __lg(n) + 2, n);
  queue<int> que;
  depth[0] = 0; que.push(0);
  while (!que.empty()) {
    int v = que.front(); que.pop();
    for (auto&& e : tree[v]) if (depth[e.to] == -1) {
      par[0][e.to] = v;
      dist[0][e.to] = e.cost;
      depth[e.to] = depth[v] + 1; que.push(e.to);
    }
  }
  for (int k = 0; k < __lg(n) + 1; k++) for (int i = 0; i < n; i++) if (par[k][i] != -1) {
    par[k + 1][i] = par[k][par[k][i]];
    dist[k + 1][i] = dist[k][i] + dist[k][par[k][i]];
  }
  auto get = [&](int v, int h) {
    lint res = 0;
    int k = 0;
    while (h) {
      if (h & 1) {
        res += dist[k][v];
        v = par[k][v];
        if (v == -1) return make_pair(-1, res);
      }
      h >>= 1;
      k++;
    }
    return make_pair(v, res);
  };
  auto f = [&](int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    lint res;
    tie(u, res) = get(u, depth[u] - depth[v]);
    if (u != v) {
      int ng = 0, ok = n;
      while (ok - ng > 1) {
        int mid = (ng + ok) / 2;
        if (get(u, mid).first != get(v, mid).first) ng = mid;
        else ok = mid;
      }
      res += get(u, ok).second + get(v, ok).second;
    }
    return res;
  };

  int nv = vs.size();
  VV<lint> d(nv);
  for (int i = 0; i < nv; i++) d[i] = dijkstra<lint>(vs[i], g);

  int q; cin >> q;
  for (int iq = 0; iq < q; iq++) {
    int u, v; cin >> u >> v, u--, v--;
    lint res = f(u, v);
    for (int i = 0; i < nv; i++) {
      res = min(res, d[i][u] + d[i][v]);
    }
    cout << res << '\n';
  }
}