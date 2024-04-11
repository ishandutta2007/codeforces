///B
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define N 100010

char s[N], t[N], u[3], v[3], b[30][30], M[N];
int a[30][30], x, n, dis;
long long ans;

int main(){
   int INF = 100000;
   scanf("%s %s", s, t);
   int S = strlen(s), T = strlen(t);
   if(S!=T){ puts("-1"); return 0; }
   scanf("%d", &n);
   for(int i = 0; i < 30; i ++) for(int j = 0; j < 30; j ++) a[i][j] = INF;
   for(int i = 0; i < 30; i ++) a[i][i] = 0;
   for(int i = 0; i < n; i ++){
      scanf("%s %s %d", u, v, &x);
      for(int j = 0; j < 30; j ++){
         for(int t = 0; t < 30; t ++){
            a[j][t] = min(a[j][u[0]-97] + x + a[v[0]-97][t], a[j][t]);
         }
      }
   }
   for(int i = 0; i < 30; i++){
      for(int j = 0; j < 30; j ++){
         dis = INF; b[i][j] = 0;
         for(int t = 0; t < 30; t ++){
            if(a[i][t] + a[j][t] < dis){ dis = a[i][t] + a[j][t]; b[i][j] = t; }
         }
      }
   }
   for(int i = 0; i < S; i ++){
      x = b[s[i]-97][t[i]-97];
      dis = a[s[i]-97][x] + a[t[i]-97][x];
      if(dis >= INF ) { puts("-1"); return 0; }
      ans += dis; M[i] = x + 97;
   }
   printf("%I64d\n", ans);
   puts(M);
}