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
  ll t, n, x;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<vector<ll>> a(2);
    rep(i, n) {
      cin >> x;
      a[x % 2].push_back(i);
    }
    ll s1 = a[0].size(), s2 = a[1].size(); 
    if (abs(s1 - s2) > 1) {
      cout << "-1\n";
      continue;
    }
    ll ans = 1e18;
    rep(i, 2) {
      int j = 1 - i;
      if (a[i].size() < a[j].size())
        continue;
      ll ca = 0;
      rep(k, a[i].size())
        ca += abs(k * 2 - a[i][k]);
      rep(k, a[j].size())
        ca += abs(k * 2 + 1 - a[j][k]);
      ans = min(ans, ca / 2);
    }
    cout << ans << '\n';
  }
}