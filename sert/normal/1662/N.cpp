#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> pos(n * n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int x;
      cin >> x;
      pos[x - 1] = {i, j};
    }
  }

  vector<int> numR(n, 0), numC(n, 0);
  long long ans = 0;

  for (const auto &[y, x] : pos) {
    ans += numR[y] * (n - numC[x] - 1);
    numR[y]++;
    numC[x]++;
  }

  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef SERT
  freopen("../a.in", "r", stdin);
  solve();
  solve();
  solve();
#else
  solve();
#endif
}