#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n), B(n);
  multiset<pair<int, int>> p;
  for (int i = 0; i < n; i++) {
    cin >> A[i] >> B[i];
    p.insert({B[i], A[i]});
  }
  int cup = 0, ans = 0;
  while (!p.empty()) {
    pair<int, int> a = *p.begin();
    if (cup >= a.first) {
      ans += a.second;
      cup += a.second;
      p.erase(p.find(a));
    } else {
      pair<int, int> b = *p.rbegin();
      int need = a.first - cup;
      if (b.second < need) {
        ans += 2 * b.second;
        cup += b.second;
        p.erase(p.find(b));
      } else {
        p.erase(p.find(b));
        cup += need;
        ans += 2 * need;
        b.second -= need;
        p.insert(b);
      }
    }
  }
  cout << ans << '\n';

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