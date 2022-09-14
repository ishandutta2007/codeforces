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
#include <ext/pb_ds/assoc_container.hpp>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

using namespace __gnu_pbds;
gp_hash_table<ll, int> mp;

const int N = 100002, L = 18, M = L * N;
vector<int> li[2];
int p[N], tmp[N], ls[L][N];
int a[M], dpos[M][2];
int n, pos;

int go(int l, int r, int d) {
  if (r - l == 1)
    return 0;
  int m = (l + r) / 2;
  if (go(l, m, d + 1) || go(m, r, d + 1) || pos == n)
    return 1;
  ls[d][l] = pos;
  int p0 = dpos[pos][0] + m - l - 1, p1 = dpos[pos][1] + r - m - 1;
  if (p0 < li[0].size())
    assert(li[0][p0] >= pos);
  if (p1 < li[1].size())
    assert(li[1][p1] >= pos);
  int npos = min(p0 < li[0].size() ? li[0][p0] : n, p1 < li[1].size() ? li[1][p1] : n);
  if (npos >= n)
    return 1;
  pos = npos + 1;
  return 0;
}

void rec(int l, int r, int d) {
  if (r - l == 1)
    return;
  int m = (l + r) / 2;
  int lp = l, rp = m, tp = l;
  for (int i = ls[d][l]; lp < m && rp < r; ++i) {
    if (a[i])
      tmp[rp++] = p[tp++];
    else
      tmp[lp++] = p[tp++];
  }
  for (; lp < m; ++lp)
    tmp[lp] = p[tp++];
  for (; rp < r; ++rp)
    tmp[rp] = p[tp++];
  for (int i = l; i < r; ++i)
    p[i] = tmp[i];
  rec(l, m, d + 1);
  rec(m, r, d + 1);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  n = s.size();
  rep(i, n) {
    a[i] = s[i] - '0';
    rep(j, 2)
      dpos[i][j] = li[j].size();
    li[a[i]].push_back(i);
  }
  int l = 0, r = 100003, m;
  while (r - l > 1) {
    m = (l + r) / 2;
    pos = 0;
    if (go(0, m, 0))
      r = m;
    else if (pos < n)
      l = m;
    else {
      break;
    }
  }
  iota(p, p + m, 1);
  rec(0, m, 0);
  cout << m << '\n';
  rep(i, m)
    cout << p[i] << ' ';
}