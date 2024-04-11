#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100100;
int A[MAXN];
int B[MAXN];
int C[MAXN];
char str[MAXN];

int N, Q;

int main() {
  scanf("%s", str);
  N = 0;
  while (str[N]) ++N;
  scanf("%d", &Q);

  for(int i = 0; i < N; ++i) {
    A[i + 1] = A[i];
    B[i + 1] = B[i];
    C[i + 1] = C[i];
    if (str[i] == 'x') 
      ++A[i + 1];
    else if (str[i] == 'y')
      ++B[i + 1];
    else
      ++C[i + 1];
  }

  for(int i = 0; i < Q; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a;

    int x = A[b] - A[a];
    int y = B[b] - B[a];
    int z = C[b] - C[a];
    int m = min(min(x,y),z);
    int M = max(max(x,y),z);

    if (b - a >= 3 && M > m + 1) {
      printf("NO\n");
    } else {
      printf("YES\n");
    }
  }
  return 0;
}