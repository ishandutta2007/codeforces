#include <cstdio>

const int MAXK = 555;
const int MAXN = 100100;
const int inf = 1 << 29;
int par[MAXN];
int find(int x) {
  if (par[x] == x) return x;
  else return par[x] = find(par[x]);
}
void join(int a, int b) {
  a = find(a);
  b = find(b);
  par[a] = b;
}

int N, M, K;

int C[MAXK];
int type[MAXN];
int adj[MAXK][MAXK];

int main() {
  scanf("%d %d %d", &N, &M, &K);
  for(int i = 1; i <= N; ++i) {
    par[i] = i;
  }
  for(int i = 0; i < K; ++i) {
    for(int j = 0; j < K; ++j) {
      adj[i][j] = inf;
    }
    adj[i][i] = 0;
  }

  int cur = 1;
  for(int i = 0; i < K; ++i) {
    scanf("%d", C + i);
    for(int k = 0; k < C[i]; ++k) {
      type[cur] = i;
      ++cur;
    }
  }

  for(int i = 0; i < M; ++i) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (c == 0) {
      join(a, b);
    }
    a = type[a];
    b = type[b];
    if (c < adj[a][b]) adj[a][b] = c;
    if (c < adj[b][a]) adj[b][a] = c;
  }

  bool good = true;
  cur = 1;
  for(int i = 0; i < K; ++i) {
    int j = find(cur);
    for(int k = 0; k < C[i]; ++k) {
      if (find(cur) != j) {
        good = false;
      }
      ++cur;
    }
  }

  if (!good) {
    printf("No\n");
    return 0;
  }

  printf("Yes\n");
  for(int k = 0; k < K; ++k) {
    for(int i = 0; i < K; ++i) {
      for(int j = 0; j < K; ++j) {
        int nd = adj[i][k] + adj[j][k];
        if (nd < adj[i][j]) adj[i][j] = nd;
      }
    }
  }

  for(int i = 0; i < K; ++i) {
    for(int j = 0; j < K; ++j) {
      if (adj[i][j] == inf) adj[i][j] = -1;
      printf("%d ", adj[i][j]);
    }
    printf("\n");
  }
  return 0;
}