#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;

int kek(vector<int> A, int x) {
  int ans = 0;
  sort(all(A));
  for (auto y : A) {
    int z = x - y;
    ans += (upper_bound(all(A), z) - A.begin());
    if (2 * y <= x) {
      ans--;
    }
  }
  ans /= 2;
  return ans;
}

void solve() {
  int n, l, r;
  cin >> n >> l >> r;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  cout << kek(A, r) - kek(A, l - 1) << '\n';
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