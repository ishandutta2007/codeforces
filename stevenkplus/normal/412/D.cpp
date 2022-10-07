#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

typedef pair<int, int> pii;

map<int, int> bad[MAXN];

int ar[MAXN];

int N, M;

void go() {
  int x = 1;
  while (x < N) {
    if (bad[ar[x]][ar[x + 1]]) {
      swap(ar[x], ar[x + 1]);
      if (x > 1) {
        --x;
        continue;
      }
    }
    ++x;
  }
}

int main() {
  scanf("%d %d", &N, &M);
  for(int i = 0; i < M; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    bad[a][b] = 1;
  }

  for(int i = 1; i <= N; ++i) {
    ar[i] = i;
  }

  go();

  for(int i = 1; i <= N; ++i) {
    printf("%d ", ar[i]);;
  }
  printf("\n");
  return 0;
}