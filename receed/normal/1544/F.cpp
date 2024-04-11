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

const int MOD = 31607, N = 21, P = 1 << N;
int a[N][N], b[N][N], pr[N][P], pv[N];

int pw(int x, int k) {
  int r = 1;
  while (k) {
    if (k & 1)
      r = r * x % MOD;
    x = x * x % MOD;
    k >>= 1;
  }
  return r;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, x, r = pw(10000, MOD - 2);
  cin >> n;
  rep(i, n)
    rep(j, n) {
      cin >> x;
      a[i][j] = x * r % MOD;
    }
  int ans = 0;
  int pw = 1 << n;
  rep(q1, 2)
    rep(q2, 2) {
      rep(i, n)
        rep(j, n)
          b[i][j] = a[i][j];
      int cm = 1;
      if (q1)
        rep(i, n) {
          cm = cm * b[i][i] % MOD;
          b[i][i] = 1;
        }
      if (q2)
        rep(i, n) {
          cm = cm * b[i][n - 1 - i] % MOD;
          b[i][n - 1 - i] = 1;
        }
      rep(i, n)
        pv[i] = 1;
      rep(i, n)
        rep(j, n)
          pv[j] = pv[j] * b[i][j] % MOD;

      rep(i, n) {
        pr[i][0] = 1;
        rep(j, n)
          pr[i][1 << j] = b[i][j];
        for (int j = 1; j < pw; ++j) {
          int x = j & (j - 1);
          pr[i][j] = pr[i][x] * pr[i][j ^ x] % MOD;
        }
        rep(j, pw) {
          pr[i][j] = (-pr[i][j] + MOD + 1) % MOD;
        }
      }
      int sg = (q1 * 2 - 1) * (q2 * 2 - 1) * cm;
      sg = (sg + MOD) % MOD;
      rep(i, pw) {
        int cp = sg, ss = 1;
        int x = i ^ (pw - 1);
        rep(j, n) {
          if ((i >> j) & 1) {
            cp = cp * pv[j] % MOD;
            ss = -ss;
          }
          cp = cp * pr[j][x] % MOD;
        }
        cp = cp * (MOD + ss) % MOD;
        ans = (ans + cp) % MOD;
      }
    }
  cout << (MOD + 1 - ans) % MOD << '\n';
}