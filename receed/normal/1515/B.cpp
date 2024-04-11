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


ll is_square(ll x) {
  ll r = sqrt(x);
  while (r * r < x)
    ++r;
  while (r * r > x)
    --r;
  return r * r == x;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll t, n;
  cin >> t;
  rep(z, t) {
    cin >> n;
    if (n % 2 == 0 && is_square(n / 2) || n % 4 == 0 && is_square(n / 4))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}