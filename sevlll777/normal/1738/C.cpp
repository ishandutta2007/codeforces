#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int c = 0;
  for (auto x :a) c += abs(x) % 2;
  if (c % 4 == 2) {
    cout << "Bob\n";
  } else if (c % 4 == 1) {
    if (n % 2 == c % 2) {
      cout << "Bob\n";
    } else {
      cout << "Alice\n";
    }
  } else if (c % 4 == 0) {
    cout << "Alice\n";
  } else {
    cout << "Alice\n";
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