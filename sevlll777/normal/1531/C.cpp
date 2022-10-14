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
  if (n == 2) {
    cout << "-1\n";
    exit(0);
  }
  int s = (int) floor(sqrt(n));
  if (n + 2 == (s + 1) * (s + 1)) {
    cout << s + 2 << '\n';
    vector<vector<char>> ans(s + 2, vector<char>(s + 2));
    for (int i = 0; i < s + 2; i++) {
      for (int j = 0; j < s + 2; j++) {
        if (i == 0) {
          if (j == 0) {
            ans[i][j] = 'o';
          } else {
            ans[i][j] = '.';
          }
        } else {
          if (j < s + 1) {
            ans[i][j] = 'o';
          } else {
            ans[i][j] = '.';
          }
        }
      }
    }
    ans[s+1][s+1] = 'o';
    ans[1][s-1] = '.';
    ans[1][s] = '.';
    ans[2][s-1] = '.';
    ans[2][s] = '.';
    for (auto p : ans) {
      for (auto x : p) {
        cout << x;
      }
      cout << '\n';
    }
    exit(0);
  }
  if (s * s == n) {
    cout << s << '\n';
    for (int _ = 0; _ < s; _++) {
      for (int __ = 0; __ < s; __++) {
        cout << 'o';
      }
      cout << '\n';
    }
  } else {
    int x = s * s;
    cout << s + 1 << '\n';
    int w = n - x;
    vector<vector<char>> ans(s + 1, vector<char>(s + 1));
    for (int i = 0; i < s + 1; i++) {
      for (int j = 0; j < s + 1; j++) {
        if (i == 0) {
          if (j < (w + 1) / 2) {
            ans[i][j] = 'o';
          } else {
            ans[i][j] = '.';
          }
        } else {
          if (j < s) {
            ans[i][j] = 'o';
          } else if (i + (w + 1) / 2 > s) {
            ans[i][j] = 'o';
          } else {
            ans[i][j] = '.';
          }
        }
      }
    }
    if (w % 2) {
      ans[1][s - 1] = '.';
    }
    for (auto p : ans) {
      for (auto x : p) {
        cout << x;
      }
      cout << '\n';
    }
  }

}