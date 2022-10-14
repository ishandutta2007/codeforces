#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;

void solve() {
  int n, k, x;
  cin >> n >> k >> x;
  vector<int> A(n);
  for (int i = 0; i < n; i++) cin >> A[i];
  sort(all(A));
  int cnt = 1;
  vector<int> lol;
  for (int i = 0; i < n - 1; i++) {
    int d = A[i + 1] - A[i];
    if (d > x) {
      lol.pb((d-1)/x);
      cnt++;
    }
  }
  sort(all(lol));
  for (auto x : lol) {
    if (k >= x) {
      cnt--;
      k -= x;
    }
  }
  cout << cnt << '\n';
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