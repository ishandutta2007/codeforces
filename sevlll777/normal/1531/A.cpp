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
  int n;
  cin >> n;
  bool locked = false;
  string ans = "blue";
  for (int _ = 0; _ < n; _++) {
    string cmd;
    cin >> cmd;
    if (cmd == "lock") {
      locked = true;
    } else if (cmd == "unlock") {
      locked = false;
    } else if (!locked) {
      ans = cmd;
    }
  }
  cout << ans << '\n';
}