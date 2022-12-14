#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;
int a[2000000];
int c[1000000];
int vis[1000000];
bool is[1000000];
int main ()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>c[i];
    for (int i=1;i<=n;i++)
        cin>>a[i];
    long long ret=0;
    for (int i=1;i<=n;i++)
    {
        if (vis[i])continue;
        int mn=1e9;
        int v=i;
        while(!vis[v])
        {
            vis[v]=i;
            v=a[v];
        }
        if (vis[v]==i)
            is[v]=1;
    }
    memset(vis,0,sizeof(vis));
    for (int i=1;i<=n;i++)
    {
        if (is[i])
        {
            int v=i;
            int mn=c[v];
            v=a[v];
            while(v!=i)
            {
                mn=min(mn,c[v]);
                v=a[v];
            }
            ret+=mn;
        }
    }
    cout<<ret<<endl;
}