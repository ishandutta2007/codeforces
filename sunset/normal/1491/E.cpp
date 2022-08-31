#include <bits/stdc++.h>

using namespace std;

const int K = 27;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> fib(K);
  fib[0] = fib[1] = 1;
  for (int i = 2; i < K; ++i) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }
  int who = -1;
  for (int i = 1; i < K; ++i) {
    if (fib[i] == n) {
      who = i;
      break;
    }
  }
  if (who == -1) {
    cout << "NO" << "\n";
    return 0;
  }
  vector<set<int>> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int v, u;
    cin >> v >> u;
    --v; --u;
    g[v].insert(u);
    g[u].insert(v);
  }
  vector<int> s(n);
  vector<int> p(n);
  function<void(int, int)> solve = [&](int v, int k) {
    if (k <= 3) {
      return;
    }
    int r = -1;
    function<void(int)> dfs = [&](int v) {
      s[v] = 1;
      for (int u : g[v]) {
        if (u != p[v]) {
          p[u] = v;
          dfs(u);
          s[v] += s[u];
        }
      }
      if (s[v] == fib[k - 1] || s[v] == fib[k - 2]) {
        r = v;
      }
    };
    p[v] = -1;
    dfs(v);
    if (r == -1) {
      cout << "NO" << "\n";
      exit(0);
    }
    g[r].erase(p[r]);
    g[p[r]].erase(r);
    if (s[r] == fib[k - 1]) {
      solve(p[r], k - 2);
      solve(r, k - 1);
    } else {
      solve(p[r], k - 1);
      solve(r, k - 2);
    }
  };
  solve(0, who);
  cout << "YES" << "\n";
  return 0;
}