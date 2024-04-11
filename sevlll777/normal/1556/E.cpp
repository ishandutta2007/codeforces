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
const int N = 100500;
const int L = 20;
int ST1[N][L], ST2[N][L];
int LOG[N];

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<int> A(n), B(n), D(n), P(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> B[i];
    D[i] = A[i] - B[i];
    if (i > 0) {
      P[i] = D[i] + P[i - 1];
    } else {
      P[i] = D[i];
    }
  }
  for (int i = 0; i < n; i++) {
    ST1[i][0] = ST2[i][0] = P[i];
  }
  for (int i = 2; i < N; i++) {
    LOG[i] = 1 + LOG[i / 2];
  }
  for (int l = 1; l < L; l++) {
    for (int i = 0; i < n; i++) {
      if ((i + (1 << (l - 1))) < n) {
        ST1[i][l] = min(ST1[i][l - 1], ST1[i + (1 << (l - 1))][l - 1]);
        ST2[i][l] = max(ST2[i][l - 1], ST2[i + (1 << (l - 1))][l - 1]);
      } else {
        ST1[i][l] = ST1[i][l - 1];
        ST2[i][l] = ST2[i][l - 1];
      }
    }
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    int lg = LOG[r - l + 1];
    int mn = min(ST1[l][lg], ST1[r - (1 << lg) + 1][lg]);
    int mx = max(ST2[l][lg], ST2[r - (1 << lg) + 1][lg]);
    if (l > 0) {
      mn -= P[l - 1];
      mx -= P[l - 1];
    }
    if (mx <= 0 && ((l > 0 && P[r] == P[l-1]) || (l == 0 && P[r] == 0))) {
      cout << -mn << '\n';
    } else {
      cout << "-1\n";
    }
  }

}