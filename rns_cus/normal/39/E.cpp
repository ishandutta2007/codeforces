#include<stdio.h>

int n, a, b;

bool POW(int a, int b){
   long long res = 1, tp = a;
   while(b){ if(b%2){ res = res * tp; if(res >= 1ll * n) return 0; } tp *= tp; b /= 2; }
   return 1;
}

int dfs(int a, int b){
   if(a == 1){
      if(!POW(2, b)) return -1;
      if(!dfs(2, b)) return 1;
      return 1 - dfs(a, b + 1);
   }
   if(POW(a, b + 1) and !dfs(a, b + 1)) return 1;
   if(POW(a + 1, b) and !dfs(a + 1, b)) return 1;
   return 0;
}

int main(){
   scanf("%d %d %d", &a, &b, &n);
   int ans = dfs(a, b);
   if(ans > 0) puts("Masha");
   else if(!ans) puts("Stas");
   else puts("Missing");
}