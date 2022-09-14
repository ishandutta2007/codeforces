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
  int t, n, x;
  cin >> t;
  rep(z, t) {
    cin >> n;
    rep(i, n)
      cin >> x;
    cout << 3 * n << '\n';
    for (int i = 1; i < n; i += 2) {
      rep(j, 2) {
        cout << 2 << ' ' << i << ' ' << i + 1 << '\n';
        cout << 1 << ' ' << i << ' ' << i + 1 << '\n';
        cout << 2 << ' ' << i << ' ' << i + 1 << '\n';
      }
    }
  }
}