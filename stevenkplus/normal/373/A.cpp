#include <cstdio>

int cnt[100];

char str[100];
int K;

int main() {
  scanf("%d", &K);
  for(int i = 0; i < 4; ++i) {
    scanf("%s", str);
    for(int j = 0; j < 4; ++j) {
      if (str[j] != '.') {
        int k = str[j] - '0';
        ++cnt[k];
      }
    }
  }

  bool good = true;
  for(int i = 0; i < 10; ++i) {
    if (cnt[i] > 2 * K) good = false;

  }
  if (good) printf("YES\n");
  else printf("NO\n");
}