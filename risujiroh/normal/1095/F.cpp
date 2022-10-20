#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using lint = long long int;
using ulint = unsigned long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


struct UnionFind {
  const int n;

  UnionFind(int n) : n(n), dat(n, -1) {}

  bool same(int u, int v) {
    assert(0 <= u and u < n);
    assert(0 <= v and v < n);
    return find(u) == find(v);
  }

  int size(int v) {
    assert(0 <= v and v < n);
    return -dat[find(v)];
  }

  void unite(int u, int v) {
    assert(0 <= u and u < n);
    assert(0 <= v and v < n);
    if ((u = find(u)) == (v = find(v))) return;
    if (-dat[u] < -dat[v]) {
      dat[v] += dat[u];
      dat[u] = v;
    } else {
      dat[u] += dat[v];
      dat[v] = u;
    }
  }

private:
  V<> dat; // dat[v] := v ? -size : parent

  int find(int v) {
    return dat[v] < 0 ? v : dat[v] = find(dat[v]);
  }
};

struct Edge { 
  int u, v;
  lint w;
  bool operator<(const auto& rhs) { return w < rhs.w; }
};

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  V<lint> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  V<Edge> es;
  int s = distance(begin(a), min_element(begin(a), end(a)));
  for (int i = 0; i < n; ++i) if (i != s) {
    es.push_back({s, i, a[s] + a[i]});
  }
  for (int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v, --u, --v;
    lint w; cin >> w;
    es.push_back({u, v, w});
  }
  sort(begin(es), end(es));
  lint res = 0;
  UnionFind uf(n);
  for (const auto& e : es) {
    if (uf.same(e.u, e.v)) continue;
    uf.unite(e.u, e.v);
    res += e.w;
  }
  cout << res << '\n';
}