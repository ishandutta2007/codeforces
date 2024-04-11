#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;
const int M = 1000000007;

void solve() {
  int n, x;
  cin >> n >> x;
  vector<int> W(n);
  for (int i = 0; i < n; i++) cin >> W[i];
  set<int> w;
  for (auto xx : W) w.insert(xx);
  vector<int> ans;
  int now = 0;
  while (!w.empty()) {
    if (w.size() == 1 && now+*w.begin() == x) {
      cout << "NO\n";
      return;
    }
    int a = *w.begin();
    w.erase(a);
    if (now + a != x) {
      ans.pb(a);
      now += a;
    } else {
      int b = *w.begin();
      w.erase(b);
      ans.pb(b);
      now += b;
      w.insert(a);
    }
  }
  cout << "YES\n";
  for (auto xx : ans) cout << xx << ' ';
  cout << '\n';

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