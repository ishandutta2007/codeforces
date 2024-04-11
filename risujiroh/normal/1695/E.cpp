#include <bits/stdc++.h>

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

#ifndef LOCAL
#define LOCAL 0
#define DUMP(...) void(0)
#endif

// https://github.com/kth-competitive-programming/kactl
namespace kactl {

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi eulerWalk(vector<vector<pii>>& gr, int nedges, int src = 0) {
  int n = sz(gr);
  static vi D(n), its(n);
  vi eu(nedges), ret, s = {src};
  D[src]++;  // to allow Euler paths, not just cycles
  while (!s.empty()) {
    int x = s.back(), y, e, &it = its[x], end = sz(gr[x]);
    if (it == end) {
      ret.push_back(x);
      s.pop_back();
      continue;
    }
    tie(y, e) = gr[x][it++];
    if (!eu[e]) {
      D[x]--, D[y]++;
      eu[e] = 1;
      s.push_back(y);
    }
  }
  for (int x : D)
    if (x < 0 || sz(ret) != nedges + 1) return {};
  return {ret.rbegin(), ret.rend()};
}

#undef rep
#undef all
#undef sz

}  // namespace kactl

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;
  vector<vector<kactl::pii>> g(2 * n);
  atcoder::dsu d(2 * n);
  vector<int> num_edges(2 * n);
  for (int e = 0; e < n; ++e) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    g[x].emplace_back(y, e);
    g[y].emplace_back(x, e);
    g[x].emplace_back(y, n + e);
    g[y].emplace_back(x, n + e);
    x = d.leader(x);
    y = d.leader(y);
    if (x != y) {
      int z = d.merge(x, y);
      num_edges[z] = num_edges[x] + num_edges[y];
    }
    ++num_edges[d.leader(x)];
  }

  vector a(2, vector<int>(n));
  vector s0(2, string(n, '?'));
  vector s1(2, string(n, '?'));
  int offset = 0;

  for (auto&& vertices : d.groups()) {
    int leader = d.leader(vertices[0]);
    if (num_edges[leader] == 0) {
      continue;
    } else if (num_edges[leader] == 1) {
      cout << "-1\n";
      return 0;
    }

    {
      vector<int> es;
      es.reserve(4 * num_edges[leader]);
      for (int v : vertices) {
        for (auto [_, e] : g[v]) {
          es.push_back(e);
        }
      }
      sort(begin(es), end(es));

      for (int v : vertices) {
        for (auto&& [_, e] : g[v]) {
          e = int(lower_bound(begin(es), end(es), e) - begin(es)) / 2;
        }
      }
    }

    auto cycle = kactl::eulerWalk(g, 2 * num_edges[leader], leader);
    assert(int(size(cycle)) == 2 * num_edges[leader] + 1);

    for (int i = 0; i < num_edges[leader]; ++i) {
      a[0][offset + i] = cycle[i];
      a[1][offset + (num_edges[leader] - i - 1)] = cycle[num_edges[leader] + i];
    }

    if (num_edges[leader] & 1) {
      for (int i = 0; i + 1 < num_edges[leader]; i += 2) {
        s0[0][offset + i] = 'L';
        s0[1][offset + i] = 'L';
        s0[0][offset + i + 1] = 'R';
        s0[1][offset + i + 1] = 'R';
      }
      s0[0][offset + num_edges[leader] - 1] = 'U';
      s0[1][offset + num_edges[leader] - 1] = 'D';

      s1[0][offset] = 'U';
      s1[1][offset] = 'D';
      for (int i = 1; i + 1 < num_edges[leader]; i += 2) {
        s1[0][offset + i] = 'L';
        s1[1][offset + i] = 'L';
        s1[0][offset + i + 1] = 'R';
        s1[1][offset + i + 1] = 'R';
      }
    } else {
      for (int i = 0; i + 1 < num_edges[leader]; i += 2) {
        s0[0][offset + i] = 'L';
        s0[1][offset + i] = 'L';
        s0[0][offset + i + 1] = 'R';
        s0[1][offset + i + 1] = 'R';
      }

      s1[0][offset] = 'U';
      s1[1][offset] = 'D';
      s1[0][offset + num_edges[leader] - 1] = 'U';
      s1[1][offset + num_edges[leader] - 1] = 'D';
      for (int i = 1; i + 1 < num_edges[leader]; i += 2) {
        s1[0][offset + i] = 'L';
        s1[1][offset + i] = 'L';
        s1[0][offset + i + 1] = 'R';
        s1[1][offset + i + 1] = 'R';
      }
    }

    offset += num_edges[leader];
  }

  cout << "2 " << n << "\n\n";
  for (int i = 0; i < n; ++i) {
    cout << a[0][i] + 1 << " \n"[i + 1 == n];
  }
  for (int i = 0; i < n; ++i) {
    cout << a[1][i] + 1 << " \n"[i + 1 == n];
  }
  cout << '\n';
  cout << s0[0] << '\n';
  cout << s0[1] << '\n';
  cout << '\n';
  cout << s1[0] << '\n';
  cout << s1[1] << '\n';
}