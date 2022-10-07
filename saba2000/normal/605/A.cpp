#include<iostream>
using namespace std;
int n,p=0,q,a[123456],b[123456],t,ans;
main()
{cin>>n;
for (int i=0; i<n; i++)
{cin>>p; b[p]=i;}
t=b[1];
p=1;
for (int i=2; i<=n; i++)
{q=b[i];
if(q>=t) p++; else{ans=max(ans,p); p=1;}
t=q;
}
cout<<n-max(p,ans)<<endl;
}