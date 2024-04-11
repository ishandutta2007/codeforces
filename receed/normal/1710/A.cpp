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

bool solve(ll n, ll m, vector<ll> &a) {
  ll r = 0;
  int f = 0;
  for (ll i : a) {
    if (i / n > 2)
      f = 1;
    if (i / n >= 2)
      r += i / n;
  }
  if (m % 2 && !f)
    return 0;
  return r >= m;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll t, n, m, k;
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    vector<ll> a(k);
    for (ll &i : a)
      cin >> i;
    if (solve(n, m, a) || solve(m, n, a))
      cout << "Yes\n";
    else
      cout << "No\n";
  }
}