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
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;
const int INF = (int) 3e9;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int x1 = INF, x2 = INF, x3 = INF, x4 = INF;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    x1 = min(x1, abs(a[0] - b[i]));
    x2 = min(x2, abs(a[n - 1] - b[i]));
  }
  for (int i = 0; i < n; i++) {
    x3 = min(x3, abs(a[i] - b[0]));
    x4 = min(x4, abs(a[i] - b[n - 1]));
  }
  vector<int> options = {x1 + x2 + x3 + x4, abs(a[0] - b[0]) + x2 + x4, abs(a[0] - b[n - 1]) + x2 + x3,
                         abs(a[n - 1] - b[0]) + x1 + x4, abs(a[n - 1] - b[n - 1]) + x1 + x3,
                         abs(a[0] - b[0]) + abs(a[n - 1] - b[n - 1]), abs(a[0] - b[n - 1]) + abs(a[n - 1] - b[0])};
  cout << *min_element(all(options));
  cout << '\n';
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