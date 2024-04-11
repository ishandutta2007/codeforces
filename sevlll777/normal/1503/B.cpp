#include <bits/stdc++.h>

#define pb push_back
// #define int long long
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
  vector<pair<int, int>> b, w;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if ((i + j) % 2) {
        b.pb({i, j});
      } else {
        w.pb({i, j});
      }
    }
  }
  for (int _ = 0; _ < n * n; _++) {
    int a;
    cin >> a;
    if (a != 1) {
      if (!b.empty()) {
        pair<int, int> y = b.back();
        b.pop_back();
        cout << "1 " << y.first << ' ' << y.second << endl;
      } else {
        pair<int, int> y = w.back();
        w.pop_back();
        cout << 5 - a << ' ' << y.first << ' ' << y.second << endl;
      }
    } else {
      if (!w.empty()) {
        pair<int, int> y = w.back();
        w.pop_back();
        cout << "2 " << ' ' << y.first << ' ' << y.second << endl;
      } else {
        pair<int, int> y = b.back();
        b.pop_back();
        cout << "3 " << y.first << ' ' << y.second << endl;
      }
    }
  }
}