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
  int t, a, b;
  cin >> t;
  rep(z, t) {
    cin >> a >> b;
    int n = a + b, ca = (n + 1) / 2, cb = n / 2;
    set<int> ans;
    rep(i, min(ca, b) + 1) {
      int j = a - ca + i;
      if (j >= 0 && j <= a && j <= cb)
        ans.insert(i + j);
    }
    rep(i, min(cb, b) + 1) {
      int j = a - cb + i;
      if (j >= 0 && j <= a && j <= ca)
        ans.insert(i + j);
    }
    cout << ans.size() << '\n';
    for (int i : ans)
      cout << i << ' ';
    cout << '\n';
  }
}