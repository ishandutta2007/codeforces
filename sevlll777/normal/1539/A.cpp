#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;

void solve() {
  int n, x, t;
  cin >> n >> x >> t;
  if (t < x) {
    cout << 0;
  } else {
    int d = t / x;
    if (d >= n) {
      cout << n * (n - 1) / 2;
    } else {
      cout << d * (d + 1) / 2 + d * (n - d - 1);
    }
  }

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