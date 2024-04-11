#include<bits/stdc++.h>
using namespace std;

#define N 2000000
#define NN 1010

int a[N], down[N], next[N], b[5][NN], d[5][NN];
int n, m, q, H, M, h, w;
int p1, p2;
int aa, bb, cc, dd;

int main(){
  // .freopen("ee.in", "r", stdin);

   scanf("%d %d %d", &n, &m, &q);
   H = n + 3;
   M = m + 3;
   for(int i = 1; i <= n; i ++) for(int j = 1; j <= m; j ++) scanf("%d", &a[i * M + j]);
   for(int i = 0; i <= n; i ++){
      for(int j = 0; j <= m; j ++){
         next[i * M + j] = i * M + j + 1;
         down[i * M + j] = i * M + j + M;
      }
   }

   while(q -- ){
      scanf("%d %d %d %d %d %d", &aa, &bb, &cc, &dd, &h, &w);
      p1 = 0, p2 = 0;
      for(int i = 1; i < aa; i ++) p1 = down[p1];
      for(int i = 1; i < bb; i ++) p1 = next[p1];
      for(int i = 1; i < cc; i ++) p2 = down[p2];
      for(int i = 1; i < dd; i ++) p2 = next[p2];
      b[0][0] = p1; d[0][0] = p2;
      for(int i = 1; i <= h; i ++){
         b[0][i] = down[b[0][i-1]];
         d[0][i] = down[d[0][i-1]];
      }
      b[1][0] = b[0][h]; d[1][0] = d[0][h];
      for(int i = 1; i <= w; i ++){
         b[1][i] = next[b[1][i-1]];
         d[1][i] = next[d[1][i-1]];
      }

      b[2][0] = p1, d[2][0] = p2;
      for(int i = 1; i <= w; i ++){
         b[2][i] = next[b[2][i-1]];
         d[2][i] = next[d[2][i-1]];
      }
      b[3][0] = b[2][w]; d[3][0] = d[2][w];
      for(int i = 1; i <= h; i ++){
         b[3][i] = down[b[3][i-1]];
         d[3][i] = down[d[3][i-1]];
      }

      for(int i = 1; i <= h; i ++){
         swap(next[b[0][i]], next[d[0][i]]);
         swap(next[b[3][i]], next[d[3][i]]);
      }
      for(int i = 1; i <= w; i ++){
         swap(down[b[1][i]], down[d[1][i]]);
         swap(down[b[2][i]], down[d[2][i]]);
      }
   }
   p1 = 0;
   for(int i = 1; i <= n; i ++){
      p1 = down[p1]; p2 = p1;
      for(int j = 1; j <= m; j ++){
         p2 = next[p2];
         printf("%d%c", a[p2], j == m ? '\n' : ' ');
      }
   }
}