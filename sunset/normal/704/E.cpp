#include <bits/stdc++.h>

using namespace std;

struct frac {
  long long num, den;

  frac(long long x = 0, long long y = 1)  {
    long long g = abs(__gcd(x, y));
    if (y < 0) {
      g = -g;
    }
    num = x / g;
    den = y / g;
  }

  frac operator-() const {
    return frac(-num, den);
  }

  frac operator+(const frac& o) const {
    return frac(num * o.den + den * o.num, den * o.den);
  }

  frac operator-(const frac& o) const {
    return frac(num * o.den - den * o.num, den * o.den);
  }

  frac operator*(const frac& o) const {
    return frac(num * o.num, den * o.den);
  }

  frac operator/(const frac& o) const {
    return frac(num * o.den, den * o.num);
  }

  bool operator<(const frac& o) const {
    return num * o.den < den * o.num;
  }

  bool operator==(const frac& o) const {
    return num * o.den == den * o.num;
  }
};

const frac INF = 123456;

frac T;

struct event {
  frac a, b, l, r;

  bool operator<(const event& o) const {
    return make_tuple(a * T + b, a, b, l, r) < make_tuple(o.a * T + o.b, o.a, o.b, o.l, o.r);
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
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int v, u;
    cin >> v >> u;
    --v; --u;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  vector<int> depth(n);
  vector<int> pr(n, -1);
  vector<int> sz(n, 1);
  function<void(int)> dfs = [&](int v) {
    for (int u : g[v]) {
      if (u != pr[v]) {
        pr[u] = v;
        depth[u] = depth[v] + 1;
        dfs(u);
        sz[v] += sz[u];
      }
    }
  };
  dfs(0);
  vector<int> top(n);
  function<void(int, int)> hld = [&](int v, int c) {
    top[v] = c;
    int son = -1;
    for (int u : g[v]) {
      if (u != pr[v] && (son == -1 || sz[u] > sz[son])) {
        son = u;
      }
    }
    if (son != -1) {
      hld(son, c);
      for (int u : g[v]) {
        if (u != pr[v] && u != son) {
          hld(u, u);
        }
      }
    }
  };
  hld(0, 0);
  auto lca = [&](int v, int u) {
    while (top[v] != top[u]) {
      if (depth[top[v]] >= depth[top[u]]) {
        v = pr[top[v]];
      } else {
        u = pr[top[u]];
      }
    }
    return depth[v] <= depth[u] ? v : u;
  };
  vector<vector<event>> foo(n), bar(n);
  while (m--) {
    frac s, c;
    int v, u;
    cin >> s.num >> c.num >> v >> u;
    --v; --u;
    frac t = s + frac(depth[v] + depth[u] - depth[lca(v, u)] * 2) / c;
    while (top[v] != top[u]) {
      if (depth[top[v]] >= depth[top[u]]) {
        {
          frac new_s = s + frac(depth[v] - depth[top[v]]) / c;
          foo[top[v]].push_back({-c, frac(depth[v]) + c * s, s, new_s});
          s = new_s;
          v = top[v];
        }
        {
          frac new_s = s + frac(depth[v] - depth[pr[v]]) / c;
          bar[v].push_back({-c, frac(depth[v]) + c * s, s, new_s});
          s = new_s;
          v = pr[v];
        }
      } else {
        {
          frac new_t = t - frac(depth[u] - depth[top[u]]) / c;
          foo[top[u]].push_back({c, frac(depth[u]) - c * t, new_t, t});
          t = new_t;
          u = top[u];
        }
        {
          frac new_t = t - frac(depth[u] - depth[pr[u]]) / c;
          bar[u].push_back({c, frac(depth[u]) - c * t, new_t, t});
          t = new_t;
          u = pr[u];
        }
      }
    }
    if (depth[v] > depth[u]) {
      foo[top[v]].push_back({-c, frac(depth[v]) + c * s, s, t});
    } else {
      foo[top[u]].push_back({c, frac(depth[u]) - c * t, s, t});
    }
  }
  frac ans = INF;
  auto explode = [&](event x, event y) {
    if (x.a == y.a) {
      if (x.b == y.b) {
        return max(x.l, y.l);
      } else {
        return INF;
      }
    } else {
      frac t = (x.b - y.b) / (y.a - x.a);
      if (t < max(x.l, y.l) || min(x.r, y.r) < t) {
        return INF;
      } else {
        return t;
      }
    }
  };
  auto solve = [&](vector<event> v) {
    int n = v.size();
    vector<int> ord(n * 2);
    for (int i = 0; i < n * 2; ++i) {
      ord[i] = i;
    }
    sort(ord.begin(), ord.end(), [&](int x, int y) {
      frac xx = x < n ? v[x].l : v[x - n].r;
      frac yy = y < n ? v[y].l : v[y - n].r;
      return make_pair(xx, x) < make_pair(yy, y);
    });
    multiset<event> st;
    for (int i : ord) {
      if (i < n) {
        T = v[i].l;
        if (!(T < ans)) {
          return;
        }
        auto it = st.insert(v[i]);
        if (it != st.begin()) {
          ans = min(ans, explode(v[i], *prev(it)));
        }
        if (it != --st.end()) {
          ans = min(ans, explode(v[i], *next(it)));
        }
      } else {
        i -= n;
        T = v[i].r;
        if (!(T < ans)) {
          return;
        }
        auto it = st.lower_bound(v[i]);
        if (it != st.begin() && it != --st.end()) {
          ans = min(ans, explode(*prev(it), *next(it)));
        }
        st.erase(it);
      }
    }
  };
  for (int i = 0; i < n; ++i) {
    solve(foo[i]);
    solve(bar[i]);
  }
  if (ans < INF) {
    cout << fixed << setprecision(9) << (double) ans.num / ans.den << "\n";
  } else {
    cout << -1 << "\n";
  }
  return 0;
}