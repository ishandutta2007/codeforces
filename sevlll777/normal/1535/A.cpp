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
    int s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    if (min(max(s1, s2), max(s3, s4)) > max(min(s1, s2), min(s3, s4))) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}