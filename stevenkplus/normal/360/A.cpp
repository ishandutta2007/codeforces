#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 5010;
const int inf = 1000000000;

int N, M;
int maxval[MAXN];
int add[MAXN];
int A[MAXN],B[MAXN],C[MAXN],D[MAXN];

int main() {
  scanf("%d %d", &N, &M);
  for(int i = 0; i < M; ++i) {
    scanf("%d %d %d %d", A + i, B + i, C + i, D + i);
  }
  for(int i = 1; i <= N; ++i) {
    maxval[i] = inf;
  }

  for(int i = 0; i < M; ++i) {
    if (A[i] == 1) {
      for(int j = B[i]; j <= C[i]; ++j) {
        add[j] += D[i];
      }
    } else {
      for(int j = B[i]; j <= C[i]; ++j) {
        maxval[j] = min(maxval[j], D[i] - add[j]);
      }
    }
  }

  for(int i = 1; i <= N; ++i) {
    add[i] = 0;
  }

  bool ans = true;
  for(int i = 0; i < M; ++i) {
    if (A[i] == 1) {
      for(int j = B[i]; j <= C[i]; ++j) {
        add[j] += D[i];
      }
    } else {
      bool good = false;
      for(int j = B[i]; j <= C[i]; ++j) {
        if (add[j] + maxval[j] == D[i]) {
          good = true;
          break;
        }
      }
      if (!good) {
        ans = false;
      }
    }
  }

  if (ans) {
    printf("YES\n");
    for(int i = 1; i <= N; ++i) {
      if (i > 1) printf(" ");
      printf("%d", maxval[i]);
    }
  } else {
    printf("NO\n");
  }
  return 0;
}