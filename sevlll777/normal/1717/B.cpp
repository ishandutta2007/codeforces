#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;

void solve() {
  int n, k, r, c;
  cin >> n >> k >> r >> c;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if ((n + i % n + j % n - (r - 1) % n) % k == (n + (c - 1) % n) % k) {
        cout << "X";
      } else {
        cout << ".";
      }
    }
    cout << '\n';
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