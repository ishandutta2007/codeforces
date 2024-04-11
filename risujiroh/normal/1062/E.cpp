#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


V<> dep;
VV<> par;

int get_par(int v, int h) {
  for (int k = 0; h > 0; h >>= 1, ++k) {
    if (v == -1) return v;
    if (h & 1) v = par[k][v];
  }
  return v;
}

int lca(int u, int v) {
  if (dep[u] > dep[v]) swap(u, v);
  v = get_par(v, dep[v] - dep[u]);
  if (u == v) return u;
  for (int k = par.size() - 1; k >= 0; --k) {
    if (par[k][u] != par[k][v]) u = par[k][u], v = par[k][v];
  }
  return par[0][u];
}

struct LCASemilattice {
  using T = int;
  static T op(T u, T v) { return u == e() ? v : v == e() ? u : lca(u, v); }
  static constexpr T e() { return -1; }
};

template<class Semilattice> struct SparseTable {
  using T = typename Semilattice::T;

  const int n;
  VV<T> val;
  
  template<class Itr> SparseTable(Itr first, Itr last) : n(distance(first, last)) {
    assign(val, __lg(n) + 1, n, Semilattice::e());
    copy(first, last, begin(val[0]));
    for (int k = 0; k < __lg(n); ++k) for (int i = 0; i < n; ++i) {
      val[k + 1][i] = Semilattice::op(val[k][i], i + (1 << k) < n ? val[k][i + (1 << k)] : Semilattice::e());
    }
  }

  T get(int l, int r) const {
    l = max(l, 0), r = min(r, n);
    if (l >= r) return Semilattice::e();
    int k = __lg(r - l);
    return Semilattice::op(val[k][l], val[k][r - (1 << k)]);
  }
};

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n, q; cin >> n >> q;
  assign(par, __lg(2 * n - 1) + 1, n, -1);
  VV<> chi(n);
  for (int v = 1; v < n; ++v) {
    cin >> par[0][v], --par[0][v];
    chi[par[0][v]].push_back(v);
  }
  for (int k = 0; k < __lg(2 * n - 1); ++k) for (int v = 0; v < n; ++v) {
    par[k + 1][v] = par[k][v] != -1 ? par[k][par[k][v]] : -1;
  }
  assign(dep, n);
  auto dfs = [&](auto dfs, int v) -> void {
    for (int w : chi[v]) {
      dep[w] = dep[v] + 1;
      dfs(dfs, w);
    }
  };
  dfs(dfs, 0);
  V<> id(n); iota(begin(id), end(id), 0);
  SparseTable<LCASemilattice> st(begin(id), end(id));
  for (int i = 0; i < q; ++i) {
    int ql, qr; cin >> ql >> qr, --ql;
    V<> vs;
    auto rec = [&](auto rec, int l, int r) -> void {
      if (r - l == 1) {
        vs.push_back(l);
        return;
      }
      int m = l + r >> 1;
      int a = st.get(l, r), al = st.get(l, m), ar = st.get(m, r);
      if (al != a and ar == a) rec(rec, m, r);
      if (ar != a and al == a) rec(rec, l, m);
      if (al == a and ar == a) vs.push_back(l);
      if (al != a and ar != a) vs.push_back(l), vs.push_back(m);
    };
    rec(rec, ql, qr);
    int resv, resd = -1;
    for (int v : vs) {
      int d = dep[LCASemilattice::op(st.get(ql, v), st.get(v + 1, qr))];
      if (d > resd) resv = v, resd = d;
    }
    cout << resv + 1 << ' ' << resd << '\n';
  }
}