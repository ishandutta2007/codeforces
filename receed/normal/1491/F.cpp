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
  int t, n;
  cin >> t;
  rep(z, t) {
    cin >> n;
    int pos, x;
    for (pos = 2; pos < n; ++pos) {
      cout << "? " << pos - 1 << ' ' << 1 << endl;
      for (int i = 1; i < pos; ++i)
        cout << i << ' ';
      cout << endl;
      cout << pos << endl;
      cin >> x;
      if (x != 0) {
        break;
      }
    }
    int l = 1, r = pos, m;
    while (r - l > 1) {
      m = (l + r) / 2;
      cout << "? " << m - l << ' ' << 1 << endl;
      for (int i = l; i < m; ++i)
        cout << i << ' ';
      cout << endl;
      cout << pos << endl;
      cin >> x;
      if (x)
        r = m;
      else
        l = m;
    }
    vector<int> ans;
    for (int i = 1; i < pos; ++i)
      if (i != l)
        ans.push_back(i);
    for (int i = pos + 1; i <= n; ++i) {
      cout << "? 1 1" << endl;
      cout << pos << endl;
      cout << i << endl;
      cin >> x;
      if (!x)
        ans.push_back(i);
    }
    cout << "! " << ans.size();
    for (int i : ans)
      cout << ' ' << i;
    cout << endl;
  }
}