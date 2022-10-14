#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;

void solve() {
  int n, r1, c1, r2, c2, r3, c3;
  cin >> n >> r1 >> c1 >> r2 >> c2 >> r3 >> c3;
  vector<int> r = {r1, r2, r3}, c = {c1, c2, c3};
  sort(all(r));
  sort(all(c));
  int R = r[1], C = c[1];
  int x, y;
  cin >> x >> y;
  if ((R == 1 || R == n) && (C == 1 || C == n)) {
    if (x == R || y == C) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
    return;
  }
  if ((x + y) % 2 != (R + C) % 2) {
    cout << "YES\n";
    return;
  }
  if (x % 2 == R % 2 && y % 2 == C % 2) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
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