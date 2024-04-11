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
const int N = 200500;
set<int> F[N];
int mxx[N];
int cnt = 0;

void add_edge(int a, int b) {
  if (mxx[a] < a) cnt--;
  if (mxx[b] < b) cnt--;
  F[a].insert(b);
  F[b].insert(a);
  mxx[a] = *F[a].rbegin();
  mxx[b] = *F[b].rbegin();
  if (mxx[a] < a) cnt++;
  if (mxx[b] < b) cnt++;
}

void del_edge(int a, int b) {
  if (mxx[a] < a) cnt--;
  if (mxx[b] < b) cnt--;
  F[a].erase(b);
  F[b].erase(a);
  if (!F[a].empty()) {
    mxx[a] = *F[a].rbegin();
  } else {
    mxx[a] = 0;
  }
  if (!F[b].empty()) {
    mxx[b] = *F[b].rbegin();
  } else {
    mxx[b] = 0;
  }
  if (mxx[a] < a) cnt++;
  if (mxx[b] < b) cnt++;
}

void solve() {
  int n, m;
  cin >> n >> m;
  cnt = n;
  for (int _ = 0; _ < m; _++) {
    int a, b;
    cin >> a >> b;
    add_edge(a, b);
  }
  int q;
  cin >> q;
  while (q--) {
    int tp;
    cin >> tp;
    if (tp == 3) {
      cout << cnt << '\n';
    } else {
      int a, b;
      cin >> a >> b;
      if (tp == 1) {
        add_edge(a, b);
      } else {
        del_edge(a, b);
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  while (t--) {
    solve();
  }
}