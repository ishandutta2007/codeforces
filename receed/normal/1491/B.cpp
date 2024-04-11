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
  int t, n, u, v;
  cin >> t;
  rep(z, t) {
    cin >> n >> u >> v;
    vector<int> a(n);
    int f = 1;
    rep(i, n) {
      cin >> a[i];
      if (a[i] != a[0])
        f = 0;
    }
    if (f) {
      cout << v + min(u, v) << '\n';
      continue;
    }
    f = 1;
    for (int i = 1; i < n; i++) {
      if (abs(a[i] - a[i - 1]) > 1) {
        f = 0;
        break;
      }
    }
    if (f)
      cout << min(u, v) << '\n';
    else
      cout << 0 << '\n';
  }
}