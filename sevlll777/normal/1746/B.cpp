#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;

void solve() {
  int n ;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int s = 0;
  for (auto x : a) s += x;
  int c = 0;
  int z = n - s;
  int ans = min(s, z);
  for (int i = 0; i < n; i++) {
    c += (a[i] == 1);
    z -= (a[i] == 0);
    ans = min(ans, max(c, z));
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