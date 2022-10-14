#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int c1 = 0, c0 = 0;
  for (auto x : s) {
    if (x == '0') {
      c0++;
    } else {
      c1++;
    }
  }
  if (c0 % 2) {
    cout << "NO\n";
    return;
  }
  int w = c1 / 2;
  int r = c0 / 2;
  int b1 = 0, b2 = 0;
  string a1 = "", a2 = "";
  for (auto c : s) {
    if (b1 < 0 || b2 < 0) {
      cout << "NO\n";
      return;
    }
    if (c == '1') {
      if (w == 0) {
        a1 += ')';
        a2 += ')';
        b1--;
        b2--;
      } else {
        w--;
        a1 += '(';
        a2 += '(';
        b1++;
        b2++;
      }
    } else {
      if (b1 == 0 && b2 == 0) {
        cout << "NO\n";
        return;
      } else if (b1 > b2 && r) {
        r--;
        a1 += ')';
        a2 += '(';
        b1--;
        b2++;
      } else {
        a1 += '(';
        a2 += ')';
        b1++;
        b2--;
      }
    }
  }
  if (r == 0 && b1 == 0 && b2 == 0) {
    cout << "YES\n" << a1 << '\n' << a2 << '\n';
  } else {
    cout << "NO\n";
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