#include<bits/stdc++.h>
using namespace std;
typedef long long INT;
int a[110],b[110];
main(){
#ifndef ONLINE_JUDGE
   freopen("e.txt","r",stdin);
#endif
   int n,m;
   cin>>n;
   for(int i=0;i<n;i++)cin>>a[i];
   cin>>m;
   for(int i=0;i<m;i++) cin>>b[i];
   sort(a,a+n);
   sort(b,b+m);
   int k=0;
   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
         if(b[j]>0 and (a[i]==b[j] or a[i]==b[j]-1 or a[i]==b[j]+1)){
            b[j]=-1;
            k++;  
            break;
         }
      }
   }
   cout<<k<<endl;
}