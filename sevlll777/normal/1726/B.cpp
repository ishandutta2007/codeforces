#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  if (m < n) {
    cout << "NO\n";
  } else if (n % 2 == 1) {
    cout << "Yes\n";
    for (int _ = 0; _ < n - 1; _++) {
      cout << "1 ";
    }
    cout << m - (n - 1) << '\n';
  } else {
    if (m % 2 == 0) {
      cout << "Yes\n";
      for (int _ = 0; _ < n - 2; _++) {
        cout << "1 ";
      }
      cout << (m - (n - 2)) / 2 << ' ' << (m - (n - 2)) / 2 << '\n';
    } else {
      cout << "NO\n";
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