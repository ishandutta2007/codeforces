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

const int MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> a(n), ra(n), b(n), c(n), used(n);
    rep(i, n) {
      cin >> a[i];
      ra[a[i] - 1] = i;
    }
    rep(i, n) {
      cin >> b[i];
      c[ra[b[i] - 1]] = i;
    }
    ll ans = 1;
    rep(i, n) {
      if (used[i])
        continue;
      ll p = i;
      while (!used[p]) {
        used[p] = 1;
        p = c[p];
      }
      ans = ans * 2 % MOD;
    }
    cout << ans << '\n';
  }
}