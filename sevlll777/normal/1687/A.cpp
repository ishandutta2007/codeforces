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
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1), p(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    p[i] = p[i - 1] + a[i];
  }
  int c = 0;
  for (int i = min(k, n); i <= n; i++) {
    c = max(c, p[i] - p[i - min(k, n)]);
  }
  for (int x = k - 1; x >= max(k - n, 1LL); x--) {
    c += x;
  }
  cout << c;
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