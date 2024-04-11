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
  ll t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<ll> d(n);
    rep(i, n)
      cin >> d[i];
    sort(all(d));
    ll ans = 0;
    rep(i, n)
      ans -= d[i] * (i - (n - 1 - i));
    ans += d.back();
    cout << ans << '\n';
  }
}