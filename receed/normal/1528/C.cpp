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

const int N = 1 << 19;
vector<int> g[2][N];
int p[2][N], tin[N], tout[N], on[N];
vector<int> tr[N * 2];
int ct, res, cnt;

void dfs(int v) {
  tin[v] = ct++;
  for (int u : g[1][v])
    dfs(u);
  tout[v] = ct;
}

void add(int cl, int cr, int x, int v=1, int l=0, int r=N) {
  if (cr <= l || r <= cl)
    return;
  if (cl <= l && r <= cr) {
    tr[v].push_back(x);
    return;
  }
  add(cl, cr, x, v * 2, l, (l + r) / 2);
  add(cl, cr, x, v * 2 + 1, (l + r) / 2, r);
}

void del(int cl, int cr, int v=1, int l=0, int r=N) {
  if (cr <= l || r <= cl)
    return;
  if (cl <= l && r <= cr) {
    tr[v].pop_back();
    return;
  }
  del(cl, cr, v * 2, l, (l + r) / 2);
  del(cl, cr, v * 2 + 1, (l + r) / 2, r);
}

int getm(int v) {
  int ans = -1;
  for (int i = N + v; i; i /= 2)
    if (!tr[i].empty())
      ans = max(ans, tr[i].back());
  return ans;
}

void dfs2(int v) {
  int pv = getm(tin[v]), fl = 0;
  if (pv != -1 && on[pv]) {
    fl = 1;
    on[pv] = 0;
  } else
    cnt++;
  on[v] = 1;
  res = max(res, cnt);
  add(tin[v], tout[v], v);
  for (int u : g[0][v])
    dfs2(u);
  del(tin[v], tout[v]);
  if (fl)
    on[pv] = 1;
  else
    cnt--;
  on[v] = 0;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t, n;
  cin >> t;
  rep(z, t) {
    cin >> n;
    ct = res = cnt = 0;
    rep(i, 2) {
      rep(j, n)
        g[i][j].clear();
      for (int j = 1; j < n; ++j) {
        cin >> p[i][j];
        g[i][--p[i][j]].push_back(j);
      }
    }
    dfs(0);
    dfs2(0);
    cout << res << '\n';
  }
}