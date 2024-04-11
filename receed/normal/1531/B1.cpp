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
  int n, x, y;
  map<int, int> c1;
  map<pair<int, int>, int> c2;
  ll ans = 0;
  cin >> n;
  rep(i, n) {
    cin >> x >> y;
    if (x > y)
      swap(x, y);
    if (x == y) {
      ans += c1[x];
      ++c1[x];
    } else {
      ans += c1[x] + c1[y] - c2[{x, y}];
      ++c1[x];
      ++c1[y];
      ++c2[{x, y}];
    }
  }
  cout << ans;
}