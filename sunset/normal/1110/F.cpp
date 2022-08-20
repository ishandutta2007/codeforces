#include <bits/stdc++.h>

using namespace std;

const long long inf = 1ll << 60;

class node {
 public:
  long long value = 0;
  long long tag = 0;
  
  inline void apply(int l, int r, long long v) {
    value += v;
    tag += v;
  }
};

class segtree {
 public:
  vector<node> tree;
  int n;

  inline node unite(const node &l, const node &r) {
    node res;
    res.value = min(l.value, r.value);
    return res;
  }

  segtree(int n): n(n) {
    tree.resize(n * 2 - 1);
  }

  inline void pull(int x, int z) {
    tree[x] = unite(tree[x + 1], tree[z]);
  }

  inline void push(int x, int l, int r) {
    int y = l + r >> 1, z = x + (y - l + 1 << 1);
    if (tree[x].tag) {
      tree[x + 1].apply(l, y, tree[x].tag);
      tree[z].apply(y + 1, r, tree[x].tag);
      tree[x].tag = 0;
    }
  }

  void build(int x, int l, int r) {
    if (l != r) {
      int y = l + r >> 1, z = x + (y - l + 1 << 1);
      build(x + 1, l, y);
      build(z, y + 1, r);
      pull(x, z);
    }
  }

  template<typename T>
  void build(int x, int l, int r, const vector<T> &v) {
    if (l == r) {
      tree[x].apply(l, r, v[l]);
    } else {
      int y = l + r >> 1, z = x + (y - l + 1 << 1);
      build(x + 1, l, y, v);
      build(z, y + 1, r, v);
      pull(x, z);
    }
  }

  template<typename... T>
  void modify(int x, int l, int r, int ll, int rr, const T&... v) {
    if (ll <= l && r <= rr) {
      tree[x].apply(l, r, v...);
    } else {
      int y = l + r >> 1, z = x + (y - l + 1 << 1);
      push(x, l, r);
      if (ll <= y) {
        modify(x + 1, l, y, ll, rr, v...);
      }
      if (rr > y) {
        modify(z, y + 1, r, ll, rr, v...);
      }
      pull(x, z);
    }
  }

  node query(int x, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
      return tree[x];
    } else {
      int y = l + r >> 1, z = x + (y - l + 1 << 1);
      push(x, l, r);
      if (rr <= y) {
        return query(x + 1, l, y, ll, rr);
      } else if (ll > y) {
        return query(z, y + 1, r, ll, rr);
      } else {
        return unite(query(x + 1, l, y, ll, rr), query(z, y + 1, r, ll, rr));
      }
    }
  }

  void build() {
    build(0, 0, n - 1);
  }

  template<typename T>
  void build(const vector<T> &v) {
    build(0, 0, n - 1, v);
  }

  template<typename... T>
  void modify(int l, int r, const T&... v) {
    modify(0, 0, n - 1, l, r, v...);
  }

  node query(int l, int r) {
    return query(0, 0, n - 1, l, r);
  }
};

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> p(n), w(n);
  vector<long long> dist(n);
  vector<bool> leaf(n, true);
  vector<vector<pair<int, int>>> adj(n);
  for (int i = 1; i < n; ++i) {
    cin >> p[i] >> w[i];
    --p[i];
    leaf[p[i]] = false;
    dist[i] = dist[p[i]] + w[i];
    adj[p[i]].emplace_back(i, w[i]);
  }
  for (int i = 0; i < n; ++i) {
    if (!leaf[i]) {
      dist[i] = inf;
    }
  }
  segtree seg(n);
  seg.build(dist);
  vector<vector<tuple<int, int, int>>> events(n);
  vector<long long> ans(q);
  for (int i = 0; i < q; ++i) {
    int v, l, r;
    cin >> v >> l >> r;
    --v;
    --l;
    --r;
    events[v].emplace_back(l, r, i);
  }
  vector<int> low(n), high(n);
  function<void(int)> dfs = [&](int x) {
    low[x] = high[x] = x;
    for (auto p : adj[x]) {
      int y = p.first;
      dfs(y);
      low[x] = min(low[x], low[y]);
      high[x] = max(high[x], high[y]);
    }
  };
  dfs(0);
  long long now = 0;
  function<void(int)> solve = [&](int x) {
    for (auto p : events[x]) {
      ans[get<2>(p)] = seg.query(get<0>(p), get<1>(p)).value + now;
    }
    for (auto p : adj[x]) {
      int y = p.first;
      now += p.second;
      seg.modify(low[y], high[y], -2 * p.second);
      solve(y);
      seg.modify(low[y], high[y], 2 * p.second);
      now -= p.second;
    }
  };
  solve(0);
  for (int i = 0; i < q; ++i) {
    cout << ans[i] << "\n";
  }
  return 0;
}