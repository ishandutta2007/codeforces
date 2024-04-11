#include <iostream>
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
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>

#define pb push_back
#define int long long
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    bool srt = true;
    for (int j = 1; j < m; j++) {
      srt &= (a[i][j] >= a[i][j - 1]);
    }
    if (!srt) {
      vector<int> b;
      for (int j = 0; j < m; j++) {
        b.pb(a[i][j]);
      }
      sort(all(b));
      vector<int> id;
      for (int j = 0; j < m; j++) {
        if (b[j] != a[i][j]) {
          id.pb(j);
        }
      }
      if (id.size() >= 3) {
        cout << "-1\n";
        return;
      }
      if (!id.empty()) {
        assert((int) id.size() == 2);
        for (int i0 = 0; i0 < n; i0++) {
          swap(a[i0][id[0]], a[i0][id[1]]);
        }

        bool ok = true;
        for (int i0 = 0; i0 < n; i0++) {
          for (int j0 = 1; j0 < m; j0++) {
            ok &= (a[i0][j0] >= a[i0][j0 - 1]);
          }
        }

        if (ok) {
          cout << 1 + id[0] << ' ' << 1 + id[1] << '\n';
          return;
        }
        cout << "-1\n";
        return;

      }
    }
  }

  cout << "1 1\n";

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