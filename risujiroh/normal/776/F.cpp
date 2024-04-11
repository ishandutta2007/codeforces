#include <bits/stdc++.h>
using namespace std;

string to_string(string s) { return '"' + s + '"'; }
string to_string(bool b) { return b ? "true" : "false"; }
template <size_t N> string to_string(bitset<N> bs) {
  string res;
  for (size_t i = 0; i < N; ++i) res += '0' + bs[i];
  return res;
}
string to_string(vector<bool> v) {
  string res = "{";
  for (bool e : v) res += to_string(e) + ", ";
  return res += "}";
}
template <class T, class U> string to_string(pair<T, U> p);
template <class C> string to_string(C c) {
  string res = "{";
  for (auto e : c) res += to_string(e) + ", ";
  return res += "}";
}
template <class T, class U> string to_string(pair<T, U> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void debug() { cerr << '\n'; }
template <class Head, class... Tail> void debug(Head head, Tail... tail) {
  cerr << ' ' << to_string(head), debug(tail...);
}
#ifdef LOCAL
#define DEBUG(...) cerr << "[" << #__VA_ARGS__ << "]:", debug(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  struct edge {
    int from, to;
  };
  vector<edge> es(2 * m + n);
  vector<vector<int>> g(n);
  for (int i = 0; i < n; ++i) {
    es[2 * m + i] = {i, (i + 1) % n};
    g[i].push_back(2 * m + i);
  }
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    tie(u, v) = minmax({u, v});
    es[2 * i] = {u, v};
    es[2 * i + 1] = {v, u};
    g[u].push_back(2 * i);
    g[v].push_back(2 * i + 1);
  }
  for (int v = 0; v < n; ++v) {
    sort(begin(g[v]), end(g[v]), [&](int lid, int rid) {
      int lto = es[lid].to, rto = es[rid].to;
      if (lto < v) {
        lto += n;
      }
      if (rto < v) {
        rto += n;
      }
      return lto > rto;
    });
    DEBUG(v, g[v]);
  }
  vector<int> nxt(2 * m + n);
  for (int v = 0; v < n; ++v) {
    vector<int> t{2 * m + (v + n - 1) % n};
    for (int i = 0; i < (int)g[v].size(); ++i) {
      if (i == (int)g[v].size() - 1) {
        assert(g[v][i] == 2 * m + v);
        t.push_back(g[v][i]);
      } else {
        assert(g[v][i] < 2 * m);
        t.push_back(g[v][i]);
        t.push_back(g[v][i] ^ 1);
      }
    }
    for (int i = 0; i < (int)t.size(); i += 2) {
      nxt[t[i]] = t[i + 1];
    }
  }
  vector<bool> used(2 * m + n);
  vector<vector<int>> f;
  for (int id = 0; id < 2 * m + n; ++id) {
    if (used[id]) {
      continue;
    }
    int v = es[id].from, x = f.size(), i = id;
    f.emplace_back();
    while (true) {
      used[i] = true;
      f[x].push_back(v);
      v = es[i].to;
      i = nxt[i];
      if (i == id) {
        break;
      }
    }
    sort(rbegin(f.back()), rend(f.back()));
  }
  assert((int)f.size() == m + 1);
  sort(begin(f), end(f));
  DEBUG(f);
  map<pair<int, int>, int> mp;
  for (int id = 0; id < 2 * m + n; ++id) {
    mp[{es[id].from, es[id].to}] = id;
  }
  vector<int> id2x(2 * m + n);
  for (int x = 0; x < m + 1; ++x) {
    for (int i = 0; i < (int)f[x].size(); ++i) {
      id2x[mp[{f[x][(i + 1) % f[x].size()], f[x][i]}]] = x;
    }
  }
  vector<vector<int>> h(m + 1);
  for (int id = 0; id < 2 * m; ++id) {
    h[id2x[id]].push_back(id2x[id ^ 1]);
  }
  DEBUG(h);
  vector<bool> be(m + 1, true);
  vector<int> sz(m + 1), par(m + 1);
  auto cent = [&](int v) -> int {
    vector<int> vs;
    auto dfs = [&](auto&& self, int v, int p) -> void {
      vs.push_back(v);
      sz[v] = 1;
      par[v] = p;
      for (int u : h[v]) {
        if (be[u] and u != p) {
          self(self, u, v);
          sz[v] += sz[u];
        }
      }
    };
    dfs(dfs, v, -1);
    for (int v : vs) {
      bool ok = vs.size() - sz[v] <= vs.size() / 2;
      for (int u : h[v]) {
        if (be[u] and u != par[v]) {
          if (sz[u] > (int)vs.size() / 2) {
            ok = false;
            break;
          }
        }
      }
      if (ok) {
        return v;
      }
    }
    assert(false);
    return -1;
  };
  vector<int> res(m + 1);
  auto rec = [&](auto&& self, int v, int col) -> void {
    int c = cent(v);
    DEBUG(v, c);
    be[c] = false;
    res[c] = col;
    for (int u : h[c]) {
      if (be[u]) {
        self(self, u, col + 1);
      }
    }
    be[c] = true;
  };
  rec(rec, 0, 1);
  for (int i = 0; i <= m; ++i) {
    cout << res[i] << " \n"[i == m];
  }
}