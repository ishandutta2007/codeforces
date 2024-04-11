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

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int mxr = 0, mxw = 0;
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      mxr = max(mxr, a);
      mxw = max(mxw, b);
    }
    if (mxr + mxw > n) {
      cout << "IMPOSSIBLE\n";
    } else {
      for (int i = 0; i < n; i++) {
        if (i < mxr) {
          cout << "R";
        } else {
          cout << "W";
        }
      }
      cout << '\n';
    }
  }
}