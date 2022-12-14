#include <bits/stdc++.h>
using namespace std;
#define M 55
int dx[] = {0, 0, 1, 1};
int dy[] = {0, 1, 0, 1};

int a[M][M], b[M][M], n;
char s[M][M];
int out(int x, int y) {return (!x || !y || x > n || y > n);}

int main() {
  //freopen("in.txt", "r", stdin);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
    for (int j = 1; j <= n; j++) a[i][j] = s[i][j] - '0';
  }
  for (int i = 1; i <= (n + 1) / 2; i++) {
    for (int j = 1; j <= n; j++) swap(a[i][j], a[n + 1 - i][j]);
  }
  int minx = n + 1, miny = n + 1, maxx = 0, maxy = 0, cnt = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i][j]) {
        minx = min(minx, i);
        maxx = max(maxx, i);
        miny = min(miny, j);
        maxy = max(maxy, j);
        cnt++;
      }
    }
  }
  if (cnt != (maxx - minx + 1) * (maxy - miny + 1)) return puts("no"), 0;


  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      for (int xx = x + 1; xx <= n; xx++) {
        for (int yy = y + 1; yy <= n; yy++) {
          if (abs(x - minx) > 3 || abs(y - miny) > 3 || abs(xx - maxx) > 3 || abs(yy - maxy) > 3) {
            continue;
          }
          memset(b, 0, sizeof b);
          //if (x != 3 || y != 2 || xx != 4 || yy != 3) continue;
          for (int i = x; i <= xx; i++) {
            for (int j = y; j <= yy; j++) {
              for (int k = 0; k < 4; k++) {
                int ii = i + dx[k], jj = j + dy[k];
                if (!out(ii, jj)) b[ii][jj]++;
              }
            }
          }
          int bf = 0;
          for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
            if (a[i][j] != b[i][j]) {
              //printf("%d %d\n", a[i][j], b[i][j]);
              //printf("%d %d\n", i, j);
              bf = 1; goto LA;
            }
          } LA:;
          if (!bf) return puts("Yes"), 0;
        }
      }
    }
  }
  puts("No");
}