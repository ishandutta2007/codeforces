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
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> r1(n), r2(n), r3(n), r4(n), r5(n);
  for (int i = 0; i < n; i++) {
    cin >> r1[i] >> r2[i] >> r3[i] >> r4[i] >> r5[i];
    r1[i] *= -1;
    r2[i] *= -1;
    r3[i] *= -1;
    r4[i] *= -1;
    r5[i] *= -1;
  }
  int x = 0;
  for (int i = 1; i < n; i++) {
    int cnt = 0;
    if (r1[i] > r1[x]) cnt++;
    if (r2[i] > r2[x]) cnt++;
    if (r3[i] > r3[x]) cnt++;
    if (r4[i] > r4[x]) cnt++;
    if (r5[i] > r5[x]) cnt++;
    if (cnt >= 3) {
      x = i;
    }
  }
  for (int i = 0; i < n; i++) {
    if (i != x) {
      int cnt = 0;
      if (r1[i] > r1[x]) cnt++;
      if (r2[i] > r2[x]) cnt++;
      if (r3[i] > r3[x]) cnt++;
      if (r4[i] > r4[x]) cnt++;
      if (r5[i] > r5[x]) cnt++;
      if (cnt >= 3) {
        cout << "-1\n";
        return;
      }
    }
  }
  cout << x + 1 << '\n';
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