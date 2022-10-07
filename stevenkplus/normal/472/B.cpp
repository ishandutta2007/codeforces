#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 2010;

int N, K;

int ar[MAXN];

int main() {
  scanf("%d %d", &N, &K);
  for(int i = 0; i < N; ++i) {
    scanf("%d", ar + i);
  }
  sort(ar, ar + N);

  int sum = 0;
  for(int i = N - 1; i >= 0; i -= K) {
    sum += ar[i] - 1;
  }

  printf("%d\n", sum * 2);
}