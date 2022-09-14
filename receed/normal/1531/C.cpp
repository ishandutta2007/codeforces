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

const int N = 101;
int a[N][N];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m = 1;
  cin >> n;
  while (m * m < n)
    ++m;
  if (n == 2) {
    cout << -1;
    return 0;
  }
  if (m * m == n) {
    rep(i, m)
      rep(j, m)
        a[i][j] = 1;
  } else {
    rep(i, m - 1)
      rep(j, m - 1)
        a[i][j] = 1;
    int k = (n - (m - 1) * (m - 1) + 1) / 2;
    if (n % 2 != m % 2) {
      rep(i, k)
        a[m - 1][i] = a[i][m - 1] = 1;
    } else {
      a[m - 2][m - 2] = 0;
      rep(i, min(k, m - 2))
        a[m - 1][i] = a[i][m - 1] = 1;
      if (k > m - 2) {
        a[0][m] = a[m][0] = 1;
        ++m;
      }
    }
  }
  cout << m << '\n';
  for (int i = m - 1; i >= 0; --i) {
    rep(j, m)
      if (a[i][j])
        cout << 'o';
      else
        cout << '.';
    cout << '\n';
  }
}