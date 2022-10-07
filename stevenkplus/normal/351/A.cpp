#include <cstdio>

const int MAXN = 4010;
int N;

int ar[MAXN];
char buf[111];

int main() {
  scanf("%d", &N);
  int sum = 0;
  int z = 0;
  for(int i = 0; i < 2 * N; ++i) {
    scanf("%s", buf);
    char *b = buf;
    while (*b != '.') ++b;
    ++b;
    sscanf(b, "%d", ar + i);
    sum += ar[i];
    if (ar[i] == 0) ++z;
  }

  int ans = -1;
  for(int i = N; i >= N - z; --i) {
    int diff = 1000 * i - sum;
    if (diff < 0) diff = -diff;
    if (diff < ans || ans == -1) ans = diff;
  }

  printf("%d.%03d\n", ans / 1000, ans % 1000);
  return 0;
}