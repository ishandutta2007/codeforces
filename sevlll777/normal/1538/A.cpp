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
  vector<int> A(n);
  int o = 0, oo = 0;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    if (A[i] == 1) {
      o = i;
    } else if (A[i] == n) {
      oo = i;
    }
  }
  if (o > oo) swap(o, oo);
  cout << min({oo + 1, n - o, o + n - oo + 1});

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