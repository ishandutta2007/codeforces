#include <bits/stdc++.h>
using namespace std;

int a[31][31], b[31];

int main() {
  ///freopen("b.in", "r", stdin);
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; i ++) for(int j = 1; j <= m; j ++) scanf("%d", &a[i][j]);
  for(int i = 1; i <= m; i ++) {
    for(int j = 1; j <= m; j ++) {
      bool yes = 1;
      for(int k = 1; k <= n; k ++) {
        bool br = 0;
        for(int r = 1; r <= m; r ++) for(int l = 1; l <= m; l ++) {
          for(int x = 1; x <= m; x ++) b[x] = a[k][x];
          swap(b[r], b[l]);
          swap(b[i], b[j]);
          int y;
          for(y = 1; y <= m; y ++) if(b[y] != y) break;
          if(y == m + 1) {br = 1; break;}
          for(int x = 1; x <= m; x ++) b[x] = a[k][x];
          swap(b[i], b[j]);
          swap(b[r], b[l]);
          for(y = 1; y <= m; y ++) if(b[y] != y) break;
          if(y == m + 1) {br = 1; break;}
        }
        if(!br) yes = 0;
      }
      if(yes) return puts("YES");
    }
  }
  puts("NO");
}