#include <cstdio>
#include <cctype>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;
using ll = long long;

#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

const int N = 505;
int n, m, M;
int Cnt[N], Sum[N], cnt[N][N], sum[N][N]; // Cnt for n = m
int C[N][N];

int main() {
  scanf("%d%d%d", &n, &m, &M);
  for (int i = 1; i <= n; ++i)
  C[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= i; ++j)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % M;
  }
  Cnt[1] = 2; Cnt[0] = 1;
  Sum[1] = 0; Sum[0] = 0;
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      Cnt[i] = (Cnt[i] + 1LL * Cnt[j - 1] * Cnt[i - j] % M * C[i - 1][j - 1]) % M;
      Sum[i] = (Sum[i] + 1LL * (1LL * Sum[j - 1] * Cnt[i - j] + 1LL * Sum[i - j] * Cnt[j - 1]) % M * (i + 1) % M * C[i - 1][j - 1]) % M;
      Sum[i] = (Sum[i] + 1LL * Cnt[j - 1] * Cnt[i - j] % M * C[i - 1][j - 1] % M * (C[j][2] + C[i - j + 1][2])) % M;
    }
    Cnt[i] = 1LL * Cnt[i] * (i + 1) % M;
  }
  cnt[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    cnt[i][0] = 1;
    for (int j = 1; j <= min(i - 1, m); ++j)
      for (int l = 0; l <= j; ++l) {
        cnt[i][j] = (cnt[i][j] + 1LL * Cnt[l] * cnt[i - l - 1][j - l] % M * C[j][l]) % M;
        sum[i][j] = (sum[i][j] + (1LL * Cnt[l] * sum[i - l - 1][j - l] + 1LL * Sum[l] * cnt[i - l - 1][j - l]) % M * C[j][l]) % M;
      }
    cnt[i][i] = Cnt[i];
    sum[i][i] = Sum[i];
  }
  printf("%d\n", sum[n][m]);
  return 0;
}