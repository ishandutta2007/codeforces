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

ll c[4];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll n, x, y;
  cin >> n;
  rep(i, n) {
    cin >> x >> y;
    x /= 2; y /= 2;
    c[x % 2 * 2 + y % 2]++;
  }
  ll ans = 0;
  rep(i, 4) {
    ans += c[i] * (c[i] - 1) * (c[i] - 2) / 6;
    rep(j, 4)
      if (i != j)
        ans += c[i] * (c[i] - 1) / 2 * c[j];
  }
  cout << ans;
}