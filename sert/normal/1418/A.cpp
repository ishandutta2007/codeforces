#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  ll x, y, k;
  cin >> x >> y >> k;
  cout << (y * k + k + x - 3) / (x - 1) + k << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
}