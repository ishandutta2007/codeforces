#include <cstdio>

const int MAXN = 20100;
const int MAXM = 111;


int ans[MAXN];
int cnt[MAXM];

int good[MAXN][MAXM];

int N, M, K;

int main() {
  scanf("%d %d %d", &N, &M, &K);
  for(int i = 1; i <= N; ++i) {
    for(int j = 1; j <= M; ++j) {
      scanf("%d", good[i] + j);
    }
  }
  for(int i = 0; i < K; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    --ans[x];
    ++cnt[y];
  }
  for(int i = 1; i <= N; ++i) {
    for(int j = 1; j <= M; ++j) {
      if (good[i][j]) ans[i] += cnt[j];
    }
    printf("%d ", ans[i]);
  }

}