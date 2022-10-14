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

void solve() {
  int n;
  cin >> n;
  int k1 = 0, k2 = 0;
  int nn = n;
  while (nn % 2 == 0) {
    nn /= 2;
  }
  if (nn != 1) {
    k1 = nn;
    k2 = 2 * (n / nn);
    vector<int> K = {k1, k2};
    for (auto k : K) {
      if (n > k * (k - 1) / 2) {
        if ((n - k * (k - 1) / 2) % k == 0) {
          cout << k << '\n';
          return;
        }
      }
    }
  } else {
    cout << -1 << '\n';
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