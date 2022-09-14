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
  int n, m, p;
  cin >> n >> m >> p;
  vector<ll> a(n);
  string s;
  rep(i, n) {
    cin >> s;
    rep(j, m)
      if (s[j] == '1')
        a[i] |= 1ll << j;
  }
  ll res = 0, ans = 0;
  random_device rd;
  mt19937 gen(rd());
  rep(i, 40) {
    ll ms = a[gen() % n];
    vector<int> b;
    rep(i, m)
      if ((ms >> i) & 1)
        b.push_back(i);
    vector<ll> cnt(1 << b.size());
    rep(j, n) {
      ll cm = 0;
      rep(k, b.size())
        if ((a[j] >> b[k]) & 1)
          cm |= 1 << k;
      cnt[cm]++;
    }
    rep(j, b.size())
      rep(k, 1 << b.size())
        if ((k >> j) & 1)
          cnt[k ^ (1 << j)] += cnt[k];
    rep(j, cnt.size())
      if (cnt[j] >= (n + 1) / 2) {
        ll ca = 0, cr = 0;
        rep(k, b.size())
          if ((j >> k) & 1) {
            cr++;
            ca |= 1ll << b[k];
          }
        if (cr > res) {
          res = cr;
          ans = ca;
        }
      }
  }
  rep(i, m)
    cout << ((ans >> i) & 1);
}