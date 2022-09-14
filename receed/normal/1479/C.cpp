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

int n = 32;
vector<vector<int>> ans;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int l, r;
  cin >> l >> r;
  rep(i, 20) {
    for (int j = n - i; j < n; j++)
      ans.push_back({n - i - 1, j, 1 << (n - j - 1)});
    ans.push_back({n - i - 1, n, 1});
  }
  int s = 1;
  if (l > 1) {
    s = 2;
    ans.push_back({1, 2, l - 1});
  }
  ans.push_back({s, n, 1});
  r -= l;
  for (int i = 20; i >= 0; i--) {
    if (r >= (1 << i)) {
      ans.push_back({s, n - i - 1, r - (1 << i) + 1});
      r -= 1 << i;
    }
  }
  cout << "YES\n";
  cout << n << ' ' << ans.size() << '\n';
  for (auto &pp : ans)
    cout << pp[0] << ' ' << pp[1] << ' ' << pp[2] << '\n';
}