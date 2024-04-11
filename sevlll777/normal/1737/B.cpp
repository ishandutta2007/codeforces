#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;

int f(int x) {
  if (x == 0)return 0;
  int r = floor(sqrt(x));
  int ans = 3 * r - 2;
  int d = r;
  if (r * r + d <= x) ans++;
  if (r * r + 2 * d <= x) ans++;
  return ans;
}

void solve() {
  int l, r;
  cin >> l >> r;
  cout << f(r) - f(l - 1) << '\n';
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