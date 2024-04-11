#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN = 2010;

int N;
int ar[MAXN];

int main() {
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) {
    scanf("%d", ar + i);
  }

  int ans = 0;
  while (N) {
    int best = 0;
    for(int i = 0; i < N; ++i) {
      if (abs(ar[i]) > abs(ar[best])) best = i;
    }

    int a = 0;
    int b = 0;
    for(int i = 0; i < N; ++i) {
      if (abs(ar[i]) != abs(ar[best])) {
        if (i < best) ++a;
        else ++b;
      }
    }
    ans += min(a, b);
    for(int i = best; i + 1 < N; ++i) {
      ar[i] = ar[i + 1];
    }
    --N;
  }

  printf("%d\n", ans);
  return 0;
}