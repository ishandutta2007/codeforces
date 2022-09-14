#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    vector ps(n, vector<int>(m + 1));
    vector<ll> ci(n + 1), co(n), ss(n + 1);
    rep(i, n) {
      cin >> a[i];
      rep(j, m)
        ps[i][j + 1] = ps[i][j] + a[i][j] - '0';
    }
    ll ans = n * m;
    rep(l, m)
      for (int r = l + 3; r < m; ++r) {
        rep(i, n) {
          ci[i] = ps[i][r] - ps[i][l + 1] + (a[i][l] == '0') + (a[i][r] == '0');
          co[i] = r - l - 1 - (ps[i][r] - ps[i][l + 1]);
        }
        rep(i, n) {
          ss[i + 1] = ss[i] + ci[i];
        }
        ll mx = 1e9;
        rep(i, n) {
          if (i >= 4)
            mx = min(mx, co[i - 4] - ss[i - 3]);
          ans = min(ans, co[i] + ss[i] + mx);
        }
      }
    cout << ans << '\n';
  }
}