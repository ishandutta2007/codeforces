#include <bits/stdc++.h>
using namespace std;


void solve() {
  using ll = long long;
  int A, B, n;
  cin >> A >> B >> n;
  vector<int> a(n), b(n);
  for (int &x : a) cin >> x;
  for (int &x : b) cin >> x;

  int maxA = *max_element(a.begin(), a.end());
  ll tot = 0;
  for (int i = 0; i < n; i++)
    tot += (b[i] + A - 1) / A * 1ll * a[i];
  cout << (B - tot + maxA > 0 ? "YES" : "NO") << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  while (t--) solve();
}