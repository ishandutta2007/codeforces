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
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<ll> a(n);
    rep(i, n)
      cin >> a[i];
    ll ans = a[0] + a.back();
    rep(i, n - 1)
      ans += abs(a[i] - a[i + 1]);
    rep(i, n) {
      ans -= max(0ll, min(i == 0 ? a[i] : a[i] - a[i - 1], i == n - 1 ? a[i] : a[i] - a[i + 1]));
    }
    cout << ans << '\n';
  }
}