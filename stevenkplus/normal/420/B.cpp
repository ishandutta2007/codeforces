#include <cstdio>

const int MAXN = 100100;

int cnt, N, M;
bool bad[MAXN];
bool vis[MAXN];

int ar[MAXN];

int main() {
  scanf("%d %d", &N, &M);
  int init = 0;
  for(int i = 0; i < M; ++i) {
    char c;
    int x;
    scanf(" %c %d", &c, &x);
    if (c == '+') {
      ar[i] = x;
    } else {
      ar[i] = -x;
    }
    if (!vis[x]) {
      vis[x] = true;
      if (c == '-') ++init;
    }
  }

  int cnt = init;
  for(int i = 0; i < M; ++i) {
    if (ar[i] > 0) {
      if ((i == 0 || ar[i - 1] + ar[i] == 0) && cnt == 0) {
        // good;
      } else {
        bad[ar[i]] = true;
      }
      ++cnt;
    } else {
      --cnt;
      if ((i + 1 == M || ar[i] + ar[i + 1] == 0) && cnt == 0) {
        // good;
      } else {
        bad[-ar[i]] = true;
      }
    }
  }

  int ans = 0;
  for(int i = 1; i <= N; ++i) {
    if (!bad[i]) ++ans;
  }
  printf("%d\n", ans);
  for(int i = 1; i <= N; ++i) {
    if (!bad[i]) {
      printf("%d ", i);
    }
  }
  printf("\n");
  return 0;
}