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
  int k;
  string s;
  cin >> k >> s;
  int n = 1 << k, pos = 0;
  vector<int> a(n * 2, 1), num(n * 2), rn(n);
  for (int i = k - 1; i >= 0; --i)
    rep(j, 1 << i) {
      num[(1 << i) + j] = pos;
      rn[pos] = (1 << i) + j;
      ++pos;
    }
  auto rel = [&](int v, char c) {
    if (c == '0')
      a[v] = a[v * 2];
    else if (c == '1')
      a[v] = a[v * 2 + 1];
    else
      a[v] = a[v * 2] + a[v * 2 + 1];
  };
  for (int i = n - 1; i; --i)
    rel(i, s[num[i]]);
  int q;
  cin >> q;
  while (q--) {
    int v;
    char c;
    cin >> v >> c;
    --v;
    s[v] = c;
    v = rn[v];
    while (v > 0) {
      rel(v, s[num[v]]);
      v /= 2;
    }
    cout << a[1] << '\n';
  }
}