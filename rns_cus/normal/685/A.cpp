#include<bits/stdc++.h>
using namespace std;

int n, m, len1, len2, nn, mm, a[10], b[10], ans, x;

int main(){
   //freopen("a.in", "r", stdin);
   scanf("%d %d", &n, &m);
   nn = n - 1; mm = m - 1;

   while(nn){
      len1 ++;
      nn /= 7;
   } if(len1 == 0) len1 = 1;

   while(mm){
      len2 ++;
      mm /= 7;
   } if(len2 == 0) len2 = 1;

     //  printf("%d %d\n", len1, len2);

   if(len1 + len2 > 7){ puts("0"); return 0; }

   ans = 0;

   for(int i = 0; i < n; i ++){
      memset(a, 0, sizeof a);

      x = i;
      for(int k = 0; k < len1; k ++){
         if(a[x % 7]) goto END;
         a[x % 7] ++;
         x /= 7;
      }

      for(int j = 0; j < m; j ++){
         for(int i = 0; i < 7; i ++) b[i] = a[i];

         x = j;
         for(int k = 0; k < len2; k ++){
            if(b[x%7]) goto EEEN;
            b[x % 7] ++;
            x /= 7;
         }
         ans ++;
         EEEN:;
      }
      END:;
   }
   printf("%d\n", ans);
}