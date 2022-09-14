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

int c[2];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    ll ans = 0, pos = 0;
    vector<int> a(s.size(), -1);
    c[0] = c[1] = 0;
    rep(i, s.size()) {
      if (s[i] != '?') {
        a[i] = (s[i] - '0') ^ (i % 2);
        c[a[i]]++;
        while (c[1 - a[i]]) {
          if (a[pos] != -1)
            c[a[pos]]--;
          pos++;
        }
      }
      ans += i - pos + 1;
    }
    cout << ans << '\n';
  }
}