#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;
const int M = 1000000007;

void solve() {
  int n, m, x;
  cin >> n >> m >> x;
  vector<int> H(n);
  for (int i = 0; i < n; i++) cin >> H[i];
  set<pair<int, int>> bb;
  for (int w = 1; w <= m; w++) {
    bb.insert({0, w});
  }
  cout << "YES\n";
  for (auto y : H) {
    pair<int, int> p = *bb.begin();
    bb.erase(p);
    cout << p.second << ' ';
    p.first += y;
    bb.insert(p);
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