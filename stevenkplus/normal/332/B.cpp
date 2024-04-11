#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;
const int MAXN = 200100;

int N, K;

int ar[MAXN];
ll sums[MAXN];

int main() {
  scanf("%d %d", &N, &K);
  for(int i = 0; i < N; ++i) {
    scanf("%d", ar + i);
  }

  for(int i = 0; i < K; ++i) {
    sums[0] += ar[i];
  }
  for(int i = 0; i + K < N; ++i) {
    sums[i + 1] = sums[i] + ar[i + K] - ar[i];
  }


  ll bst = 0;
  ll bx = 0;
  ll ans = 0;
  ll ax = 0, ay = 0;
  for(int i = K; i + K <= N; ++i) {
    if (sums[i - K] > bst) bst = sums[i - K], bx = i - K;
    ll val = sums[i] + bst;
    if (val > ans) ans = val, ax = bx, ay = i;
  }
  cout << ax + 1 << " " << ay + 1 << "\n";
  return 0;
}