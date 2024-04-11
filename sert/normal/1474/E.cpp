#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> v;
  ll ans = 0;
  vector<int> a(n);
  iota(a.begin(), a.end(), 1);
  for (int i = 1; i + 1 < n; i++) {
    if (i < n / 2) v.emplace_back(i, n - 1);
    else v.emplace_back(i, 0);
  }
  v.emplace_back(0, n - 1);
  for (int i = n - 2; i >= 0; i--) {
    swap(a[v[i].first], a[v[i].second]);
    ll x = abs(v[i].first - v[i].second);
    ans += x * x;
  }
  cout << ans << "\n";
  for (int x : a) cout << x << " ";
  cout << "\n" << n - 1 << "\n";
  for (auto &[v1, v2] : v) cout << v1 + 1 << " " << v2 + 1 << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
}