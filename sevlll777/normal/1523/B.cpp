#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;

void f(int a, int b, int c) {
  cout << a << ' ' << b << ' ' << c << '\n';
}

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++) cin >> A[i];
  cout << 6 * (n / 2) << '\n';
  for (int i = 1; i <= n; i += 2) {
    f(1, i, i + 1);
    f(2, i, i + 1);
    f(1, i, i + 1);
    f(1, i, i + 1);
    f(2, i, i + 1);
    f(1, i, i + 1);
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