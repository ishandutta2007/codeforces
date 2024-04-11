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
  int u, v, w;
  bool operator<(const Edge& rhs) { return w < rhs.w; }
};

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n, m, k; cin >> n >> m >> k;
  V<> x(k); for (int i = 0; i < k; ++i) cin >> x[i], --x[i];
  V<Edge> es(m);
  for (int i = 0; i < m; ++i) {
    int u, v, w; cin >> u >> v >> w, --u, --v;
    es.push_back({u, v, w});
  }
  sort(begin(es), end(es));
  auto chk = [&](int y) -> bool {
    UnionFind uf(n);
    for (const auto& e : es) {
      if (e.w > y) break;
      uf.unite(e.u, e.v);
    }
    for (int i = 1; i < k; ++i) {
      if (!uf.same(x[0], x[i])) return false;
    }
    return true;
  };
  int ng = 0, ok = 1e9;
  while (ok - ng > 1) {
    int mid = ng + ok >> 1;
    (chk(mid) ? ok : ng) = mid;
  }
  for (int i = 0; i < k; ++i) {
    cout << ok << (i != k - 1 ? ' ' : '\n');
  }
}