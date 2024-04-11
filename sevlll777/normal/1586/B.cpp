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
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<bool> kek(n + 1, false);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    kek[b] = true;
  }
  for (int i = 1; i <= n; i++) {
    if (!kek[i]) {
      for (int x = 1; x <= n; x++) {
        if (x != i) {
          cout << x << ' ' << i << '\n';
        }
      }
      break;
    }
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