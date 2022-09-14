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

int cnt(int x, int b) {
  int ans = x >> (b + 1) << b;
  x = x & ((1 << (b + 1)) - 1);
  ans += min(x, 1 << b);
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t, l, r;
  cin >> t;
  while (t--) {
    cin >> l >> r;
    int ans = r - l + 1;
    rep(i, 20) {
      ans = min(ans, cnt(r + 1, i) - cnt(l, i));
    }
    cout << ans << '\n';
  }
}