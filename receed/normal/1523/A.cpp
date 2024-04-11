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
  int t, n, m;
  cin >> t;
  rep(z, t) {
    string s;
    cin >> n >> m >> s;
    vector<int> l(n, m + 1), r(n, m + 1);
    rep(i, n) {
      if (s[i] == '1')
        l[i] = 0;
      else if (i > 0)
        l[i] = l[i - 1] + 1;
    }
    for (int i = n - 1; i >= 0; --i) {
      if (s[i] == '1')
        r[i] = 0;
      else if (i < n - 1) {
        r[i] = r[i + 1] + 1;
      }
    }
    rep(i, n)
      if ((l[i] <= m || r[i] <= m) && l[i] != r[i])
        s[i] = '1';
    cout << s << '\n';
  }
}