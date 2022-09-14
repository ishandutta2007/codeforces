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

ll solve(vector<int> &a) {
  int n = a.size();
  ll res = 0;
  rep(i, n) {
    if (a[i] == 1)
      continue;
    int f = 1;
    for (int j = 2; j * j <= a[i]; ++j)
      if (a[i] % j == 0) {
        f = 0;
        break;
      }
    if (!f)
      continue;
    ll l = i - 1, r = i + 1;
    while (l >= 0 && a[l] == 1)
      l--;
    while (r < n && a[r] == 1)
      r++;
    res += (i - l) * (r - i) - 1;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, e;
    cin >> n >> e;
    vector<vector<int>> li(e);
    rep(i, n) {
      int x;
      cin >> x;
      li[i % e].push_back(x);
    }
    ll ans = 0;
    rep(i, e)
      ans += solve(li[i]);
    cout << ans << '\n';
  }
}