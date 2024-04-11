#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>

#define pb push_back
#define int long long
#define ld long double
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;
const int L = 20;
const int N = 300500;
int LG[N];

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  LG[1] = 0;
  for (int i = 2; i < N; i++) {
    LG[i] = 1 + LG[i / 2];
  }
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n + 1), d(n + 1), p(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      d[i] = a[i] - a[i - 1];
    }
    for (int i = 0; i <= n; i++) {
      p[i] = d[i];
      if (i >= 2) {
        p[i] += p[i - 2];
      }
    }
    int ST[n + 1][L];
    for (int i = 0; i <= n; i++) {
      ST[i][0] = p[i];
    }
    for (int l = 1; l < L; l++) {
      for (int i = 0; i <= n; i++) {
        if (i + (1 << l) <= n) {
          ST[i][l] = min(ST[i][l - 1], ST[i + (1 << l)][l - 1]);
        } else {
          ST[i][l] = ST[i][l - 1];
        }
      }
    }

    map<int, vector<int>> indeven, indodd;
    for (int i = 1; i <= n; i++) {
      if (i % 2 == 1) {
        indodd[p[i]].pb(i);
      } else {
        indeven[p[i]].pb(i);
      }
    }

    int ans = 0, ans2 = 0;
    for (int l = 1; l <= n; l++) {
      int lf = l, rf = n + 1;
      while (rf - lf > 1) {
        int m = (lf + rf) / 2;
        if (l + 1 == m) {
          if (a[l + 1] >= a[l]) {
            lf = m;
          } else {
            rf = m;
          }
        } else if (l + 2 == m) {
          if (a[l + 1] >= a[l] && a[l + 2] + a[l] >= a[l + 1]) {
            lf = m;
          } else {
            rf = m;
          }
        } else {
          int len1 = 1 + (m - (l + 1)) / 2;
          int len2 = 1 + (m - (l + 2)) / 2;
          int r1 = m;
          int r2 = m;
          if (m % 2 == (l + 1) % 2) {
            r2--;
          } else {
            r1--;
          }
          int min1 = min(ST[l + 1][LG[len1]], ST[r1 + 2 - (1 << (1 + LG[len1]))][LG[len1]]);
          int min2 = min(ST[l + 2][LG[len2]], ST[r2 + 2 - (1 << (1 + LG[len2]))][LG[len2]]);
          if (min1 >= p[l - 1] && min2 >= p[l] - a[l]) {
            lf = m;
          } else {
            rf = m;
          }
        }
      }
      if (l % 2 == 0) {
        int x = (lower_bound(all(indeven[p[l] - a[l]]), l) - indeven[p[l] - a[l]].begin());
        int y = (upper_bound(all(indeven[p[l] - a[l]]), lf) - indeven[p[l] - a[l]].begin() - 1);
        ans += max(0LL, y - x + 1);

        x = (lower_bound(all(indodd[p[l - 1]]), l) - indodd[p[l - 1]].begin());
        y = (upper_bound(all(indodd[p[l - 1]]), lf) - indodd[p[l - 1]].begin() - 1);
        ans += max(0LL, y - x + 1);

      } else {
        int x = (lower_bound(all(indodd[p[l] - a[l]]), l) - indodd[p[l] - a[l]].begin());
        int y = (upper_bound(all(indodd[p[l] - a[l]]), lf) - indodd[p[l] - a[l]].begin() - 1);
        ans += max(0LL, y - x + 1);

        x = (lower_bound(all(indeven[p[l - 1]]), l) - indeven[p[l - 1]].begin());
        y = (upper_bound(all(indeven[p[l - 1]]), lf) - indeven[p[l - 1]].begin() - 1);
        ans += max(0LL, y - x + 1);
      }

    }
    cout << ans << '\n';
  }

}