#include <bits/stdc++.h>

using namespace std;

const int md = 998244353;

inline void add(int &x, int y) {
  x += y;
  if (x >= md) {
    x -= md;
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
  scanf("%d", &n);
  vector<vector<int>> adj(n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    --x;
    --y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  vector<int> free(n);
  vector<int> must(n);
  vector<int> done(n);
  function<void(int, int)> dfs = [&](int x, int parent) {
    free[x] = 1;
    for (auto y : adj[x]) {
      if (y != parent) {
        dfs(y, x);
        done[x] = mul(done[x], free[y] + mul(done[y], 2));
        add(done[x], mul(must[x], free[y] + must[y]));
        add(done[x], mul(free[x], free[y] + must[y]));
        must[x] = mul(must[x], free[y] + mul(done[y], 2));
        add(must[x], mul(free[x], done[y]));
        free[x] = mul(free[x], free[y] + done[y]);
      }
    }
  };
  dfs(0, -1);
  int answer = 0;
  add(answer, free[0]);
  add(answer, done[0]);
  printf("%d\n", answer);
  return 0;
}