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

ll q(int x, int y, int t) {
  cout << (t ? "and" : "or") << ' ' << x + 1 << ' ' << y + 1 << endl;
  ll res;
  cin >> res;
  return res;
}

int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  ll o01 = q(0, 1, 0), o02 = q(0, 2, 0), o12 = q(1, 2, 0);
  ll a01 = q(0, 1, 1), a02 = q(0, 2, 1), a12 = q(1, 2, 1);
  a[0] = o01 & o02 & ~a12 | a01 & a02;
  a[1] = o12 & o01 & ~a02 | a12 & a01;
  a[2] = o12 & o02 & ~a01 | a12 & a02;
  for (int i = 3; i < n; ++i) {
    ll ca = q(0, i, 1), co = q(0, i, 0);
    a[i] = ca | (co & ~a[0]);
  }
  sort(all(a));
  cout << "finish " << a[k - 1] << endl;
}