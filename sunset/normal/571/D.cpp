#include <bits/stdc++.h>

using namespace std;

template <typename T>
class fenwick {
 public:
  vector<T> fenw;
  int n;

  fenwick(int n) : n(n) {
    fenw.resize(n);
  }

  void modify(int x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= x + 1;
    }
  }

  T query(int x) {
    T res{};
    while (x >= 0) {
      res += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return res;
  }
};

struct tree {
  vector<int> l;
  vector<int> r;
  vector<int> s;
  vector<int> p;
  int n;

  tree(int n) : n(n) {
    l.assign(n, -1);
    r.assign(n, -1);
    s.assign(n, 1);
    p.resize(n);
    for (int i = 0; i < n; ++i) {
      p[i] = i;
    }
  }

  int find(int v) {
    while (v != p[v]) {
      v = p[v] = p[p[v]];
    }
    return v;
  }

  bool unite(int v, int u) {
    v = find(v); u = find(u);
    if (v == u) {
      return false;
    }
    l.push_back(v);
    r.push_back(u);
    s.push_back(s[v] + s[u]);
    p.push_back(n);
    p[v] = p[u] = n++;
    return true;
  }
};

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  tree foo(n), bar(n);
  vector<vector<int>> modify_foo(n * 2 - 1);
  vector<vector<int>> modify_bar(n * 2 - 1);
  vector<vector<int>> query(n);
  vector<long long> ans(m, -1);
  for (int i = 0; i < m; ++i) {
    string type;
    cin >> type;
    if (type == "U") {
      int v, u;
      cin >> v >> u;
      foo.unite(--v, --u);
    } else if (type == "M") {
      int v, u;
      cin >> v >> u;
      bar.unite(--v, --u);
    } else if (type == "A") {
      int v;
      cin >> v;
      modify_foo[foo.find(--v)].push_back(i);
    } else if (type == "Z") {
      int v;
      cin >> v;
      modify_bar[bar.find(--v)].push_back(i);
    } else {
      int v;
      cin >> v;
      query[--v].push_back(i);
    }
  }
  set<int> st;
  st.insert(-1);
  function<void(int)> dfs_bar = [&](int v) {
    for (int i : modify_bar[v]) {
      st.insert(i);
    }
    if (v >= n) {
      dfs_bar(bar.l[v]); dfs_bar(bar.r[v]);
    } else {
      for (int i : query[v]) {
        ans[i] = *--st.lower_bound(i);
      }
    }
    for (int i : modify_bar[v]) {
      st.erase(i);
    }
  };
  for (int i = 0; i < bar.n; ++i) {
    if (bar.p[i] == i) {
      dfs_bar(i);
    }
  }
  fenwick<long long> fenw(m);
  function<void(int)> dfs_foo = [&](int v) {
    for (int i : modify_foo[v]) {
      fenw.modify(i, foo.s[v]);
    }
    if (v >= n) {
      dfs_foo(foo.l[v]); dfs_foo(foo.r[v]);
    } else {
      for (int i : query[v]) {
        ans[i] = fenw.query(i) - fenw.query(ans[i]);
      }
    }
    for (int i : modify_foo[v]) {
      fenw.modify(i, -foo.s[v]);
    }
  };
  for (int i = 0; i < foo.n; ++i) {
    if (foo.p[i] == i) {
      dfs_foo(i);
    }
  }
  for (int i = 0; i < m; ++i) {
    if (ans[i] != -1) {
      cout << ans[i] << "\n";
    }
  }
  return 0;
}