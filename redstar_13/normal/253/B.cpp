#include<bits/stdc++.h>
using namespace std;
int c[110000],n;
int f(int x){
   int st=0,ed=n;
   while(st<ed){
      int m=(st+ed)/2;
      if(c[m]>x) ed=m; 
      else st=m+1;
   }
   return st;
}

main(){
   freopen("input.txt","r",stdin); 
   freopen("output.txt","w",stdout); 
   scanf("%d",&n);
   for(int i=0;i<n;i++) scanf("%d",&c[i]); 
   c[n]=1e6;
   sort(c,c+n);
   int m=n;
   for(int i=0;i<n;i++) {
      //int p=upper_bound(c,c+n,c[i]*2)-c;
      int p=f(c[i]*2);
      m=min(m,i+n-p);
   }
   cout<<m<<endl;
}