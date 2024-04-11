#line 1 "main.cpp"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep2(i, m, n) for (auto i = (m); i < (n); i++)
#define rep(i, n) rep2(i, 0, n)
#define all(x) begin(x), end(x)

#line 1 "ac-library/atcoder/dsu.hpp"



#line 7 "ac-library/atcoder/dsu.hpp"

namespace atcoder {

// Implement (union by size) + (path compression)
// Reference:
// Zvi Galil and Giuseppe F. Italiano,
// Data structures and algorithms for disjoint set union problems
struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

}  // namespace atcoder


#line 9 "main.cpp"

int n, m;
vector<int> G[300000]; bool w[300000];
int q, a[300000], b[300000];
int dep[300000], par[300000];


void dfs(int v, int p) {
  par[v] = p;
  for (auto u : G[v]) if (u != p) dep[u] = dep[v] + 1, dfs(u, v);
}

int ans;
void dfs2(int v, int p) {
  int c = 0;
  for (auto u : G[v]) if (u != p) c += w[u], dfs2(u, v);
  ans += w[v] ? c/2 : (c+1)/2;
}

int main() {
  scanf("%d%d", &n, &m);
  atcoder::dsu dsu(n);
  rep(i, m) {
    int x, y; scanf("%d%d", &x, &y), x--, y--;
    if (!dsu.same(x, y)) {
      dsu.merge(x, y);
      G[x].push_back(y);
      G[y].push_back(x);
    }
  }
  scanf("%d", &q);
  rep(i, q) scanf("%d%d", a+i, b+i), a[i]--, b[i]--;

  dfs(0, 0);

  rep(i, q) {
    int u = a[i], v = b[i];
    if (dep[u] < dep[v]) swap(u, v);
    while (dep[u] > dep[v]) w[u] ^= 1, u = par[u];
    while (u != v) w[u] ^= 1, u = par[u], w[v] ^= 1, v = par[v];
  }

  dfs2(0, 0);

  if (ans) return printf("NO\n%d\n", ans), 0;
  printf("YES\n");

  vector<int> us, vs;
  rep(i, q) {
    int u = a[i], v = b[i];

    us.push_back(u), vs.push_back(v);

    while (dep[u] > dep[v]) us.push_back(u = par[u]);
    while (dep[v] > dep[u]) vs.push_back(v = par[v]);

    while (u != v) us.push_back(u = par[u]), vs.push_back(v = par[v]);

    vs.pop_back();
    us.insert(us.end(), vs.rbegin(), vs.rend());

    printf("%zd\n", us.size());
    rep(i, us.size()) printf("%d%c", us[i]+1, " \n"[i==us.size()-1]);

    us.clear(), vs.clear();
  }
}