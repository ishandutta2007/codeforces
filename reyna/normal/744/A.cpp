// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>

using namespace std;

const int N = (int) 1e5 + 5, mod = (int) 0;
int a[N], par[N], sz[N];
int find(int v) { return v == par[v]? v: par[v] = find(par[v]); }
void unite(int u, int v) {
  par[find(u)] = find(v);
}
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int j = 0; j < N; ++j) par[j] = j;
  for (int j = 0; j < k; ++j) {
    cin >> a[j];
    a[j]--;
  }
  for (int j = 0; j < m; ++j) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    unite(u, v);
  }
  for (int j = 0; j < n; ++j) {
    sz[find(j)]++;
  }
  int sum = n;
  int mx = 0;
  int res = 0;
  for (int j = 0; j < k; ++j) {
    int s = sz[find(a[j])];
    res += s * (s - 1) / 2;
    sum -= sz[find(a[j])];
    mx = max(mx, sz[find(a[j])]);
  }
  cout << mx * sum + sum * (sum - 1) / 2 + res - m << endl;
}