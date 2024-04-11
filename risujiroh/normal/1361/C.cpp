#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template< typename T >
struct edge {
  int src, to;
  T cost;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}

  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;

template< typename T >
vector< edge< T > > eulerian_path(Edges< T > es, int s, bool directed) {
  int V = 0;
  for(auto &e : es) V = max(V, max(e.to, e.src) + 1);
  vector< vector< pair< edge< T >, int > > > g(V);
  for(auto &e : es) {
    int sz_to = (int) g[e.to].size();
    g[e.src].emplace_back(e, sz_to);
    if(!directed) {
      int sz_src = (int) g[e.src].size() - 1;
      swap(e.src, e.to);
      g[e.src].emplace_back(e, sz_src);
    }
  }
  vector< edge< T > > ord;
  stack< pair< int, edge< T > > > st;
  st.emplace(s, edge< T >(-1, -1));
  while(st.size()) {
    int idx = st.top().first;
    if(g[idx].empty()) {
      ord.emplace_back(st.top().second);
      st.pop();
    } else {
      auto e = g[idx].back();
      g[idx].pop_back();
      if(e.second == -1) continue;
      if(!directed) g[e.first.to][e.second].second = -1;
      st.emplace(e.first.to, e.first);
    }
  }
  ord.pop_back();
  reverse(begin(ord), end(ord));
  if(ord.size() != es.size()) return {};
  return ord;
}

struct dsu {
  int cc;
  vector<int> p, sz;
  dsu(int n = 0) : cc(n), p(n, -1), sz(n, 1) {}
  int root(int v) const {
    while (p[v] != -1) v = p[v];
    return v;
  }
  bool unite(int u, int v) {
    u = root(u), v = root(v);
    if (u == v) return false;
    --cc;
    if (sz[u] < sz[v]) swap(u, v);
    p[v] = u;
    sz[u] += sz[v];
    return true;
  }
  bool same(int u, int v) const { return root(u) == root(v); }
  int size(int v) const { return sz[root(v)]; }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
  }
  auto chk = [&](int k) {
    int mask = (1 << k) - 1;
    dsu d(1 << k);
    vector<int> deg(1 << k);
    for (int i = 0; i < n; ++i) {
      ++deg[a[i] & mask];
      ++deg[b[i] & mask];
      d.unite(a[i] & mask, b[i] & mask);
    }
    set<int> se;
    for (int v = 0; v < 1 << k; ++v) {
      if (deg[v] & 1) {
        return false;
      }
      if (deg[v]) {
        se.insert(d.root(v));
      }
    }
    return size(se) == 1;
  };
  int ok = 0, ng = 21;
  while (ng - ok > 1) {
    int mid = (ok + ng) / 2;
    (chk(mid) ? ok : ng) = mid;
  }
  cout << ok << '\n';
  int mask = (1 << ok) - 1;
  Edges<int> es;
  map<pair<int, int>, vector<int>> mp;
  for (int i = 0; i < n; ++i) {
    a[i] &= mask;
    b[i] &= mask;
    es.emplace_back(a[i], b[i], -1);
    mp[minmax({a[i], b[i]})].push_back(i);
  }
  auto ord = eulerian_path(es, a[0], false);
  vector<int> res;
  for (int i = 0; i < n; ++i) {
    int x = ord[i], y = ord[(i + 1) % n];
    int j = mp[minmax({x, y})].back();
    mp[minmax({x, y})].pop_back();
    if (a[j] == y and b[j] == x) {
      res.emplace_back(2 * j + 1);
      res.emplace_back(2 * j + 0);
    } else {
      assert(a[j] == x and b[j] == y);
      res.emplace_back(2 * j + 0);
      res.emplace_back(2 * j + 1);
    }
  }
  for (int i = 0; i < 2 * n; ++i) {
    cout << res[i] + 1 << " \n"[i == 2 * n - 1];
  }
  // for (int i = 0; i < 2 * n; ++i) {
  //   cout << (res[i] & 1 ? b : a)[res[i] / 2] << " \n"[i == 2 * n - 1];
  // }
}