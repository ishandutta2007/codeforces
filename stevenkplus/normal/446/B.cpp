#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

const ll infl = 1LL << 60;
const int MAXN = 1111;
const int MAXK = 1001000;

int grid[MAXN][MAXN];
ll bestr[MAXK];
ll bestc[MAXK];
int rsum[MAXN];
int csum[MAXN];

int N, M, P, K;

int main() {
  priority_queue<int> rsums, csums;

  scanf("%d %d %d %d", &N, &M, &K, &P);

  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < M; ++j) {
      scanf("%d", grid[i] + j);
      rsum[i] += grid[i][j];
      csum[j] += grid[i][j];
    }
  }

  for(int i = 0; i < N; ++i) {
    rsums.push(rsum[i]);
  }

  for(int i = 0; i < M; ++i) {
    csums.push(csum[i]);
  }

  ll curr = 0;
  for(int i = 1; i <= K; ++i) {
    int nxtr = rsums.top(); rsums.pop();
    curr += nxtr;
    bestr[i] = curr;
    rsums.push(nxtr - P * M);
  }

  ll curc = 0;
  for(int i = 1; i <= K; ++i) {
    int nxtc = csums.top(); csums.pop();
    curc += nxtc;
    bestc[i] = curc;
    csums.push(nxtc - P * N);
  }

  ll ans = -infl;
  for(int i = 0; i <= K; ++i) {
    int j = K - i;
    ll val = bestr[i] + bestc[j] - ll(i) * j * P;
    if (val > ans) ans = val;
  }

  cout << ans << "\n";
  return 0;
}