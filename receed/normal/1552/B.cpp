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

bool cmp(vector<int> &a, vector<int> &b) {
  int r = 0;
  rep(i, 5)
    r += (a[i] < b[i]);
  return r > 2;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t, n;
  cin >> t;
  random_device rd;
  mt19937 gen(rd());
  while (t--) {
    cin >> n;
    vector<vector<int>> a(n, vector<int>(5));
    rep(i, n)
      rep(j, 5)
        cin >> a[i][j];
    int pos = 0;
    rep(i, n)
      if (cmp(a[i], a[pos]))
        pos = i;
    rep(i, n)
      if (i != pos && cmp(a[i], a[pos])) {
        pos = -2;
        break;
      }
    cout << pos + 1 << '\n';
  }
}