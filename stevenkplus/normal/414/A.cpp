#include <cstdio>
#include <map>

using namespace std;

const int MAXN = 100100;

int ans[MAXN];
map<int, int> vis;

int N, K;

int main() {
  scanf("%d %d", &N, &K);
  int parts = N / 2;
  int first = K - parts + 1;
  if (first < 1) {
    printf("-1\n");
    return 0;
  }
  if (N == 1) {
    if (K == 0) {
      printf("1\n");
    } else {
      printf("-1\n");
    }
    return 0;
  }

  for(int i = 1; i <= N; ++i) {
    ans[i] = i;
  }
  ans[1] *= first;
  ans[2] *= first;
  int nxt = N + 1;
  for(int i = 1; i <= N; i += 2) {
    while (vis[ans[i]] || vis[ans[i + 1]]) {
      ans[i] = nxt;
      ans[i + 1] = nxt + 1;
      nxt += 2;
    }
    vis[ans[i]] = true;
    vis[ans[i + 1]] = true;
  }

  for(int i = 1; i <= N; ++i) {
    printf("%d ", ans[i]);
  }
  printf("\n");
  return 0;
}