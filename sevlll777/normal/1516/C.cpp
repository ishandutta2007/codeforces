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
  for (int i = 0; i < n; i++) cin >> A[i];
  int s = 0;
  for (auto x : A) s += x;
  if (s % 2) {
    cout << "0\n";
    return;
  }
  bitset<200009> T;
  T[0] = true;
  for (auto x : A) {
    T |= (T << x);
  }
  if (!T[s / 2]) {
    cout << "0\n";
    return;;
  }
  while (true) {
    for (int i = 0; i < n; i++) {
      if (A[i] % 2) {
        cout << "1\n";
        cout << i + 1 << '\n';
        return;
      }
    }
    for (auto &x : A) x /= 2;
  }
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