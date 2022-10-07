#include<iostream>
using namespace std;
int q,t,p,ans,n;
main()
{cin>>n>>t;
p=1;
for (int i=1; i<n; i++)
{cin>>q;
if(q>=t) p++; else{ans=max(ans,p); p=1;}
t=q;
}
cout<<max(p,ans)<<endl;
}