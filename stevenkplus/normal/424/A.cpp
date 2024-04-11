#include <cstdio>
#include <cstdlib>

const int MAXN = 222;

int N;
char str[MAXN];

int main() {
  scanf("%d", &N);
  scanf("%s", str);
  int cnt = 0;
  for(int i = 0; i < N; ++i) {
    if (str[i] == 'x') ++cnt;
    else --cnt;
  }
  printf("%d\n", abs(cnt) / 2);
  for(int i = 0; i < N; ++i) {
    if (cnt > 0 && str[i] == 'x') {
      cnt -= 2;
      str[i] = 'X';
    }
    if (cnt < 0 && str[i] == 'X') {
      cnt += 2;
      str[i] = 'x';
    }
  }

  printf("%s\n", str);
  return 0;
}