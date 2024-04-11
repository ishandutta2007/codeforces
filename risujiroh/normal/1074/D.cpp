#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


struct XorGroup {
  using T = int;
  static T op(const T& lhs, const T& rhs) { return lhs ^ rhs; }
  static constexpr T e() { return 0; }
  static T inv(const T& val) { return val; }
};

template<class AbelianGroup> struct UnionFind {
  using T = typename AbelianGroup::T;

  V<> dat;
  V<T> pot;

  UnionFind(int n) : dat(n, -1), pot(n, AbelianGroup::e()) {}

  T sub(const T& lhs, const T& rhs) { return AbelianGroup::op(lhs, AbelianGroup::inv(rhs)); }

  T diff(int u, int v) {
    assert(same(u, v));
    return sub(pot[v], pot[u]);
  }

  int find(int v) {
    if (dat[v] < 0) return v;
    else {
      int r = find(dat[v]);
      pot[v] = AbelianGroup::op(pot[v], pot[dat[v]]);
      return dat[v] = r;
    }
  }

  bool same(int u, int v) { return find(u) == find(v); }

  int size(int v) { return -dat[find(v)]; }

  void unite(int u, int v, T d) {
    assert(!same(u, v));
    d = sub(d, sub(pot[v], pot[u]));
    if (dat[u] >= 0) u = dat[u];
    if (dat[v] >= 0) v = dat[v];
    if (-dat[u] < -dat[v]) {
      dat[v] += dat[u];
      dat[u] = v;
      pot[u] = AbelianGroup::inv(d);
    } else {
      dat[u] += dat[v];
      dat[v] = u;
      pot[v] = d;
    }
  }
};

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int q; cin >> q;
  UnionFind<XorGroup> uf(2 * q);
  int last = 0;
  map<int, int> mp;
  int c = 0;
  for (int i = 0; i < q; ++i) {
    int t; cin >> t;
    if (t == 1) {
      int l, r, x; cin >> l >> r >> x;
      l ^= last, r ^= last, x ^= last;
      if (l > r) swap(l, r);
      ++r;
      if (mp.count(l) and mp.count(r) and uf.same(mp[l], mp[r])) continue;
      if (!mp.count(l)) mp[l] = c++;
      if (!mp.count(r)) mp[r] = c++;
      uf.unite(mp[l], mp[r], x);
    } else {
      int l, r; cin >> l >> r;
      l ^= last, r ^= last;
      if (l > r) swap(l, r);
      ++r;
      if (mp.count(l) and mp.count(r) and uf.same(mp[l], mp[r])) cout << (last = uf.diff(mp[l], mp[r])) << '\n';
      else cout << -(last = 1) << '\n';
    }
  }
}