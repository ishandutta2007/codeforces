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
    if (n % 2 == 1) {
      cout << "Bob\n";
    } else {
      int c = 0;
      while (n % 2 == 0) {
        n /= 2;
        c++;
      }
      if (c % 2 == 1 && n == 1) {
        cout << "Bob\n";
      } else {
        cout << "Alice\n";
      }
    }
  }
}