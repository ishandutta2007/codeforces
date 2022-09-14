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

const int N = 300002, L = 19;
int d[N], a[N], c[N], del[N], up[N][L];

int main() {
  int q, t, v, w;
  cin >> q >> a[0] >> c[0];
  for (int i = 1; i <= q; ++i) {
    cin >> t;
    if (t == 1) {
      cin >> up[i][0] >> a[i] >> c[i];
      rep(j, L - 1)
        up[i][j + 1] = up[up[i][j]][j];
      d[i] = d[up[i][0]] + 1;
    } else {
      cin >> v >> w;
      int u = v;
      for (int j = L - 1; j >= 0; --j)
        if (!del[up[u][j]])
          u = up[u][j];
      ll sa = 0, sc = 0;
      for (int j = d[v] - d[u]; j >= 0; --j) {
        u = v;
        rep(k, L)
          if ((j >> k) & 1)
            u = up[u][k];
        if (w >= a[u]) {
          sa += a[u];
          w -= a[u];
          sc += (ll) a[u] * c[u];
          a[u] = 0;
          del[u] = 1;
        } else {
          sa += w;
          sc += (ll) w * c[u];
          a[u] -= w;
          break;
        }
      }
      cout << sa << ' ' << sc << endl;
    }
  }
}