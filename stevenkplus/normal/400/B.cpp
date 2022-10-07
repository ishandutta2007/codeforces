#include <cstdio>

const int MAXN = 1010;
int N, M;
char str[MAXN];
bool vis[MAXN];

int go() {
  scanf("%s", str);
  int state = 0;
  int run = 0;
  int ans = 0;
  for(int i = 0; i < M; ++i) {
    if (str[i] == '*') {
      ++run;
    } else if (str[i] == 'G') {
      if (state == 0) {
        state = 1;
        run = 0;
      } else ++run;
    } else {
      if (state == 1) {
        if (run > ans) ans = run;
        state = 0;
      }
    }
  }
  if (state == 1) return -1;
  return ans;
}

int main() {
  scanf("%d %d", &N, &M);
  int ans = 0;
  for(int i = 0; i < N; ++i) {
    int x = go();
    if (x == -1) {
      ans = -1;
      break;
    } else {
      if (vis[x]) continue;
      vis[x] = true;
      ++ans;
    }
  }

  printf("%d\n", ans);
  return 0;
}