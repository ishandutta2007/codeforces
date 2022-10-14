#include <bits/stdc++.h>

#define pb push_back
// #define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;
const int M = 1000000007;

void solve() {
  int n, l, r;
  cin >> n >> l >> r;
  vector<int> C(n);
  for (int i = 0; i < n; i++) cin >> C[i];
  map<int, int> A, B;
  for (int x = 0; x < n; x++) {
    if (x < l) {
      A[C[x]]++;
    } else {
      B[C[x]]++;
    }
  }
  if (l > n / 2) {
    swap(A, B);
  }
  int d = abs(l - r) / 2;
  for (auto p : A) {
    int x = p.first;
    int m = min(A[x], B[x]);
    A[x] -= m;
    B[x] -= m;
  }
  int ans = 0;
  for (auto &p : B) {
    int op = max(0, min(d, p.second / 2));
    d -= op;
    p.second -= 2 * op;
    ans += op;
    ans += p.second;
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