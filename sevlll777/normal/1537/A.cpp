#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    int s = 0;
    for (auto x : A) s += x;
    if (s == n) {
      cout << 0 << '\n';
    } else if (s < n) {
      cout << 1 << '\n';
    } else {
      cout << s - n << '\n';
    }
  }
}