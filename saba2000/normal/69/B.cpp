#include<iostream>
using namespace std;
int k[109],p[109],l,r,t,c,n,m,ans;
main()
{cin>>n>>m;
for (int i=0; i<m; i++)
{cin>>l>>r>>t>>c;
for (int j=l; j<=r; j++)
{if(t<k[j] || k[j]==0) 
{k[j]=t;  ans-=p[j]; p[j]=c; ans+=p[j];}}
}

cout<<ans<<endl;
}