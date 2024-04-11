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
  int n, t, l, r, x;
  cin >> t;
  rep(z, t) {
    cin >> n >> l >> r;
    vector<int> b(n);
    rep(i, n) {
      cin >> x;
      b[--x] += (i < l ? 1 : -1);
    }
    int d = l - r, ans = 0, lx = 0;
    int s = (d > 0 ? 1 : -1);
    rep(i, n) {
      while (d != 0 && abs(b[i]) > 1 && (b[i] > 0) == (d > 0)) {
        b[i] -= 2 * s;
        d -= 2 * s;
        ans++;
      }
      lx += abs(b[i]);
    }
    ans += lx / 2 + abs(d) / 2;
    cout << ans << '\n';
  }
}