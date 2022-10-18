#line 1 "main.cpp"
#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

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


#line 7 "main.cpp"

int n, f[100000];
int m;
int g[100000], h[100000], hs;

int main() {
  scanf("%d", &n);
  rep(i, n) scanf("%d", f + i), f[i]--;

  rep(x, n) if (f[x] != f[f[x]]) return printf("-1\n"), 0;

  atcoder::dsu uf(n);
  rep(x, n) uf.merge(x, f[x]);

  auto gs = uf.groups();
  m = gs.size();

  rep(i, m) {
    for (auto x : gs[i]) g[x] = i;
  }
  rep(x, n) h[g[f[x]]] = f[x];

  printf("%d\n", m);
  rep(i, n) printf("%d%c", g[i] + 1, " \n"[i==n-1]);
  rep(i, m) printf("%d%c", h[i] + 1, " \n"[i==m-1]);
}