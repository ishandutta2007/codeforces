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
  int n, k;
  cin >> n >> k;
  vector<vector<ll>> a(k, vector<ll>(n));
  vector<ll> sq(k), s(k);
  rep(i, k) {
    rep(j, n) {
      cin >> a[i][j];
      sq[i] += a[i][j] * a[i][j];
      s[i] += a[i][j];
    }
  }
  ll ts = 0, tq = 0;
  int pos = -1;
  rep(i, k) {
    vector<ll> cs = s;
    if (i > 2)
      cs[i] = cs[i - 1] * 2 - cs[i - 2];
    else
      cs[i] = cs[i + 1] * 2 - cs[i + 2];
    int ok = 1;
    rep(j, k - 2)
      if (cs[j + 1] - cs[j] != cs[j + 2] - cs[j + 1])
        ok = 0;
    if (ok) {
      pos = i;
      ts = cs[i];
      break;
    }
  }
  int fl = 0;
  if (pos <= 2) {
    reverse(all(s));
    reverse(all(sq));
    pos = k - 1 - pos;
    fl = 1;
  }
  ll aa, b, c = sq[0];
  aa = (sq[2] - 2 * sq[1] + c) / 2;
  b = sq[1] - aa - c;
  tq = aa * pos * pos + b * pos + c;
  if (fl) {
    reverse(all(s));
    reverse(all(sq));
    pos = k - 1 - pos;
  }
  cout << pos << ' ';
  rep(i, n) {
    ll tv = a[pos][i] + ts - s[pos];
    if (sq[pos] - a[pos][i] * a[pos][i] + tv * tv == tq) {
      cout << tv;
      return 0;
    }
  }
}