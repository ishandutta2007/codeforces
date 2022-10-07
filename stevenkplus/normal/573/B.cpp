#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100100;
int ar[MAXN];

int N;
int main() {
  scanf("%d", &N);
  for(int i = 1; i <= N; ++i) {
    scanf("%d", ar + i);
  }

  for(int i = 1; i <= N; ++i) {
    ar[i] = min(ar[i], ar[i - 1] + 1);
  }

  for(int i = N; i >= 1; --i) {
    ar[i] = min(ar[i], ar[i + 1] + 1);
  }

  int ans = 0;
  for(int i = 1; i <= N; ++i) {
    ans = max(ans, ar[i]);
  }

  printf("%d\n", ans);
  return 0;
}