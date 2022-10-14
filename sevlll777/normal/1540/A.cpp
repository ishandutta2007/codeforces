#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> D(n);
  for (int i = 0; i < n; i++) cin >> D[i];
  sort(all(D));
  vector<int> D2;
  for (int i = 1; i < n; i++) {
    D2.pb(D[i] - D[i - 1]);
  }
  int sum = 0;
  for (int i = 0; i < n - 1; i++) {
    sum += D2[i] * (i + 1) * (n - 1 - i);
  }
  cout << -sum + D.back() << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}