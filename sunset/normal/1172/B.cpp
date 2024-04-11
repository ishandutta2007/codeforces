#include <bits/stdc++.h>

using namespace std;

const int md = 998244353;

inline int mul(int x, int y) {
  return (int) ((long long) x * y % md);
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> fact(n);
  fact[0] = 1;
  for (int i = 1; i < n; ++i) {
    fact[i] = mul(fact[i - 1], i);
  }
  vector<int> degree(n);
  for (int i = 0; i < n - 1; ++i) {
    int from, to;
    cin >> from >> to;
    --from;
    --to;
    ++degree[from];
    ++degree[to];
  }
  int ans = n;
  for (int i = 0; i < n; ++i) {
    ans = mul(ans, fact[degree[i]]);
  }
  cout << ans << "\n";
  return 0;
}