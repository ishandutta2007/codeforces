#include<bits/stdc++.h>
using namespace std;
long long ans[5];
int main(){
   int T;
   scanf("%d",&T);
   while (T--){
      int n;
      long long x;
      scanf("%d",&n);
      long long s1=0,s2=0;
      for (int i=1; i<=n; i++){
         scanf("%lld",&x);
         s1+=x;
         s2^=x;
      }
      int t=0;
      if (s1&1){
         ans[++t]=1e16;
         ans[1]++;
         //puts("11");
          //printf("%lld %lld\n",s1,ans[1]);
         s1+=ans[1];
         s2^=ans[1];
      }else{
         ans[++t]=1e16;
         s1+=ans[1];
         s2^=ans[1];
      }
   //  printf("%lld %lld\n",s1,s2);
      long long delta=s2-s1/2;
      ans[++t]=delta;
      ans[++t]=delta;
      printf("%d\n",3);
      for (int i=1; i<=3; i++) printf("%lld ",ans[i]);
      puts("");
   }
}