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

int N, M, A[200050], K[200050], done[200050], all_cnt[200050];
vector<int> pos[200050];

int main() {
  N = in();
  M = in();
  for (int i = 0; i < N; ++i) {
    A[i] = in() - 1;
    ++all_cnt[A[i]];
    pos[A[i]].push_back(i);
  }
  int to = 0, s = 0;
  for (int i = 0; i < M; ++i) {
    K[i] = in();
    if (K[i] > all_cnt[i]) {
      puts("-1");
      return 0;
    }
    s += K[i];
    if (K[i] != 0) {
      chmax(to, pos[i][K[i] - 1]);
    }
  }

  int res = INF;
  for (int i = 0; i < N; ++i) {
    const int c = A[i];
    chmin(res, to - i + 1);
    ++done[c];
    if (K[c] != 0) {
      if (K[c] + done[c] > all_cnt[c]) {
        break;
      }
      chmax(to, pos[c][K[c] + done[c] - 1]);
    }
  }

  printf("%d\n", res - s);

  return 0;
}