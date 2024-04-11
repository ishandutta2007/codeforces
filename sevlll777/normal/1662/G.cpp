#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>

#define pb push_back
// #define int long long
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;
const int N = 1000009;

vector<int> g[N];
int sizes[N];

void make_size(int vertex, int parent, int h) {
  sizes[vertex] = 1;
  for (int q : g[vertex]) {
    if (q != parent) {
      make_size(q, vertex, h + 1);
      sizes[vertex] += sizes[q];
    }
  }
}

int centroid(int vertex) {
  int parent = -1, all = sizes[vertex];
  bool flag = false;
  while (!flag) {
    flag = true;
    for (int q : g[vertex]) {
      if (q != parent && sizes[q] * 2 > all) {
        parent = vertex, vertex = q, flag = false;
        break;
      }
    }
  }
  return vertex;
}

bitset<N> used;
long long ans = 0;
int sons[N];
int sz = 0;

void dfs(int v) {
  sz++;
  sons[v] = 1;
  used[v] = true;
  for (auto u : g[v]) {
    if (!used[u]) {
      dfs(u);
      sons[v] += sons[u];
    }
  }
  ans += sons[v];
}

int bts[N];
bitset<N> dp;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int p;
    cin >> p;
    p--;
    g[p].pb(i);
    g[i].pb(p);
  }
  make_size(0, -1, 0);
  int c = centroid(0);
  used[c] = true;

  for (auto u : g[c]) {
    sz = 0;
    dfs(u);
    bts[sz]++;
  }

  dp[0] = true;

  for (int i = 0; i <= n; i++) {
    if (bts[i] >= 3) {
      bts[i + i] += (bts[i] - 1) / 2;
      bts[i] = 2 - bts[i] % 2;
    }
    for (int _ = 0; _ < bts[i]; _++) {
      dp |= (dp << i);
    }
  }
  long long kek = 0;
  for (int w = 0; w <= n; w++) {
    if (dp[w]) {
      kek = max(kek, (long long) (w + 1) * (long long) (n - w));
    }
  }
  ans += kek;
  cout << ans << '\n';


}