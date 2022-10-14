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
// #define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;
const int N = 300500;
const int L = 22;
const long long M = 998244353;
int par[N];
int up[N][L];
int sz[N];

void merge(int a, int b) {
  if (sz[a] <= sz[b]) {
    par[a] = b;
    sz[b] += sz[a];
  } else {
    par[b] = a;
    sz[a] += sz[b];
  }
}

int parent(int a) {
  if (a == par[a]) return a;
  return par[a] = parent(par[a]);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  for (int i = 0; i < N; i++) {
    par[i] = i;
    sz[i] = 1;
  }
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> A;
  for (int _ = 0; _ < n; _++) {
    int l;
    cin >> l;
    vector<int> B(l);
    for (int i = 0; i < l; i++) {
      cin >> B[i];
    }
    A.pb(B);
  }
  for (auto B : A) {
    for (int i = 0; i < (int) B.size() - 1; i++) {
      merge(parent(B[i]), parent(B[i + 1]));
    }
  }
  vector<bool> ban(k + 1, false);
  vector<int> next(k + 1, -1);
  vector<int> prev(k + 1, -1);
  for (auto B : A) {
    for (int i = 0; i < (int) B.size() - 1; i++) {
      if (next[B[i]] == -1) {
        next[B[i]] = B[i + 1];
      } else if (next[B[i]] != B[i + 1]) {
        ban[parent(B[i])] = true;
      }
    }
    for (int i = 0; i < (int) B.size() - 1; i++) {
      if (prev[B[i + 1]] == -1) {
        prev[B[i + 1]] = B[i];
      } else if (prev[B[i + 1]] != B[i]) {
        ban[parent(B[i + 1])] = true;
      }
    }
    vector<int> B2 = B;
    sort(all(B2));
    for (int i = 0; i < (int) B2.size() - 1; i++) {
      if (B2[i] == B2[i + 1]) {
        ban[parent(B2[i])] = true;
      }
    }
  }
  for (int i = 1; i <= k; i++) {
    if (ban[parent(i)]) {
      ban[i] = true;
    }
    //cout << ban[i];
  }
  for (int i = 1; i <= k; i++) {
    if (!ban[i]) {
      if (next[i] != -1) {
        up[i][0] = next[i];
      } else {
        up[i][0] = i;
      }
    }
  }
  for (int l = 1; l < L; l++) {
    for (int i = 1; i <= k; i++) {
      if (!ban[i]) {
        up[i][l] = up[up[i][l - 1]][l - 1];
      }
    }
  }
  for (int i = 1; i <= k; i++) {
    if (!ban[i]) {
      if (next[up[i][L - 1]] != -1) {
        ban[i] = true;
      }
    }
  }
  vector<int> aboba;
  for (int i = 1; i <= k; i++) {
    if (!ban[i] && prev[i] == -1) {
      int j = i;
      int kek = 1;
      for (int l = L - 1; l >= 0; l--) {
        if (next[up[j][l]] != -1) {
          j = up[j][l];
          kek += (1 << l);
        }
      }
      if (next[j] != -1) {
        kek++;
      }
      aboba.pb(kek);
    }
  }
  vector<int> boba;
  int s = (int) sqrt(n);
  vector<long long> cnt(s + 1);
  for (auto x : aboba) {
    if (x <= s) {
      cnt[x]++;
    } else {
      boba.pb(x);
    }
  }
  vector<long long> dp(m + 1);
  dp[0] = 1;
  for (int i = 1; i <= m; i++) {
    for (int x = 1; x <= min(i, s); x++) {
      dp[i] += (cnt[x] * dp[i - x]) % M;
    }
    for (auto x : boba) {
      if (i >= x) {
        dp[i] += dp[i - x];
      }
    }
    dp[i] %= M;
  }
  cout << dp[m] << '\n';
}