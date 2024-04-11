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

const int N = 1 << 18;
ll inf = 1e15;
ll tr[2][N * 2];

void add(int t, int v, ll x) {
  for (int i = N + v; i; i /= 2)
    tr[t][i] = max(tr[t][i], x);
}

void adds(int t, int v) {
  for (int i = N + v; i; i /= 2)
    tr[t][i] = -inf;
}

ll mx(int t, int cl, int cr, int v=1, int l=0, int r=N) {
  if (cr <= l || r <= cl)
    return -inf;
  if (cl <= l && r <= cr)
    return tr[t][v];
  return max(mx(t, cl, cr, v * 2, l, (l + r) / 2), mx(t, cl, cr, v * 2 + 1, (l + r) / 2, r));
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t, n, m;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    rep(i, 2)
      rep(j, n + 2)
        adds(i, j);
    vector<ll> a(n), b(n), li;
    vector<vector<ll>> e;
    rep(i, n) {
      cin >> a[i] >> b[i];
      e.push_back({a[i] - b[i], 1, b[i] - a[i]});
      e.push_back({a[i], -2, 2 * a[i]});
      e.push_back({a[i] + b[i], 1, -b[i] - a[i]});
    }
    li = a;
    sort(all(li));
    sort(all(e));
    li.erase(unique(all(li)), li.end());
    int l = li.size();
    vector<ll> y(l);
    ll pos = 0, cb = 0, ck = 0;
    rep(i, l) {
      while (pos < e.size() && e[pos][0] <= li[i]) {
        ck += e[pos][1];
        cb += e[pos][2];
        pos++;
      }
      y[i] = ck * li[i] + cb;
    }
    vector<ll> pm(l + 1, -inf), sm(l + 1, -inf);
    rep(i, l) {
      pm[i + 1] = max(pm[i], y[i]);
      add(0, i, y[i] - li[i]);
    }
    for (int i = l - 1; i >= 0; --i) {
      sm[i] = max(sm[i + 1], y[i]);
      add(1, i, y[i] + li[i]);
    }
    rep(i, n) {
      int pl = lower_bound(all(li), a[i] - b[i]) - li.begin();
      int pr = lower_bound(all(li), a[i] + b[i]) - li.begin();
      int md = lower_bound(all(li), a[i]) - li.begin();
      if (pm[pl] > m || sm[pr] > m || mx(0, pl, md) + a[i] - b[i] > m || mx(1, md, pr) - a[i] - b[i] > m)
        cout << 0;
      else
        cout << 1;
    }
    cout << '\n';
  }
}