#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  set<int> vacant;
  for (int i = 1; i <= n; i++) {
    vacant.insert(i);
  }
  vector<int> ans(n + 1);
  for (int i = 0; i < n - 1; i++) {
    if (a[i] > a[i + 1]) {
      int d = a[i] - a[i + 1];
      while (!vacant.empty() && *vacant.rbegin() < d) {
        int w = *vacant.rbegin();
        ans[w] = i + 1;
        d -= w;
      }
      int x = *vacant.lower_bound(d);
      ans[x] = i + 1;
      vacant.erase(x);
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] + 1 << ' ';
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