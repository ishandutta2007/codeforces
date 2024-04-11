#include<bits/stdc++.h>
using namespace std;
int a[500009],m1,m2,m3;
int ans;
vector<int> v[300009];
main()
{int n,M=-1000000009;
cin>>n;
for (int i=1; i<=n; i++)
{cin>>a[i];
M=max(M,a[i]);}

for (int i=1; i<=n; i++)
{if(a[i]==M) m1++;
if(a[i]==M-1) m2++;}
ans=M+5;
for (int i=1; i<n; i++)
{int u,b;cin>>u>>b;
v[u].push_back(b);
v[b].push_back(u);}
for (int i=1; i<=n; i++)
{int k1=0,k2=0; 
for (int j=0; j<v[i].size(); j++)
{if(a[v[i][j]]==M) k1++;
if(a[v[i][j]]==M-1) k2++;}
//cout<<i<<" "<<k1<<" "<<k2<<" "<<ans<<endl;
int x=a[i];
if(k1>0) x=max(x,M+1); 
if(a[i]==M) k1++;
if(m1>k1) x=max(x,M+2);
if(a[i]==M-1) k2++;
if(m2>k2) x=max(x,M+1);
ans=min(ans,x);
}
cout<<ans<<endl;
}