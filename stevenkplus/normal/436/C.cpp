#include <cstdio>

const int MAXN = 1010;
const int MAXM = 11;

int dist[MAXN][MAXN];
char ar[MAXN][MAXM][MAXM];

int dst[MAXN];
int frm[MAXN];
bool vis[MAXN];

int N, M, K, W;

int ord[MAXN];
int prim() {
  for(int i = 0; i < K; ++i) {
    dst[i] = N * M;
  }

  frm[0] = 0;
  int sum = 0;
  for(int k = 0; k < K; ++k) {
    int bst = -1;
    for(int i = 0; i < K; ++i) {
      if (!vis[i]) {
        if (bst == -1 || dst[i] < dst[bst]) {
          bst = i;
        }
      }
    }
    ord[k] = bst;

    vis[bst] = true;
    sum += dst[bst];
    for(int i = 0; i < K; ++i) {
      if (!vis[i] && dist[bst][i] < dst[i]) {
        dst[i] = dist[bst][i];
        frm[i] = bst + 1;
      }
    }
  }

  return sum;
}

int comp(int a, int b) {
  int diff = 0;
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < M; ++j) {
      if (ar[a][i][j] != ar[b][i][j]) ++diff;
    }
  }
  return diff * W;
}

int main() {
  scanf("%d %d %d %d", &N, &M, &K, &W);
  for(int i = 0; i < K; ++i) {
    for(int j = 0; j < N; ++j) {
      scanf("%s", ar[i][j]);
    }
  }
  for(int i = 0; i < K; ++i) {
    for(int j = 0; j < K; ++j) {
      dist[i][j] = comp(i, j);
    }
  }

  int ans = prim();
  printf("%d\n", ans);
  for(int i = 0; i < K; ++i) {
    printf("%d %d\n", ord[i] + 1, frm[ord[i]]);
  }
  return 0;
}