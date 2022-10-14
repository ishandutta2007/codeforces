#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;
const int M = 1000000007;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  for (int i = 0; i < n; i++) cin >> A[i];
  int j = 0;
  while (j < n - 1 && A[j] == 0) j++;
  while (k--) {
    A[j]--;
    A[n - 1]++;
    if (j < n - 1 && A[j] == 0) {
      j++;
    }
  }
  for (auto x : A) cout << x << ' ';
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