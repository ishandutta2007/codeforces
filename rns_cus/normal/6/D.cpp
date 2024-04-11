#include<cstdio>
#include<algorithm>
using namespace std;

int n, a, b, h[25], f[200];

bool dfs(int d, int x, int l){
   if( d == 0 ){
      for(int i = 1; i <= n; i ++) if(h[i] >= 0) return 0;
      return 1;
   }
   if(h[x] < 0) return dfs( d, x + 1, l);
   if( x == n ){
      h[x] -= b; f[d] = x - 1;
      if (dfs(d-1, x, l)) return 1;
      h[x] += b; return 0;
   }
   for(int i = max(i, l); i <= x + 1; i ++){
      if(i <= 1 or i >= n) continue;
      f[d] = i;
      h[i] -= a; h[i-1] -= b; h[i+1] -= b;
      if(dfs(d - 1, x, i)) return 1;
      h[i] += a; h[i-1] += b; h[i+1] += b;
   }
   return 0;
}

int main(){
   scanf("%d %d %d", &n, &a, &b);
   for(int i = 1; i <= n; i ++) scanf("%d", h + i);
   for(int ans = 0; ;ans ++){
      if(dfs(ans, 1, 2)){
         printf("%d\n", ans);
         for(int i = ans; i > 0; i --) printf("%d ", f[i]);
         return 0;
      }
   }
}