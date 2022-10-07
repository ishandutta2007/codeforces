#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 222;
const int MAXK = 1111;
const int M = 1E9 + 7;

int ar[MAXN];
ll DP[MAXN][MAXK]; // DP[x][y] = #ways to have x open parens, cursum of y
ll nDP[MAXN][MAXK];
int N, K;

inline void upd(int x, int y, ll val) {
  if (x >= 0 && y < MAXK) {
    nDP[x][y] += val;
    nDP[x][y] %= M;
  }
}

int main() {
  scanf("%d %d", &N, &K);
  for(int i = 0; i < N; ++i) {
    scanf("%d", ar + i);
  }
  sort(ar, ar + N);

  DP[0][0] = 1;
  for(int i = 0; i < N; ++i) {
    int diff = 0;
    if (i > 0) diff = ar[i] - ar[i - 1];
    for(int x = 0; x <= i; ++x) {
      for(int y = 0; y <= K; ++y) {
        ll cur = DP[x][y];
        int ny = y + x * diff;
        { // singleton
          upd(x, ny, cur);
        }
        { // open paren
          upd(x + 1, ny, cur);
        }
        { // middle
          upd(x, ny, cur * x % M);
        }
        { // close paren
          upd(x - 1, ny, cur * x % M);
        }
      }
    }

    for(int x = 0; x < MAXN; ++x) {
      for(int y = 0; y < MAXK; ++y) {
        DP[x][y] = nDP[x][y];
        nDP[x][y] = 0;
      }
    }
  }

  ll ans = 0;
  for(int i = 0; i <= K; ++i) {
    ans += DP[0][i];
    ans %= M;
  }

  cout << ans << "\n";
}