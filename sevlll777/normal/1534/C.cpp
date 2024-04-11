#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;
const int M = 1000000007;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n), B(n);
  for (int i = 0; i < n; i++) cin >> A[i];
  for (int i = 0; i < n; i++) cin >> B[i];
  vector<vector<int>> g(n+1);
  for (int i = 0; i < n; i++) {
    g[A[i]].pb(B[i]);
    g[B[i]].pb(A[i]);
  }
  int ans = 1;
  vector<bool> used(n+1, false);
  for (int x = 1; x <= n; x++) {
    if (!used[x]) {
      used[x] = true;
      ans *= 2;
      ans %= M;
      vector<int> s = {x};
      while (!s.empty()) {
        int y = s.back();
        s.pop_back();
        for (auto uy : g[y]) {
          if (!used[uy]) {
            used[uy] = true;
            s.pb(uy);
          }
        }
      }
    }
  }
  cout << ans << '\n';
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