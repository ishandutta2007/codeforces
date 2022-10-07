#include <cstdio>

const int MAXN = 100100;
int N;

int par[MAXN];
int ar[MAXN];
int sz[MAXN];

int find(int x) {
  if (par[x] == x) return x;
  return par[x] = find(par[x]);
}

void join(int a, int b) {
  a = find(a);
  b = find(b);
  if (a == b) return;
  par[a] = b;
  sz[b] += sz[a];
}

int main() {
  scanf("%d", &N);
  for(int i = 1; i <= N; ++i) {
    par[i] = i;
    sz[i] = 1;
    scanf("%d", ar + i);
  }

  for(int i = 1; i <= N; ++i) {
    join(i, ar[i]);
  }

  for(int i = 1; i <= N; ++i) {
    if (par[i] != i) continue;
    if (sz[i] == 1) {
      printf("YES\n");
      for(int j = 1; j <= N; ++j) {
        if (i != j) {
          printf("%d %d\n", i, j);
        }
      }
      return 0;
    }
  }

  int center = 0;
  for(int i = 1; i <= N; ++i) {
    if (par[i] != i) continue;
    if (sz[i] % 2 != 0) {
      printf("NO\n");
      return 0;
    }
    if (sz[i] == 2) {
      center = i;
    }
  }
  if (!center) {
    printf("NO\n");
    return 0;
  }

  printf("YES\n");
  int ocenter = ar[center];
  printf("%d %d\n", center, ocenter);
  for(int i = 1; i <= N; ++i) {
    if (par[i] == i && find(i) != center) {
      int cur = i;
      do {
        printf("%d %d\n", center, cur);
        cur = ar[cur];
        printf("%d %d\n", ocenter, cur);
        cur = ar[cur];
      } while (cur != i);
    }
  }
  return 0;
}