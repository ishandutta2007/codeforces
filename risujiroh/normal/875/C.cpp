#include <bits/stdc++.h>
using namespace std;

template <class T> struct sparse_table {
  vector<vector<T>> t;
  sparse_table(const vector<T>& v = {}) : t{v} {
    for (int k = 1, n = v.size(); 1 << k <= n; ++k) {
      t.emplace_back(n - (1 << k) + 1);
      for (int i = 0; i + (1 << k) <= n; ++i)
        t[k][i] = min(t[k - 1][i], t[k - 1][i + (1 << (k - 1))]);
    }
  }
  T fold(int l, int r) const {
    assert(l < r);
    int k = __lg(r - l);
    return min(t[k][l], t[k][r - (1 << k)]);
  }
};

template <class S> vector<int> build_sa(const S& s) {
  int n = s.size();
  vector<int> sa(n), id(begin(s), end(s)), buf(n);
  iota(rbegin(sa), rend(sa), 0);
  stable_sort(begin(sa), end(sa), [&](int i, int j) { return s[i] < s[j]; });
  for (int m = 1; m < n; m *= 2) {
    for (int k = 0; k < n; ++k) {
      int i = sa[k], p = k ? sa[k - 1] : n, j = i + m / 2, q = p + m / 2;
      buf[i] = p + m < n and id[i] == id[p] and id[j] == id[q] ? buf[p] : k;
    }
    swap(id, buf);
    iota(begin(buf), end(buf), 0);
    auto nsa = sa;
    for (int k = 0, i; k < n; ++k)
      if ((i = sa[k] - m) >= 0) nsa[buf[id[i]]++] = i;
    swap(sa, nsa);
  }
  return sa;
}

template <class S> struct suffix_array {
  const S s;
  const int n;
  vector<int> sa, rank, h;
  suffix_array(const S& _s = S()) : s(_s), n(s.size()), rank(n), h(n) {
    sa = build_sa(s);
    for (int k = 0; k < n; ++k) rank[sa[k]] = k;
    for (int i = 0, m = 0; i < n; ++i, m = max(m - 1, 0)) {
      int j = rank[i] + 1 < n ? sa[rank[i] + 1] : n;
      while (max(i, j) + m < n and s[i + m] == s[j + m]) ++m;
      h[rank[i]] = m;
    }
  }
  int lcp(int i, int j) const {
    static sparse_table<int> st(h);
    if (i == j) return n - i;
    if (rank[i] > rank[j]) swap(i, j);
    return st.fold(rank[i], rank[j]);
  }
  int cmp(int i, int j, int len) const {
    int m = lcp(i, j);
    return m < len ? s[i + m] - s[j + m] : 0;
  }
};

template <typename T>
class graph {
  public:
  struct edge {
    int from;
    int to;
    T cost;
  };
  vector<edge> edges;
  vector< vector<int> > g;
  int n;
  function<bool(int)> ignore;
  graph(int _n) : n(_n) {
    g.resize(n);
    ignore = nullptr;
  }
  virtual int add(int from, int to, T cost) = 0;
  virtual void set_ignore_edge_rule(const function<bool(int)> &f) {
    ignore = f;
  }
  virtual void reset_ignore_edge_rule() {
    ignore = nullptr;
  }
};

template <typename T>
class digraph : public graph<T> {
  public:
  using graph<T>::edges;
  using graph<T>::g;
  using graph<T>::n;
  using graph<T>::ignore;
  digraph(int _n) : graph<T>(_n) {
  }
  int add(int from, int to, T cost = 1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int) edges.size();
    g[from].push_back(id);
    edges.push_back({from, to, cost});
    return id;
  }
  digraph<T> reverse() const {
    digraph<T> rev(n);
    for (auto &e : edges) {
      rev.add(e.to, e.from, e.cost);
    }
    if (ignore != nullptr) {
      rev.set_ignore_edge_rule([&](int id) {
        return ignore(id);
      });
    }
    return rev;
  }
};

template <typename T>
vector<int> find_scc(const digraph<T> &g, int &cnt) {
  digraph<T> g_rev = g.reverse();
  vector<int> order;
  vector<bool> was(g.n, false);
  function<void(int)> dfs1 = [&](int v) {
    was[v] = true;
    for (int id : g.g[v]) {
      if (g.ignore != nullptr && g.ignore(id)) {
        continue;
      }
      auto &e = g.edges[id];
      int to = e.to;
      if (!was[to]) {
        dfs1(to);
      }
    }
    order.push_back(v);
  };
  for (int i = 0; i < g.n; i++) {
    if (!was[i]) {
      dfs1(i);
    }
  }
  vector<int> c(g.n, -1);
  function<void(int)> dfs2 = [&](int v) {
    for (int id : g_rev.g[v]) {
      if (g_rev.ignore != nullptr && g_rev.ignore(id)) {
        continue;
      }
      auto &e = g_rev.edges[id];
      int to = e.to;
      if (c[to] == -1) {
        c[to] = c[v];
        dfs2(to);
      }
    }
  };
  cnt = 0;
  for (int id = g.n - 1; id >= 0; id--) {
    int i = order[id];
    if (c[i] != -1) {
      continue;
    }
    c[i] = cnt++;
    dfs2(i);
  }
  return c;
  // c[i] <= c[j] for every edge i -> j
}

class twosat {
  public:
  digraph<int> g;
  int n;
  twosat(int _n) : g(digraph<int>(2 * _n)), n(_n) {
  }
  inline void add(int x, int value_x) {
    // (v[x] == value_x)
    assert(0 <= x && x < n);
    assert(0 <= value_x && value_x <= 1);
    g.add(2 * x + (value_x ^ 1), 2 * x + value_x);
  }
  
  inline void add(int x, int value_x, int y, int value_y) {
    // (v[x] == value_x || v[y] == value_y)
    assert(0 <= x && x < n && 0 <= y && y < n);
    assert(0 <= value_x && value_x <= 1 && 0 <= value_y && value_y <= 1);
    g.add(2 * x + (value_x ^ 1), 2 * y + value_y);
    g.add(2 * y + (value_y ^ 1), 2 * x + value_x);
  }
  inline vector<int> solve() {
    int cnt;
    vector<int> c = find_scc(g, cnt);
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
      if (c[2 * i] == c[2 * i + 1]) {
        return vector<int>();
      }
      res[i] = (c[2 * i] < c[2 * i + 1]);
    }
    return res;
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> head(n + 1, 0), s;
  for (int i = 0; i < n; ++i) {
    int l;
    cin >> l;
    head[i + 1] = head[i] + l;
    while (l--) {
      int a;
      cin >> a;
      --a;
      s.push_back(a);
    }
  }
  suffix_array sa(s);
  twosat ts(m);
  for (int i = 0; i < n - 1; ++i) {
    int l = sa.lcp(head[i], head[i + 1]);
    if (l >= head[i + 1] - head[i]) {
      continue;
    }
    if (l >= head[i + 2] - head[i + 1]) {
      cout << "No\n";
      exit(0);
    }
    int x = s[head[i] + l], y = s[head[i + 1] + l];
    assert(x != y);
    if (x < y) {
      ts.add(x, 1, y, 0);
    } else {
      ts.add(x, 1);
      ts.add(y, 0);
    }
  }
  auto v = ts.solve();
  if (empty(v)) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
    vector<int> res;
    for (int i = 0; i < m; ++i) {
      if (v[i]) {
        res.push_back(i);
      }
    }
    int sz = size(res);
    cout << sz << '\n';
    for (int i = 0; i < sz; ++i) {
      cout << res[i] + 1 << " \n"[i == sz - 1];
    }
  }
}