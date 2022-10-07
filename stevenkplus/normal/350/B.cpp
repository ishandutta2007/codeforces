#include <cstdio>

const int MAXN = 100100;

int N;
int par[MAXN];
int ch[MAXN];
int deg[MAXN];
int type[MAXN];

int ans = 0, best;
int main() {
  scanf("%d", &N);

  for(int i = 1; i <= N; ++i) {
    scanf("%d", type + i);
  }
  
  for(int i = 1; i <= N; ++i) {
    scanf("%d", par + i);
    ++deg[par[i]];
    ch[par[i]] = i;
  }

  for(int i = 1; i <= N; ++i) {
    if (type[i] == 1) {
      int len = 1;
      int cur = i;
      while (par[cur] && deg[par[cur]] == 1) {
        cur = par[cur];
        ++len;
      }
      if (len > ans) {
        ans = len;
        best = cur;
      }
    }
  }

  printf("%d\n", ans);
  int cur = best;
  bool first = true;
  while (cur) {
    if (!first) printf(" ");
    first = false;
    printf("%d", cur);
    cur = ch[cur];
  }
  printf("\n");
}