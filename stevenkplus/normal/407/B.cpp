#include <cstdio>

const int MAXN = 1010;
const int MOD = 1E9 + 7;
int dist[MAXN];

int P[MAXN];

int N;
int main() {
  scanf("%d", &N);
  for(int i = 1; i <= N; ++i) {
    scanf("%d", P + i);
  }

  dist[1] = 0;
  for(int i = 1; i <= N; ++i) {
    int d = dist[i] - dist[P[i]];
    dist[i + 1] = dist[i] + 1 + d + 1;
    dist[i + 1] %= MOD;
    if (dist[i + 1] < 0) dist[i + 1] += MOD;
  }
  printf("%d\n", dist[N + 1]);
}