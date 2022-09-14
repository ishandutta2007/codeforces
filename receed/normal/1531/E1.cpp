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

const int N = 100002, L = 18;
int a[N], p[N], tmp[N], ls[L][N], rs[L][N];
int n, pos;

int go(int l, int r, int d) {
  if (r - l == 1)
    return 0;
  int m = (l + r) / 2;
  if (go(l, m, d + 1) || go(m, r, d + 1))
    return 1;
  int c[2]{};
  ls[d][l] = pos;
  while (c[0] < m - l && c[1] < r - m) {
    if (pos >= n)
      return 1;
    ++c[a[pos]];
    ++pos;
  }
  rs[d][l] = pos;
  return 0;
}

void rec(int l, int r, int d) {
  if (r - l == 1)
    return;
  int m = (l + r) / 2;
  int lp = l, rp = m, tp = l;
  for (int i = ls[d][l]; i < rs[d][l]; ++i) {
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
  rep(i, n)
    a[i] = s[i] - '0';
  int m = 1;
  for (; ; ++m) {
    pos = 0;
    if (!go(0, m, 0) && pos == n)
      break;
  }
  iota(p, p + m, 1);
  rec(0, m, 0);
  cout << m << '\n';
  rep(i, m)
    cout << p[i] << ' ';
}