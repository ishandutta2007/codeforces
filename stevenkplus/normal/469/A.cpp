#include <cstdio>

const int MAXN = 100100;

bool vis[MAXN];
int N, M;

int main() {
  scanf("%d", &N);
  int a, b;
  scanf("%d", &a);
  for(int i = 0; i < a; ++i) {
    int x;
    scanf("%d", &x);
    vis[x] = true;
  }

  scanf("%d", &b);
  for(int i = 0; i < b; ++i) {
    int x;
    scanf("%d", &x);
    vis[x] = true;
  }

  bool good = true;
  for(int i = 1; i <= N; ++i) {
    if (!vis[i]) {
      good = false;
    }
  }

  if (good) {
    printf("I become the guy.\n");
  } else {
    printf("Oh, my keyboard!\n");
  }
}