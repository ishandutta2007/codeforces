#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<map<int, int>> cnt(2);
  ++cnt[0][0];
  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    sum ^= x;
    ++cnt[i % 2][sum];
  }
  long long ans = 0;
  for (int i = 0; i < 2; ++i) {
    for (auto p : cnt[i]) {
      ans += (long long) p.second * (p.second - 1) / 2;
    }
  }
  cout << ans << "\n";
  return 0;
}