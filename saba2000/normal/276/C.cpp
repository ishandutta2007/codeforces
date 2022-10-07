#include<bits/stdc++.h>
using namespace std;
long long n,q,a[200009],b[200009],c[200009],ans,p,t;
long long  k[200009];
 main()
{
cin>>n>>q;
for (long long i=1; i<=n; i++)
cin>>a[i];
for (long long i=0; i<q; i++)
{cin>>p>>t;
b[p]++; c[t]++;}
for (long long i=1; i<=n; i++)
{k[i]=k[i-1]-c[i-1]+b[i];}
sort(a+1,a+n+1); sort(k+1,k+n+1);
for (long long i=1; i<=n; i++){
ans+=a[i]*k[i];
}
cout<<ans<<endl;
}