#include <bits/stdc++.h>


#include <cassert>
#include <vector>


#include <cassert>
#include <numeric>
#include <type_traits>

namespace atcoder {

namespace internal {

#ifndef _MSC_VER
template <class T>
using is_signed_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value ||
                                  std::is_same<T, __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int128 =
    typename std::conditional<std::is_same<T, __uint128_t>::value ||
                                  std::is_same<T, unsigned __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using make_unsigned_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value,
                              __uint128_t,
                              unsigned __int128>;

template <class T>
using is_integral = typename std::conditional<std::is_integral<T>::value ||
                                                  is_signed_int128<T>::value ||
                                                  is_unsigned_int128<T>::value,
                                              std::true_type,
                                              std::false_type>::type;

template <class T>
using is_signed_int = typename std::conditional<(is_integral<T>::value &&
                                                 std::is_signed<T>::value) ||
                                                    is_signed_int128<T>::value,
                                                std::true_type,
                                                std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<(is_integral<T>::value &&
                               std::is_unsigned<T>::value) ||
                                  is_unsigned_int128<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<
    is_signed_int128<T>::value,
    make_unsigned_int128<T>,
    typename std::conditional<std::is_signed<T>::value,
                              std::make_unsigned<T>,
                              std::common_type<T>>::type>::type;

#else

template <class T> using is_integral = typename std::is_integral<T>;

template <class T>
using is_signed_int =
    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<is_integral<T>::value &&
                                  std::is_unsigned<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<is_signed_int<T>::value,
                                              std::make_unsigned<T>,
                                              std::common_type<T>>::type;

#endif

template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

template <class T> using to_unsigned_t = typename to_unsigned<T>::type;

}  // namespace internal

}  // namespace atcoder


namespace atcoder {

template <class T> struct fenwick_tree {
    using U = internal::to_unsigned_t<T>;

  public:
    fenwick_tree() : _n(0) {}
    explicit fenwick_tree(int n) : _n(n), data(n) {}

    void add(int p, T x) {
        assert(0 <= p && p < _n);
        p++;
        while (p <= _n) {
            data[p - 1] += U(x);
            p += p & -p;
        }
    }

    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        return sum(r) - sum(l);
    }

  private:
    int _n;
    std::vector<U> data;

    U sum(int r) {
        U s = 0;
        while (r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
};

}  // namespace atcoder


// https://kopricky.github.io/code/DataStructure_OnGraph/lca.html

namespace kopricky {

using namespace std;

template <typename T>
class segtree {
 private:
  int n, sz;
  vector<pair<T, int>> node;

 public:
  void resize(const vector<T>& v) {
    sz = (int)v.size();
    n = 1;
    while (n < sz) {
      n *= 2;
    }
    node.resize(2 * n);
    for (int i = 0; i < sz; i++) {
      node[i + n] = make_pair(v[i], i);
    }
    for (int i = n - 1; i >= 1; i--) {
      node[i] = min(node[2 * i], node[2 * i + 1]);
    }
  }
  pair<T, int> query(int a, int b) {
    pair<T, int> res1 = make_pair(numeric_limits<T>::max(), -1);
    pair<T, int> res2 = make_pair(numeric_limits<T>::max(), -1);
    a += n, b += n;
    while (a != b) {
      if (a % 2) res1 = min(res1, node[a++]);
      if (b % 2) res2 = min(res2, node[--b]);
      a >>= 1, b >>= 1;
    }
    return min(res1, res2);
  }
};

class LCA {
 private:
  int V;
  vector<vector<int>> G;
  vector<int> ord, depth, id;
  segtree<int> st;
  void dfs(int u, int p, int k) {
    id[u] = (int)ord.size();
    ord.push_back(u);
    depth[u] = k;
    for (int v : G[u]) {
      if (v != p) {
        dfs(v, u, k + 1);
        ord.push_back(u);
      }
    }
  }

 public:
  LCA(int node_size) : V(node_size), G(V), depth(V), id(V, -1) {}
  void add_edge(int from, int to) {
    G[from].push_back(to), G[to].push_back(from);
  }
  void build() {
    ord.reserve(2 * V - 2);
    for (int i = 0; i < V; i++) {
      if (id[i] < 0) {
        dfs(i, -1, 0);
      }
    }
    vector<int> stvec(2 * V - 2);
    for (int i = 0; i < 2 * V - 2; i++) {
      stvec[i] = depth[ord[i]];
    }
    st.resize(stvec);
  }
  int lca(int u, int v) {
    return ord[st.query(min(id[u], id[v]), max(id[u], id[v]) + 1).second];
  }
  int dist(int u, int v) {
    int lca_ = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[lca_];
  }
};

}  // namespace kopricky

using namespace std::literals;

void solve(std::istream& is, std::ostream& os) {
  int n;
  is >> n;
  std::vector<std::vector<int>> g(n);
  for (int e = 0; e < n - 1; ++e) {
    int u, v;
    is >> u >> v;
    --u;
    --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  std::vector<int> pv(n, -1);
  std::vector<int> et;
  et.reserve(2 * n);
  {
    auto dfs = [&](auto self, int v, int p) -> void {
      et.push_back(v);
      for (int u : g[v]) {
        if (u == p) {
          continue;
        }
        pv[u] = v;
        self(self, u, v);
      }
      et.push_back(~v);
    };
    dfs(dfs, 0, -1);
  }

  std::vector vs(21, std::vector<std::vector<int>>(n));
  for (int v = 0; v < n; ++v) {
    int p = v;
    for (int i = 0; i <= 20; ++i) {
      vs[i][p].push_back(v);
      p = pv[p];
      if (p == -1) {
        break;
      }
    }
  }

  std::vector p(21, std::vector<std::array<int, 4>>(n));
  std::vector<atcoder::fenwick_tree<int>> f(21);
  std::vector pos(21, std::vector<std::array<int, 2>>(n));
  for (int i = 0; i <= 20; ++i) {
    int t = 0;
    for (int v : et) {
      if (0 <= v) {
        p[i][v][0] = t;
        for (int u : vs[i][v]) {
          pos[i][u][0] = t;
          ++t;
        }
        p[i][v][1] = t;
      } else {
        v = ~v;
        p[i][v][2] = t;
        for (int u : vs[i][v]) {
          pos[i][u][1] = t;
          ++t;
        }
        p[i][v][3] = t;
      }
    }
    f[i] = atcoder::fenwick_tree<int>(t + 1);
  }

  kopricky::LCA lca(n);
  for (int v = 1; v < n; ++v) {
    lca.add_edge(v, pv[v]);
  }
  lca.build();

  int q;
  is >> q;
  while (q--) {
    int t;
    is >> t;
    if (t == 1) {
      int v;
      is >> v;
      --v;
      int ans = 0;
      for (int i = 0; i <= 20; ++i) {
        ans += f[i].sum(0, pos[i][v][0] + 1);
        ans -= f[i].sum(0, pos[i][v][1] + 1);
      }
      os << ans << '\n';
    } else {
      int u, v, k, d;
      is >> u >> v >> k >> d;
      --u;
      --v;
      int w = lca.lca(u, v);
      f[d].add(p[d][w][0], k * 2);
      f[d].add(p[d][u][1], -k);
      f[d].add(p[d][v][1], -k);
      f[d].add(p[d][w][2], k);
      f[d].add(p[d][w][3], -k);
      for (int i = d; i--;) {
        int pw = w ? pv[w] : w;
        f[i].add(p[i][pw][0], k);
        f[i].add(p[i][w][1], -k);
        w = pw;
      }
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  solve(std::cin, std::cout);
}