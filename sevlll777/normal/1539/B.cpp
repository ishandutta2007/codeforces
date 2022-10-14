#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;

void solve() {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<int> p = {0};
  for (int i = 1; i <= n; i++) {
    p.pb((int) (1 + s[i - 1] - 'a') + p.back());
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << p[r] - p[l - 1] << '\n';
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  while (t--) {
    solve();
  }
}