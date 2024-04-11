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
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<ll> a(n), b(n), sa(n + 1), sb(n + 1);
    rep(i, n)
      cin >> a[i];
    rep(i, n)
      cin >> b[i];
    sort(all(a));
    sort(rall(b));
    rep(i, n) {
      sa[i + 1] = sa[i] + a[i];
      sb[i + 1] = sb[i] + b[i];
    }
    for (int i = 0; ; ++i) {
      ll m = n + i, k = m - m / 4;
      if (sa[m] - sa[m / 4] >= sb[k]) {
        cout << i << '\n';
        break;
      }
      ll na = sa.back() + 100;
      sa.push_back(na);
      ll nb = sb.back();
      sb.push_back(nb);
    }
  }
}