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
    cin >> n;
    vector<int> a(n);
    rep(i, n)
      cin >> a[i];
    int mn = n <= 2 ? 0 : n;
    rep(i, n)
      rep(j, i) {
        int cc = 0;
        rep(k, n) {
          int ax = j - i, ay = a[j] - a[i];
          int bx = k - i, by = a[k] - a[i];
          if (ax * by - bx * ay != 0)
            cc++;
        }
        mn = min(mn, cc);
      }
    cout << mn << '\n';
  }
}