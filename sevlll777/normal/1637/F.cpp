#include <iostream>
#include <iomanip>
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
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>

#define pb push_back
#define int long long
#define ld long double
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;
const int N = 200500;
int H[N];
vector<int> g[N];
bitset<N> used;
int maxh[N];
int vl[N];
int ans = 0;
int rt = 0;
int biba = 0;

void dfs(int v) {
  used[v] = true;
  maxh[v] = H[v];
  for (auto u : g[v]) {
    if (!used[u]) {
      dfs(u);
      maxh[v] = max(maxh[v], maxh[u]);
    }
  }
}

void dfs2(int v) {
  used[v] = true;
  vector<int> sons;
  for (auto u : g[v]) {
    if (!used[u]) {
      used[u] = true;
      sons.pb(u);
    }
  }
  int m = 0;
  for (auto x : sons) {
    m = max(m, maxh[x]);
  }
  int c = 0;
  for (auto x : sons) {
    if (maxh[x] == m) {
      c++;
    }
  }
  if (c > 1) {
    for (auto x : sons) {
      vl[x] = max({vl[v], H[v], m});
    }
  } else {
    for (auto x : sons) {
      if (maxh[x] != m) {
        vl[x] = max({H[v], vl[v], m});
      } else {
        int mem = 0;
        for (auto y : sons) {
          if (x != y) {
            mem = max(mem, maxh[y]);
          }
        }
        vl[x] = max({H[v], vl[v], mem});
      }
    }
  }
  for (auto x : sons) {
    dfs2(x);
  }
}

void dfs3(int v) {
  used[v] = true;
  vector<int> dud;
  if (v != rt) {
    dud.pb(vl[v]);
  }
  for (auto u : g[v]) {
    if (!used[u]) {
      dfs3(u);
      dud.pb(maxh[u]);
    }
  }
  sort(rall(dud));
  if ((int) g[v].size() == 1) {
    dud.pb(H[v]);
  }
  if ((int) dud.size() > 1) {
    ans += max(0LL, H[v] - dud[0]);
    ans += max(0LL, H[v] - dud[1]);
  }
}


signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> H[i];
  }
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].pb(b);
    g[b].pb(a);
  }
  if (n == 2) {
    cout << 2 * max(H[0], H[1]) << '\n';
    exit(0);
  }
  for (int _ = 0; _ < 4; _++) {
    ans = 0;
    for (int v = 0; v < n; v++) {
      if ((int) g[v].size() == 1) {
        ans += H[v];
      }
    }
    rt = rand() % n;
    while ((int) g[rt].size() == 1) {
      rt = rand() % n;
    }
    vl[rt] = (int) -1e9;
    dfs(rt);
    used.reset();
    dfs2(rt);
    used.reset();
    dfs3(rt);
    used.reset();
    biba = max(biba, ans);
  }
  cout << biba << '\n';

}