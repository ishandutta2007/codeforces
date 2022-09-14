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
  ll t, x, y;
  cin >> t;
  rep(z, t) {
    cin >> x >> y;
    ll l = 0, r = 0, f = 0;
    while (x > 0 || y > 0) {
      r = r + x % 2 - y % 2;
      l = (l + x % 2 - y % 2 + 1) / 2;
      if (l > r) {
        f = 1;
        break;
      }
      x /= 2;
      y /= 2;
    }
    if (f || l > 0)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
}