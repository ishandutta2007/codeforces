#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 500005;
char s[N];
int _c[N * 2][2];
auto c = _c + N;

int main() {
  int T;
  for (scanf("%d", &T); T; --T) {
    scanf("%s", s);
    int n = strlen(s);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      int ns = sum + (s[i] == '0' ? 1 : -1);
      ++c[sum][s[i] - '0']; ++c[ns]['1' - s[i]];
      sum = ns;
    }
    int x = 0;
    for (int i = 0; i < n; ++i) {
      if (c[x][0] > 0) {
        if (c[x][0] == 1 && c[x][1] > 0)
          --c[x][1], --c[x - 1][0], --x, putchar('1');
        else
          --c[x][0], --c[x + 1][1], ++x, putchar('0');
      }
      else
        --c[x][1], --c[x - 1][0], --x, putchar('1');
    }
    putchar('\n');
  }
  return 0;
}