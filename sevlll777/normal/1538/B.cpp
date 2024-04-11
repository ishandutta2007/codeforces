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
  vector<int> A(n);
  int s = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    s += A[i];
  }
  if (s % n) {
    cout << "-1\n";
    return;
  }
  for (auto x : A) {
    if (x * n > s) {
      ans++;
    }
  }
  cout << ans;

  cout << '\n';
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