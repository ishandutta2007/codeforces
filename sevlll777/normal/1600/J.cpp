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
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;


signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> A(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> A[i][j];
    }
  }
  vector<vector<int>> g(n * m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      A[i][j] = 15 - A[i][j];
      if (i != 0) {
        if (A[i][j] >= 8) {
          A[i][j] -= 8;
          g[i * m + j].pb((i - 1) * m + j);
          g[(i - 1) * m + j].pb(i * m + j);
        }
      }
      if (j != m - 1) {
        if (A[i][j] >= 4) {
          A[i][j] -= 4;
          g[i * m + j].pb(i * m + j + 1);
          g[i * m + j + 1].pb(i * m + j);
        }
      }
      if (i != n - 1) {
        if (A[i][j] >= 2) {
          A[i][j] -= 2;
          g[i * m + j].pb((i + 1) * m + j);
          g[(i + 1) * m + j].pb(i * m + j);
        }
      }
      if (j != 0) {
        if (A[i][j] >= 1) {
          A[i][j] -= 1;
          g[i * m + j].pb(i * m + j - 1);
          g[i * m + j - 1].pb(i * m + j);
        }
      }
    }
  }
  vector<bool> used(n * m, false);
  vector<int> ans;
  for (int v = 0; v < n * m; v++) {
    if (!used[v]) {
      used[v] = true;
      int kek = 1;
      vector<int> st = {v};
      while (!st.empty()) {
        int u = st.back();
        st.pop_back();
        for (auto uu : g[u]) {
          if (!used[uu]) {
            used[uu] = true;
            st.pb(uu);
            kek++;
          }
        }
      }
      ans.pb(kek);
    }
  }
  sort(rall(ans));
  for (auto x : ans) {
    cout << x << ' ';
  }
}