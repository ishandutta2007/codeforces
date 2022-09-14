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

const int N = 200001;
set<int> g[N];
int d[N], ans;


void add(int u, int v) {
  if (u > v)
    swap(u, v);
  d[u]++;
  if (d[u] == 1)
    ans--;
}

void del(int u, int v) {
  if (u > v)
    swap(u, v);
  d[u]--;
  if (d[u] == 0)
    ans++;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m, u, v, t;
  cin >> n >> m;
  ans = n;
  rep(i, m) {
    cin >> u >> v;
    add(u, v);
  }
  int q;
  cin >> q;
  rep(i, q) {
    cin >> t;
    if (t == 3)
      cout << ans << '\n';
    else {
      cin >> u >> v;
      if (t == 1)
        add(u, v);
      else
        del(u, v);
    }
  }
}