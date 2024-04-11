#include<bits/stdc++.h>
using namespace std;
int main(){
   int n,k,pos,val,pos1,val1,cnt=0;
   scanf("%d%d",&n,&k);
   printf("?"); for (int i=1; i<=k; i++) printf(" %d",i); puts("");
   fflush(stdout);
   scanf("%d%d",&pos,&val);
   for (int i=1; i<=k; i++) if (i!=pos){
      printf("?"); for (int j=1; j<=k; j++) printf(" %d",j==i?n:j); puts("");
      fflush(stdout);
      scanf("%d%d",&pos1,&val1);
      if (val1!=val) cnt++;
   }
   printf("?"); for (int j=1; j<=k; j++) printf(" %d",j==pos?n:j); puts("");
   fflush(stdout);
   scanf("%d%d",&pos1,&val1);
   if (val1>val) {
      printf("! %d\n",cnt+1);
   }else{
      printf("! %d\n",k-cnt);
   }
   return 0;
}