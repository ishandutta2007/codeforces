#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
const int MAXP = 7;
const int MAXN = 100100;
const ll infl = 1LL << 60;
int mat[MAXN][MAXP];
int aud[MAXN];

pii srt[MAXN];
ll dp[1 << MAXP][2];
int main() {
  int N, P, K;
  cin >> N >> P >> K;
  for (int i = 0; i < N; ++i) {
    cin >> aud[i];
    srt[i] = pii(-aud[i], i);
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < P; ++j) {
      cin >> mat[i][j];
    }
  }
  for (int i = 0; i < 1 << P; ++i) {
    dp[i][0] = dp[i][1] = -infl;
  }
  dp[0][0] = 0;
  sort(srt, srt + N);
  for (int i = 0; i < N; ++i) {
    int cur = srt[i].second;
    for (int j = 0; j < 1 << P; ++j) {
      int cnt = K - i;
      for (int k = 0; k < P; ++k) {
        if (j & (1 << k)) {
          ++cnt;
          continue;
        }
        int nj = j | (1 << k);
        dp[nj][(i + 1) % 2] = max(dp[nj][(i + 1) % 2], dp[j][i % 2] + mat[cur][k]);
      }
      if (cnt > 0) {
        dp[j][(i + 1) % 2] = max(dp[j][(i + 1) % 2], dp[j][i % 2] + aud[cur]);
      } else {
        dp[j][(i + 1) % 2] = max(dp[j][(i + 1) % 2], dp[j][i % 2]);
      }

    }
  }
  cout << dp[(1 << P) - 1][N % 2] << "\n";
}