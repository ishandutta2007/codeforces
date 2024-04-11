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

const int N = 1000002, M = 64;
ll a[N], pc[N], ans, ca;
vector<ll> ps[2][M];
vector<pair<int, int>> pos[2][M];

int inter(int l1, int r1, int l2, int r2) {
  return max(0, min(r1, r2) - max(l1, l2));
}

void add(int x, int l, int r, int t, int d) {
  int tt = t ^ 1;
  int cl = lower_bound(all(pos[tt][x]), pair{l, 0}) - pos[tt][x].begin();
  int cr = lower_bound(all(pos[tt][x]), pair{r, 0}) - pos[tt][x].begin() - 1;
  int dd = 0;
  if (cl < cr)
    dd = ps[tt][x][cr] - ps[tt][x][cl];
  if (cl > 0)
    dd += inter(l, r, pos[tt][x][cl - 1].first, pos[tt][x][cl - 1].second);
  if (cl - 1 != cr && cr >= 0)
    dd += inter(l, r, pos[tt][x][cr].first, pos[tt][x][cr].second);
  ca += d * dd;
  if (d == 1) {
    pos[t][x].push_back({l, r});
    ll q = r - l + ps[t][x].back();
    ps[t][x].push_back(q);
  } else {
    assert(pos[t][x].back() == pair(l, r));
    pos[t][x].pop_back();
    ps[t][x].pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  rep(i, 2)
    rep(j, M)
      ps[i][j].push_back(0);
  vector<int> li{-1}, ri{-1};
  rep(i, n) {
    cin >> a[i];
    pc[i] = __builtin_popcountll(a[i]);

    while (li.size() > 1 && a[i] < a[li.back()]) {
      add(pc[li.back()], li[li.size() - 2] + 1, li.back() + 1, 0, -1);
      li.pop_back();
    }
    add(pc[i], li.back() + 1, i + 1, 0, 1);
    li.push_back(i);

    while (ri.size() > 1 && a[i] >= a[ri.back()]) {
      add(pc[ri.back()], ri[ri.size() - 2] + 1, ri.back() + 1, 1, -1);
      ri.pop_back();
    }
    add(pc[i], ri.back() + 1, i + 1, 1, 1);
    ri.push_back(i);
    ans += ca;
  }
  cout << ans;
}