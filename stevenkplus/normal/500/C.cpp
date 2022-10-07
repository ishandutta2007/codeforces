#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 510;
int N, M;

bool vis[MAXN];
int W[MAXN];
int cur[MAXN];

int main() {
  scanf("%d %d", &N, &M);
  for(int i = 1; i <= N; ++i) {
    scanf("%d", W + i);
  }

  int sum = 0;
  int len = 0;
  for(int i = 0; i < M; ++i) {
    int nxt;
    scanf("%d", &nxt);
    if (!vis[nxt]) {
      cur[len] = nxt;
      ++len;
      vis[nxt] = 1;
    }

    int j;
    int prv = nxt;
    for(j = 0; cur[j] != nxt; ++j) {
      sum += W[cur[j]];
      swap(prv, cur[j]);
    }
    swap(prv, cur[j]);
  }

  printf("%d\n", sum);
  return 0;
}