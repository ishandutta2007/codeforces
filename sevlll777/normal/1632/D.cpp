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
const int L = 21;
int A[N];
int ST[N][L];
int LG[N];

int q(int l, int r) {
  int len = r - l + 1;
  int lg = LG[len];
  return gcd(ST[l][lg], ST[r - (1 << lg) + 1][lg]);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  for (int x = 2; x < N; x++) {
    LG[x] = LG[x / 2] + 1;
  }
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < n; i++) {
    ST[i][0] = A[i];
  }
  for (int l = 1; l < L; l++) {
    for (int i = 0; i < n; i++) {
      ST[i][l] = ST[i][l - 1];
      if ((i + (1 << (l - 1))) < n) {
        ST[i][l] = gcd(ST[i][l], ST[i + (1 << (l - 1))][l - 1]);
      }
    }
  }
  vector<int> lol(n, -1);
  for (int s = 0; s < n; s++) {
    int l = 0, r = n - s + 1;
    while (r - l > 1) {
      int len = (l + r) / 2;
      int s2 = s + len - 1;
      int gg = q(s, s2);
      if (gg > len) {
        l = len;
      } else {
        r = len;
      }
    }
    int len = l + 1;
    int s2 = s + len - 1;
    if (q(s, s2) == len) {
      lol[s2] = max(lol[s2], s);
    }
  }
  for (int i = 1; i < n; i++) {
    lol[i] = max(lol[i], lol[i - 1]);
  }
  vector<int> dp(n);
  dp[0] = (A[0] == 1);
  for (int i = 1; i < n; i++) {
    int s = lol[i];
    if (s == -1) {
      dp[i] = 0;
    } else {
      if (s) {
        dp[i] = 1 + dp[s - 1];
      } else {
        dp[i] = 1;
      }
    }
  }
  for (auto x : dp) {
    cout << x << '\n';
  }

}