#include <cstdio>
const int MAXN = 100100;
const int INF = 1 << 30;

int N, L, R, QL, QR;

int A[MAXN];

int main() {
  scanf("%d %d %d %d %d", &N, &L, &R, &QL, &QR);
  for(int i = 0; i < N; ++i) {
    scanf("%d", A + i);
  }

  int l = 0;
  int best = INF;
  for(int i = 0; i < N; ++i) l += A[i];
  int r = 0;
  for(int i = N; i >= 0; --i) {
    if (i < N) {
      l -= A[i];
      r += A[i];
    }
    int cost = L * l + R * r;
    int lft = i;
    int rgt = N - lft;
    if (lft > rgt + 1) {
      cost += QL * (lft - rgt - 1);
    }
    if (rgt > lft + 1) {
      cost += QR * (rgt - lft - 1);
    }
    if (cost < best) best = cost;
  }
  
  printf("%d\n", best);
  return 0;
}