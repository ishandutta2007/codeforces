#line 2 "lib/prelude.hpp"
#ifndef LOCAL
#pragma GCC optimize("O3")
/* #pragma GCC target("avx2") */
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep2(i, m, n) for (auto i = (m); i < (n); i++)
#define rep(i, n) rep2(i, 0, n)
#define repr2(i, m, n) for (auto i = (n); i-- > (m);)
#define repr(i, n) repr2(i, 0, n)
#define all(x) begin(x), end(x)
template <class T>
auto ndvec(size_t n, T&& x) { return vector(n, forward<T>(x)); }
template <class... Ts>
auto ndvec(size_t n, Ts&&... xs) { return vector(n, ndvec(forward<Ts>(xs)...)); }
#line 3 "lib/ds/dsu.hpp"

class dsu {
 public:
  dsu(int n) : par(n, -1), count_(n) {}
  int count() const { return count_; }
  void clear() {
    fill(par.begin(), par.end(), -1);
    count_ = par.size();
  }
  int find(int x) { return par[x] < 0 ? x : par[x] = (int)find(par[x]); }
  bool same(int x, int y) { return find(x) == find(y); }
  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    if (par[x] > par[y]) swap(x, y);
    par[x] += par[y], par[y] = (int)x;
    count_--;
    return true;
  }
  int size(int x) { return -par[find(x)]; }
  vector<vector<int>> groups() {
    vector<vector<int>> res(par.size());
    for (int x = 0; x < par.size(); x++) res[find(x)].push_back(x);
    res.erase(remove_if(all(res), [](const auto& v) { return v.empty(); }),
              res.end());
    return res;
  }

 private:
  vector<int> par;
  int count_;
};
#line 3 "main.cpp"

int read() {
  int x; scanf("%d", &x); return x;
}

void solve() {
  int n = read();
  vector<int> d(n); rep(i, n) d[i] = read();
  vector<vector<int>> G(n);

  auto ask = [&](int v) {
    assert(G[v].size() < d[v]);
    printf("? %d\n", v + 1);
    fflush(stdout);
    int u = read() - 1;
    G[v].push_back(u);
    return u;
  };

  vector<int> vs(n); iota(all(vs), 0);
  sort(all(vs), [&](int u, int v) { return d[u] > d[v]; });

  vector<char> done(n);
  dsu dsu(n);

  for (auto v : vs) if (!done[v]) {
    done[v] = true;
    while (G[v].size() < d[v]) {
      int u = ask(v);
      dsu.unite(u, v);
      if (done[u]) break;
      done[u] = true;
    }
  }
  
  vector<int> c(n, -1);
  auto gs = dsu.groups();
  rep(i, gs.size()) for (auto v : gs[i]) c[v] = i+1;
  printf("!");
  for (auto x : c) printf(" %d", x);
  printf("\n");
  fflush(stdout);
}

int main() {
  int T = read();
  while (T--) solve();
}