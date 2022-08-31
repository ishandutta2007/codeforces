#include <bits/stdc++.h>

using namespace std;

const int md = 998244353;

inline void add(int &x, int y) {
  x += y;
  if (x >= md) {
    x -= md;
  }
}

inline void sub(int &x, int y) {
  x -= y;
  if (x < 0) {
    x += md;
  }
}

inline int mul(int x, int y) {
  return (long long)x * y % md;
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  vector<int> f(n), g(n), size(n), power(n);
  power[0] = 1;
  for (int i = 1; i < n; ++i) {
    power[i] = mul(power[i - 1], 2);
  }
  int answer = mul(n, power[n - 1]);
  
  function<void(int, int)> dfs = [&](int x, int parent) {
    size[x] = 1;
    f[x] = 1;
    for (auto y : adj[x]) {
      if (y != parent) {
        dfs(y, x);
        size[x] += size[y];
        g[x] = mul(g[x], mul(2, f[y] + g[y]));
        add(g[x], mul(f[x], f[y]));
        f[x] = mul(f[x], f[y] + mul(2, g[y]));
      }
    }
    sub(answer, mul(f[x], power[n - size[x]]));
  };

  dfs(0, -1);
  answer = mul(answer, 2);
  cout << answer << endl;
  return 0;
}