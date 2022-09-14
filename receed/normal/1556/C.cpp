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
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n)
    cin >> a[i];
  ll ans = 0;
  for (int i = 0; i < n; i += 2) {
    ll mn = 0, cs = 0;
    for (int j = i + 1; j < n; ++j) {
      if (j % 2 == 1) {
        ll cl = max(-mn, 0ll);
        ll cr = cl + cs;
        if (cr < 0) {
          cl -= cr;
          cr = 0;
        }
        if (j == i + 1)
          cl = cr = 1;
        ans += max(0ll, min(a[i] - cl + 1, a[j] - cr + 1));
      }

      cs += a[j] * (1 - j % 2 * 2);
      mn = min(mn, cs);
    }
  }
  cout << ans;
}