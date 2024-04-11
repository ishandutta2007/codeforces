#include<bits/stdc++.h>
using namespace std;
int main(){
   int T;
   scanf("%d",&T);
   while (T--){
      int mx1=0,mx2=0,n,k1,k2,x;
      scanf("%d%d%d",&n,&k1,&k2);
      for (int i=1; i<=k1; i++) {
         scanf("%d",&x);
         if (x>mx1) mx1=x;
      }
      for (int i=1; i<=k2; i++){
         scanf("%d",&x);
         if (x>mx2) mx2=x;
      }
      puts(mx1>mx2?"YES":"NO");
   }
   return 0;
}