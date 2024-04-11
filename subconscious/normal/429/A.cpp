#include<bits/stdc++.h>
using namespace std;
vector<int>g[100020],v;
int f[100020];
void dfs(int a,int p,int q,int b)
{
    if(p^f[a])
    {
        v.push_back(a);
        p^=1;
    }
    for(int i=0;i<g[a].size();i++)
    {
        if(g[a][i]!=b)
            dfs(g[a][i],q,p,a);
    }
}
int main()
{
    int n,a,b,x;
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
        scanf("%d",&f[i]);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        f[i]^=x;
    }
    dfs(1,0,0,0);
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++)
        printf("%d\n",v[i]);
    return 0;
}