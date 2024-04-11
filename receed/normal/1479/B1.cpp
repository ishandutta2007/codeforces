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
  int n;
  cin >> n;
  vector<int> a(n);
  vector<pair<int, int>> q;
  rep(i, n) {
    cin >> a[i];
    if (!q.empty() && q.back().first == a[i])
      q.back().second++;
    else
      q.push_back({a[i], 1});
  }
  int ans = q.size();
  for (auto &pp : q)
    if (pp.second > 1)
      ans++;
  int l = -1;
  rep(i, q.size()) {
    if (q[i].second == 1)
      continue;
    if (l == -1) {
      l = i;
      continue;
    }
    int f = 0;
    if ((i - l) % 2 == 0 && q[l].first == q[i].first) {
      f = 1;
      for (int j = l; j < i; j += 2)
        if (q[j].first != q[l].first)
          f = 0;
    }
    ans -= f;
    l = i;
  }
  cout << ans;
}