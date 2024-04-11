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
  int n, k;
  cin >> n >> k;
  vector<int> c(n * k), d(n);
  vector<vector<int>> li(n);
  rep(i, n * k) {
    cin >> c[i];
    li[c[i] - 1].push_back(i);
  }
  vector<int> la(n), ra(n);
  rep(i, (n + k) / (k - 1)) {
    int l = i * (k - 1), r = min((i + 1) * (k - 1), n);
    rep(j, r - l) {
      int pos = -1;
      for (int t = l; t < r; ++t)
        if (!d[t] && (pos == -1 || li[t][j + 1] < li[pos][j + 1]))
          pos = t;
      d[pos] = 1;
      la[pos] = li[pos][j];
      ra[pos] = li[pos][j + 1];
    }
  }
  rep(i, n)
    cout << la[i] + 1 << ' ' << ra[i] + 1 << '\n';
}