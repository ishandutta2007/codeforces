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

const int N = 200003;
int mh[N];
vector<int> g[N];
vector<int> li;

void dfs1(int v, int p) {
  for (int u : g[v])
    if (u != p) {
      dfs1(u, v);
      mh[v] = max(mh[v], mh[u] + 1);
    }
}

void dfs2(int v, int p, int ch) {
  for (int u : g[v]) {
    if (u == p)
      continue;
    if (mh[v] == mh[u] + 1 && ch) {
      dfs2(u, v, ch + 1);
      ch = 0;
    } else {
      dfs2(u, v, 1);
    }
  }
  if (ch)
    li.push_back(ch);
  else
    li.push_back(0);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll n, k, u, v;
  cin >> n >> k;
  rep(i, n - 1) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs1(1, -1);
  dfs2(1, -1, 1);
  sort(rall(li));
  ll ans = -1e14, fs = n, cc = 0;
  for (int i : li) {
    fs -= i;
    cc++;
    ll rs = min(fs, n / 2);
    ans = max(ans, cc * (n - cc) - rs * (n - rs));
    if (cc == k)
      break;
  }
  cout << ans << '\n';
}