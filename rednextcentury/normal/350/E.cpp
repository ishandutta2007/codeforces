#include <bits/stdc++.h>
bool is[1000000];
int edges[1000000][2];
using namespace std;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=0;i<k;i++)
    {
        int x;
        cin>>x;
        is[x]=1;
    }
    int u,v;
    if (n==k){
        cout<<-1<<endl;
        return 0;
    }
    else if (k==1)
    {
        u=1,v=n;
        for (int i=2;i<=n;i++)
            if(is[i]==1)v=i;
    }
    else
    {
        u=n+1,v=0;
        for (int i=1;i<=n;i++)
        {
            if (is[i]==1)
                u=min(u,i),v=max(v,i);
        }
    }
    int t=0;
    for (int i=1;i<=n;i++)
    {
        if (i==v || i==u)continue;
        edges[t][0]=v;
        edges[t++][1]=i;
    }
    for (int i=1;i<=n;i++)
    {
        if (i==v || i==u)continue;
        if (is[i]==1)continue;

        edges[t][0]=u;
        edges[t++][1]=i;
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=i+1;j<=n;j++)
        {
            if (i==u || j==u || i==v || j==v)continue;
            edges[t][0]=i,edges[t++][1]=j;
        }
    }
    if (t<m)cout<<-1<<endl;
    else
    {
        for (int i=0;i<m;i++)
            cout<<edges[i][0]<<' '<<edges[i][1]<<endl;
    }
    return 0;
}