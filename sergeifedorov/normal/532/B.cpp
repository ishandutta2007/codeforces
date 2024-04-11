#undef NDEBUG
#ifdef ssu1
#endif

#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <bitset>
#include <sstream>
#include <typeinfo>
#include <limits>

using namespace std;

const int kMaxN = 300000;

int n;
vector<int> g[kMaxN];

long long a[kMaxN], d[kMaxN][3];
long long z[kMaxN][3];

long long Solve(int v, int tp) {
  long long& ans = d[v][tp];
  if (ans == -1) {
    ans = 0;

    for (int i = 0; i < 3; ++i) {
      for (int u : g[v])
        Solve(u, i);
    }

    for (int i = 0; i < g[v].size() + 10; ++i) {
      for (int j = 0; j < 3; ++j) {
        z[i][j] = -2;
      }
    }

    z[0][0] = 0;
    for (int i = 0; i < g[v].size(); ++i) {
      int u = g[v][i];
      for (int j = 0; j < 2; ++j) {
        if (z[i][j] < 0)
          continue;
        for (int k = 0; k < 2; ++k) {
          long long res = Solve(u, k);
          if (res < 0)
            continue;
          z[i + 1][(j + k) % 2] = max(z[i + 1][(j + k) % 2], z[i][j] + res);
        }
      }
    }

    if (tp == 1) {
      ans = z[g[v].size()][0];
      if (ans >= 0)
        ans += a[v];
      ans = max(ans, z[g[v].size()][1]);
    } else {
      ans = z[g[v].size()][0];
    }

    if (ans < 0)
      ans = -2;
  }
  return ans;
}

int main() {
#ifdef ssu1
  assert(freopen("input.txt", "rt", stdin));
#endif
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int pi;
    scanf("%d%lld", &pi, &a[i]);
    if (pi != -1) {
      pi--;
      g[pi].push_back(i);
    }
  }

  memset(d, -1, sizeof d);

  cout << max(Solve(0, 0), Solve(0, 1)) << endl;

#ifdef ssu1
  cerr << "\nTime = " << static_cast<double>(clock()) / CLOCKS_PER_SEC << endl;
#endif
  return 0;
}