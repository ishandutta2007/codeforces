#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 111;

int ar[MAXN];

int N, K;

int main() {
  scanf("%d %d", &N, &K);
  for(int i = 0; i < N; ++i) {
    scanf("%d", ar + i);
  }
  sort(ar, ar + N);
  printf("%d\n", ar[N - K]);
  return 0;
}