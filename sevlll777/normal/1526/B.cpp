#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;

void solve() {
  int x;
  cin >> x;
  if (x % 11 == 0) {
    cout << "YES\n";
  } else {
    int r = x % 11;
    if (x < 111 * r) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
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