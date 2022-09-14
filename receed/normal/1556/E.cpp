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

const int N = 1 << 17;
ll a[N], ps[N], t1[N * 2], t2[N * 2];

pair<ll, ll> qq(int cl, int cr, int v=1, int l=0, int r=N) {
  if (cr <= l || r <= cl)
    return {1e18, -1e18};
  if (cl <= l && r <= cr)
    return {t1[v], t2[v]};
  auto p1 = qq(cl, cr, v * 2, l, (l + r) / 2);
  auto p2 = qq(cl, cr, v * 2 + 1, (l + r) / 2, r);
  return {min(p1.first, p2.first), max(p1.second, p2.second)};
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll n, q, x;
  cin >> n >> q;
  rep(i, n)
    cin >> a[i];
  rep(i, n) {
    cin >> x;
    a[i] -= x;
    ps[i + 1] = ps[i] + a[i];
  }
  rep(i, n + 1)
    t1[N + i] = t2[N + i] = ps[i];
  for (int i = N - 1; i > 0; --i) {
    t1[i] = min(t1[i * 2], t1[i * 2 + 1]);
    t2[i] = max(t2[i * 2], t2[i * 2 + 1]);
  }
  ll l, r;
  rep(i, q) {
    cin >> l >> r;
    l--;
    auto [mn, mx] = qq(l, r);
    mn -= ps[l];
    mx -= ps[r];
    if (ps[r] != ps[l] || mx > 0)
      cout << "-1\n";
    else
      cout << -mn << '\n';
  }
}