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
  vector<int> A(n);
  int x = 0;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    x ^= A[i];
  }
  if (x == 0) {
    cout << "Yes\n";
    return;
  }
  int y = 0;
  for (int i = 0; i < n; i++) {
    y ^= A[i];
    if (y == x) {
      int z = 0;
      for (int j = i + 1; j < n; j++) {
        z ^= A[j];
        if (z == x) {
          cout << "Yes\n";
          return;
        }
      }
    }
  }
  cout << "No\n";
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