#include <cstdio>

const int MAXN = 111;
int T;
int N, P;

bool adj[MAXN][MAXN];

void join(int a, int b) {
  b %= N;
  adj[a][b] = adj[b][a] = true;
}


int main() {
  scanf("%d", &T);
  for(int t = 0; t < T; ++t) {
    scanf("%d %d", &N, &P);
    for(int i = 0; i < N; ++i) {
      for(int j = 0; j < N; ++j) {
        adj[i][j] = false;
      }
      adj[i][i] = true;
    }

    for(int i = 0; i < N; ++i) {
      join(i, i + 1);
      join(i, i + 2);
    }

    for(int i = 0; i < N; ++i) {
      for(int j = i + 1; j < N; ++j) {
        if (!adj[i][j] && P) {
          join(i, j);
          --P;
        }
      }
    }

    for(int i = 0; i < N; ++i) {
      for(int j = i + 1; j < N; ++j) {
        if (adj[i][j]) {
          printf("%d %d\n", i + 1, j + 1);
        }
      }
    }
  }
return 0;
}