#include<bits/stdc++.h>
using namespace std;
typedef long long INT;
int a[10010];
main(){
#ifndef ONLINE_JUDGE
   freopen("d.txt","r",stdin);
#endif
   int n,r,t,u,v,m;
   cin>>n;
   r=0;
   for(int i=0;i<n;i++){
      cin>>a[i];
      if(a[i])r++;
   }
   m=-1e5;
   for(int i=0;i<n;i++){
      u=0,v=0;
      for(int j=i;j<n;j++){
         if(a[j]) u++;
         else v++;
         m=max(r-u+v,m);   
      }
   }
   cout<<m<<endl;
}