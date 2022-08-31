#include <bits/stdc++.h>

using namespace std;

const int MAX = 200000;

struct range {
  int l, r, c;
  
  bool operator<(const range& o) const {
    return r < o.r;
  }
};

struct dsu {
  int n;
  vector<int> p;
  vector<int> m;

  dsu(int n, vector<int> m) : n(n), m(m) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }

  int find(int v) {
    while (v != p[v]) {
      v = p[v] = p[p[v]];
    }
    return v;
  }

  void unite(int v, int u) {
    v = find(v);
    u = find(u);
    if (v != u) {
      p[v] = u;
      m[u] = max(m[u], m[v]);
    }
  }
};

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
  }
  vector<int> c(MAX), l(MAX, n), r(MAX, -1);
  for (int i = 0; i < n; ++i) {
    ++c[a[i]];
    l[a[i]] = min(l[a[i]], i);
    r[a[i]] = max(r[a[i]], i);
  }
  vector<range> b;
  for (int i = 0; i < MAX; ++i) {
    if (c[i] > 0) {
      b.push_back({l[i], r[i], c[i]});
    }
  }
  sort(b.begin(), b.end());
  int m = b.size();
  c.resize(m);
  for (int i = 0; i < m; ++i) {
    c[i] = b[i].c;
  }
  dsu d(m, c);
  stack<int> st;
  for (int i = 0; i < m; ++i) {
    while (!st.empty() && b[i].l <= b[st.top()].r) {
      b[i].l = min(b[i].l, b[st.top()].l);
      d.unite(i, st.top());
      st.pop();
    }
    st.push(i);
  }
  int ans = n;
  for (int i = 0; i < m; ++i) {
    if (d.find(i) == i) {
      ans -= d.m[i];
    }
  }
  cout << ans << "\n";
  return 0;
}