#include<bits/stdc++.h>
using namespace std;
typedef long long INT;
char str[110][110];
main(){
#ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
#endif
   int n;
   scanf("%d",&n); 
   for(int i=0;i<n;i++) scanf("%s",str[i]);
    
   int ans=-1e5;
   for(int i=0;i<n;i++){
      int m=0;
      for(int j=i;j<n;j++){
         if(strcmp(str[i],str[j])==0)m++;   
      }
      ans=max(ans,m);
   }
   cout<<ans<<endl;
}