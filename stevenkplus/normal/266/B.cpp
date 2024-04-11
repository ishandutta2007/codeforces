#include <cstdio>

const int maxn = 55;

int n, k;
char str[maxn];

int main() {
  scanf("%d %d", &n, &k);
  scanf("%s", str);

  for(int j = 0; j < k; ++j)
  for(int i = 0; i + 1 < n; ++i) {
    if (str[i] == 'B' && str[i + 1] == 'G') {
      str[i] = 'G';
      str[i + 1] = 'B';
      ++i;
     }
  }

  printf("%s\n", str);
  return 0;
}