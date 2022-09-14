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
  while (t--) {
    cin >> n >> m;
    vector<string> a(n);
    int f = -1, x;
    rep(i, n) {
      cin >> a[i];
      rep(j, m)
        if (a[i][j] != '.') {
          x = ((i + j) % 2) ^ (a[i][j] == 'R');
          if (x != f) {
            if (f == -1)
              f = x;
            else
              f = -2;
          }
        }
    }
    if (f == -2) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    if (f == -1)
      f = 0;
    rep(i, n) {
      rep(j, m) {
        if ((i + j) % 2 != f)
          cout << 'R';
        else
          cout << 'W';
      }
      cout << '\n';
    }
  }
}