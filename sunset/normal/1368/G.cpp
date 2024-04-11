#include <bits/stdc++.h>
 
using namespace std;
 
struct node {
  int val;
  int cnt;
  int tag;
 
  void apply(int l, int r, int w) {
    val += w;
    tag += w;
  }
};
 
class segtree {
 public:
  vector<node> tree;
  int n;
 
  node unite(const node &l, const node &r) {
    node res;
    res.val = min(l.val, r.val);
    res.cnt = 0;
    if (res.val == l.val) res.cnt += l.cnt;
    if (res.val == r.val) res.cnt += r.cnt;
    res.tag = 0;
    return res;
  }
 
  segtree(int n): n(n) {
    tree.resize(n * 2 - 1);
  }
 
  void pull(int x, int z) {
    tree[x] = unite(tree[x + 1], tree[z]);
  }
 
  void push(int x, int l, int r) {
    int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
    if (tree[x].tag) {
      tree[x + 1].apply(l, y, tree[x].tag);
      tree[z].apply(y + 1, r, tree[x].tag);
      tree[x].tag = 0;
    }
  }
 
  void build(int x, int l, int r) {
    if (l == r) {
      tree[x].cnt = 1;
    } else {
      int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
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
      int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
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
      int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
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
      int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
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
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> board(n);
  for (int i = 0; i < n; ++i) {
    cin >> board[i];
  }
  int N = n * m;
  vector<vector<int>> g(N);
  auto add = [&](int x, int y) {
    g[x].push_back(y);
    g[y].push_back(x);
  };
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (board[i][j] == 'L' && j + 2 < m) {
        add(i * m + j, i * m + (j + 2));
      }
      if (board[i][j] == 'R' && j - 2 >= 0) {
        add(i * m + j, i * m + (j - 2));
      }
      if (board[i][j] == 'U' && i + 2 < n) {
        add(i * m + j, (i + 2) * m + j);
      }
      if (board[i][j] == 'D' && i - 2 >= 0) {
        add(i * m + j, (i - 2) * m + j);
      }
    }
  }
  vector<int> p(N, -1);
  vector<int> dfn(N, -1);
  vector<int> sz(N, -1);
  vector<int> rt(N, -1);
  int t = 0;
  function<void(int)> dfs = [&](int x) {
    dfn[x] = t++;
    sz[x] = 1;
    for (int y : g[x]) {
      if (dfn[y] == -1) {
        p[y] = x;
        rt[y] = rt[x];
        dfs(y);
        sz[x] += sz[y];
      }
    }
  };
  for (int i = 0; i < N; ++i) {
    if (dfn[i] == -1) {
      rt[i] = i;
      dfs(i);
    }
  }
  vector<vector<pair<pair<int, int>, int>>> ev(N + 1);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (board[i][j] == 'L') {
        int x = i * m + j;
        int y = i * m + (j + 1);
        int bx = j + 2 < m ? i * m + (j + 2) : -1;
        int by = j - 1 >= 0 ? i * m + (j - 1) : -1;
        if (rt[x] > rt[y]) {
          swap(x, y);
          swap(bx, by);
        }
        vector<pair<int, int>> ix;
        vector<pair<int, int>> iy;
        if (bx == -1) {
          ix.emplace_back(dfn[rt[x]], dfn[rt[x]] + sz[rt[x]]);
        } else if (bx == p[x]) {
          ix.emplace_back(dfn[x], dfn[x] + sz[x]);
        } else {
          ix.emplace_back(dfn[rt[x]], dfn[bx]);
          ix.emplace_back(dfn[bx] + sz[bx], dfn[rt[x]] + sz[rt[x]]);
        }
        if (by == -1) {
          iy.emplace_back(dfn[rt[y]], dfn[rt[y]] + sz[rt[y]]);
        } else if (by == p[y]) {
          iy.emplace_back(dfn[y], dfn[y] + sz[y]);
        } else {
          iy.emplace_back(dfn[rt[y]], dfn[by]);
          iy.emplace_back(dfn[by] + sz[by], dfn[rt[y]] + sz[rt[y]]);
        }
        for (auto p : ix) {
          for (auto q : iy) {
            ev[p.first].push_back(make_pair(q, 1));
            ev[p.second].push_back(make_pair(q, -1));
          }
        }
      }
      if (board[i][j] == 'U') {
        int x = i * m + j;
        int y = (i + 1) * m + j;
        int bx = i + 2 < n ? (i + 2) * m + j : -1;
        int by = i - 1 >= 0 ? (i - 1) * m + j : -1;
        if (rt[x] > rt[y]) {
          swap(x, y);
          swap(bx, by);
        }
        vector<pair<int, int>> ix;
        vector<pair<int, int>> iy;
        if (bx == -1) {
          ix.emplace_back(dfn[rt[x]], dfn[rt[x]] + sz[rt[x]]);
        } else if (bx == p[x]) {
          ix.emplace_back(dfn[x], dfn[x] + sz[x]);
        } else {
          ix.emplace_back(dfn[rt[x]], dfn[bx]);
          ix.emplace_back(dfn[bx] + sz[bx], dfn[rt[x]] + sz[rt[x]]);
        }
        if (by == -1) {
          iy.emplace_back(dfn[rt[y]], dfn[rt[y]] + sz[rt[y]]);
        } else if (by == p[y]) {
          iy.emplace_back(dfn[y], dfn[y] + sz[y]);
        } else {
          iy.emplace_back(dfn[rt[y]], dfn[by]);
          iy.emplace_back(dfn[by] + sz[by], dfn[rt[y]] + sz[rt[y]]);
        }
        for (auto p : ix) {
          for (auto q : iy) {
            ev[p.first].push_back(make_pair(q, 1));
            ev[p.second].push_back(make_pair(q, -1));
          }
        }
      }
    }
  }
  segtree seg(N);
  seg.build(0, 0, N - 1);
  long long ans = 0;
  for (int i = 0; i < N; ++i) {
    for (auto p : ev[i]) {
      int l = p.first.first;
      int r = p.first.second - 1;
      int w = p.second;
      if (l <= r) {
        seg.modify(l, r, w);
      }
    }
    node res = seg.query(0, N - 1);
    ans += N - res.cnt;
  }
  cout << ans << "\n";
  return 0;
}