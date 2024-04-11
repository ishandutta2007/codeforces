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

void solve() {
  int a, b;
  cin >> a >> b;
  int ans = (int) 1e18;
  for (int i = 0; i <= b - a; i++) {
    int op = i;
    if ((a + i) != b) {
      op += ((a + i) | b) - b + 1;
    }
    ans = min(ans, op);
  }
  for (int i = 0; i <= 2 * b + 77; i++) {
    int op = i;
    int aa = a | (b + i);
    op += 1 + (aa - b - i);
    ans = min(ans, op);
  }
  cout << ans;
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