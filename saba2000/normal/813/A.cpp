#include<bits/stdc++.h>
using namespace std;
int main()
{int n;
int t=0;
cin>>n;
for (int i=0; i<n; i++)
{int a;cin>>a;
t+=a;}
int m;cin>>m;
int ans=100000000;
for (int i=0; i<m; i++)
{int l,r;
cin>>l>>r;
if(t<=l)ans=min(ans,l);
else if(t<=r) ans=min(ans,t);}
if(ans==100000000) cout<<-1<<endl;
else cout<<ans<<endl;
}