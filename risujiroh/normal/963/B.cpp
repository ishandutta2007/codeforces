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
  int n;
  cin >> n;
  vector<vector<int>> ch(n);
  int r = -1;
  for (int v = 0; v < n; ++v) {
    int p;
    cin >> p;
    --p;
    if (p == -1) {
      r = v;
    } else {
      ch[p].push_back(v);
    }
  }
  vector<array<bool, 2>> dp(n);
  vector<vector<int>> g(n);
  auto dfs = [&](auto&& self, int v) -> void {
    dp[v] = {true, false};
    for (int u : ch[v]) {
      self(self, u);
      array<bool, 2> ndp{false, false};
      for (int p : {0, 1}) {
        for (int q : {0, 1}) {
          if (dp[v][p] and dp[u][q]) {
            if (q % 2 == 0) {
              ndp[p ^ 1] = true;
              g[v].push_back(u);
            } else {
              ndp[p] = true;
              g[u].push_back(v);
            }
          }
        }
      }
      swap(dp[v], ndp);
    }
  };
  dfs(dfs, r);
  DEBUG(dp);
  if (dp[r][0]) {
    cout << "YES\n";
    vector<int> indeg(n);
    for (int v = 0; v < n; ++v) {
      for (int u : g[v]) {
        ++indeg[u];
      }
    }
    queue<int> que;
    for (int v = 0; v < n; ++v) {
      if (indeg[v] == 0) {
        que.push(v);
      }
    }
    while (not que.empty()) {
      int v = que.front();
      que.pop();
      cout << v + 1 << '\n';
      for (int u : g[v]) {
        if (--indeg[u] == 0) {
          que.push(u);
        }
      }
    }
  } else {
    cout << "NO\n";
  }
}