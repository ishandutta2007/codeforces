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
    vector<vector<int>> a(2);
    int x;
    rep(i, n) {
      cin >> x;
      a[i % 2].push_back(x);
    }
    sort(all(a[0]));
    sort(all(a[1]));
    int ok = 1;
    rep(i, n - 1)
      if (a[i % 2][i / 2] > a[(i + 1) % 2][(i + 1) / 2])
        ok = 0;
    cout << (ok ? "YES" : "NO") << '\n';
  }
}