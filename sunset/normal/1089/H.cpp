#include <bits/stdc++.h>

using namespace std;

bool solve() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<int> from(m), to(m);
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    if (x < 0) {
      x = n - x;
    }
    if (y < 0) {
      y = n - y;
    }
    --x;
    --y;
    from[i] = x;
    to[i] = y;
    if (from[i] > to[i]) {
      swap(from[i], to[i]);
    }
  }
  auto get_another = [&](int x) {
    return x >= n ? x - n : x + n;
  };
  vector<vector<int>> adj(n << 1);
  for (int i = 0; i < m; ++i) {
    adj[get_another(from[i])].push_back(to[i]);
    adj[get_another(to[i])].push_back(from[i]);
  }
  vector<int> dfn(n << 1, -1), low(n << 1, -1), scc(n << 1, -1);
  stack<int> st;
  int cc = 0, tt = 0;
  function<void(int)> tarjan = [&](int x) {
    dfn[x] = low[x] = tt++;
    st.push(x);
    for (auto y : adj[x]) {
      if (!~dfn[y]) {
        tarjan(y);
        low[x] = min(low[x], low[y]);
      } else if (!~scc[y]) {
        low[x] = min(low[x], dfn[y]);
      }
    }
    if (dfn[x] == low[x]) {
      for (int t = -1; t != x; ) {
        t = st.top();
        scc[t] = cc;
        st.pop();
      }
      ++cc;
    }
  };
  for (int i = 0; i < n << 1; ++i) {
    if (!~dfn[i]) {
      tarjan(i);
    }
  }
  for (int i = 0; i < n; ++i) {
    if (scc[i] == scc[i + n]) {
      return false;
    }
  }
  vector<bool> ban_scc(cc);
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'E') {
      ban_scc[scc[i]] = ban_scc[scc[i + n]] = true;
    } else {
      if (ban_scc[scc[i]] || ban_scc[scc[i + n]]) {
        return false;
      }
    }
  }
  for (int i = 0; i < cc; ++i) {
    ban_scc[i] = false;
  }
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'A') {
      if (ban_scc[scc[i]]) {
        return false;
      }
      ban_scc[scc[i]] = true;
      if (ban_scc[scc[i + n]]) {
        return false;
      }
      ban_scc[scc[i + n]] = true;
    }
  }
  vector<bool> can(cc);
  vector<vector<int>> graph(cc);
  for (int x = 0; x < n << 1; ++x) {
    for (auto y : adj[x]) {
      if (scc[x] != scc[y]) {
        graph[scc[x]].push_back(scc[y]);
      }
    }
  }
  for (int x = 0; x < cc; ++x) {
    for (auto y : graph[x]) {
      if (can[y] || ban_scc[y]) {
        can[x] = true;
      }
    }
    if (can[x] && ban_scc[x]) {
      return false;
    }
  }
  return true;
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    puts(solve() ? "TRUE" : "FALSE");
  }
  return 0;
}