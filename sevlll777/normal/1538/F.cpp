#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;

int kek(int x) {
  int ans = 0;
  for (int d = 1; d <= x; d *= 10) {
    ans += x / d;
  }
  return ans;
}

void solve() {
  int l, r;
  cin >> l >> r;
  cout << kek(r) - kek(l) << '\n';
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