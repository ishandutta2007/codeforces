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
    string s1, s2;
    cin >> n >> s1 >> s2;
    int c00 = 0, c01 = 0, c10 = 0, c11 = 0;
    rep(i, n) {
      if (s1[i] == '1') {
        if (s2[i] == '1')
          c11++;
        else
          c10++;
      } else {
        if (s2[i] == '1')
          c01++;
        else
          c00++;
      }
    }
    int inf = 1e9, ans = inf;
    if (c10 == c01)
      ans = c10 * 2;
    if (c11 - 1 == c00)
      ans = min(ans, c00 * 2 + 1);
    if (ans == inf)
      ans = -1;
    cout << ans << '\n';
  }
}