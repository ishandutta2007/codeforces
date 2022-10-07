#include<bits/stdc++.h>
using namespace std;
int f[300009],D[300009];
vector<int> v[300009];
int ans=0,k=0; 
void dfs(int m, int d)
{f[m]=1;
ans=max(ans,2*D[m]);
for (int i=0;  i<v[m].size(); i++)
if(D[v[m][i]]>d+1 && f[v[m][i]]==0) dfs(v[m][i],d+1);
}
int x;
void dfs1(int m, int d)
{f[m]=1;
D[m]=d;
for (int i=0;  i<v[m].size(); i++)
if(f[v[m][i]]==0) dfs1(v[m][i],d+1);
}
int main()
{int n;
cin>>n>>x;
for (int i=0; i<n-1; i++)
{int a,b;
cin>>a>>b;
v[a].push_back(b);
v[b].push_back(a);}
dfs1(1,0);
for(int i=0; i<=n; i++)
f[i]=0;
dfs(x,0);

cout<<ans<<endl;
}