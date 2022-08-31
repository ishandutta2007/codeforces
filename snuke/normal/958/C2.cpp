#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <array>
#include <list>
#include <stack>
#include <valarray>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef unsigned long long UInt;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }
int in() { int x; scanf("%d", &x); return x; }
double fin() { double x; scanf("%lf", &x); return x; }
Int lin() { Int x; scanf("%lld", &x); return x; }

int dp[20002][55][101], mo[202];

int main() {
  int N = in();
  int K = in();
  int P = in();
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    A[i] = in() % P;
  }
  for (int i = 0; i < 2 * P; ++i) {
    mo[i] = i % P;
  }

  memset(dp, -1, sizeof(dp));
  dp[1][0][A[0]] = 0;
  for (int i = 1; i < N; ++i) {
    for (int k = 0; k < K; ++k) {
      for (int p = 0; p < P; ++p) {
        if (dp[i][k][p] >= 0) {
          chmax(dp[i + 1][k + 1][A[i]], dp[i][k][p] + p);
          chmax(dp[i + 1][k][mo[p + A[i]]], dp[i][k][p]);
        }
      }
    }
  }

  int res = 0;
  for (int p = 0; p < P; ++p) {
    chmax(res, dp[N][K - 1][p] + p);
  }

  printf("%d\n", res);

  return 0;
}