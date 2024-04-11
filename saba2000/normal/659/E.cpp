#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v[100009];
int f[100009];
int x,k;
void dfs(int u)
{
    x+=v[u].size();
    k++;
    f[u]=1;
    for (int i=0; i<v[u].size(); i++)
        if(f[v[u][i]]==0) dfs(v[u][i]);
}
main()
{int n,m;
cin>>n>>m;
for (int i=0; i<m; i++)
{int a,b;
cin>>a>>b;
v[a].push_back(b);
v[b].push_back(a);
}
int ans=0;
for (int i=1; i<=n; i++)
{
    x=0,k=0;
    if(f[i]==0) dfs(i);
    x/=2;
   // cout<<x<<" "<<k<<endl;
    if(x==k-1) ans++;
}
cout<<ans<<endl;
}