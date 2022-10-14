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
  vector<int> A(n+2);
  for (int i = 1; i <= n; i++) cin >> A[i];
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    ans += abs(A[i]-A[i+1]);
  }
  for (int i = 1; i <= n; i++) {
    if (A[i] >= max(A[i-1], A[i+1])) {
      ans -= (A[i] - max(A[i-1], A[i+1]));
    }
  }
  cout << ans << '\n';
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