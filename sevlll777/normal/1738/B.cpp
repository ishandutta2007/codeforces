#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> s(k);
  for (int i = 0; i < k; i++) {
    cin >> s[i];
  }
  if (k == 1) {
    cout << "YES\n";
    return;
  }
  vector<int> a;
  for (int i = 1; i < k; i++) {
    a.pb(s[i] - s[i - 1]);
  }
  int kek = s[0];
  int el = n - k + 1;
  if (a[0] * el >= kek && is_sorted(all(a))) {
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