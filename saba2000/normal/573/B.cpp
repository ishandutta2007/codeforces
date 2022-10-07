#include <iostream>
using namespace std;
int n,h[100000],t[100000],l=1,ans;
main()
{cin>>n;
for(int i=0; i<n; i++)
cin>>h[i];
for(int i=0; i<n; i++)
{t[i]=min(h[i],l); l=min(l+1,h[i]+1);}
l=1;
for(int i=n-1; i>=0; i--)
{t[i]=min(t[i],min(l,h[i])); l=min(l+1,h[i]+1);}
ans=t[0];
for(int i=0; i<n; i++)
{ans=max(ans,t[i]);}
cout<<ans<<endl;
}