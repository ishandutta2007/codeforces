#include <cstdio>

const int MAXN = 33;
const int MAXK = 222;

double DP[MAXN][MAXN][MAXK]; // DP[a][b]: prob[ inv(a, b)] after k

int rev(int x, int a, int b) {
  if (x < a || x > b) return x;
  return a + b - x;
}

int P[MAXN];
int N, K;
int main() {
  scanf("%d %d", &N, &K);
  for(int i = 0; i < N; ++i) {
    scanf("%d", P + i);
  }

  for(int k = 0; k < K; ++k) {
    for(int i = 0; i < N; ++i) {
      for(int j = i + 1; j < N; ++j) {
        int cnt = 0;
        double p = 0;
        for(int a = 0; a < N; ++a) {
          for(int b = a; b < N; ++b) {
            int ni = rev(i, a, b);
            int nj = rev(j, a, b);
            if (ni < nj) {
              p += DP[ni][nj][k];
            } else {
              p += 1 - DP[nj][ni][k];
            }
            ++cnt;
          }
        }

        DP[i][j][k + 1] = p / cnt;
      }
    }
  }

  double ans = 0;
  for(int i = 0; i < N; ++i) {
    for(int j = i + 1; j < N; ++j) {
      if (P[i] < P[j]) {
        ans += DP[i][j][K];
      } else {
        ans += 1 - DP[i][j][K];
      }
    }
  }


  printf("%.10lf\n", ans);
}