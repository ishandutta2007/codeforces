#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
int t,n,m,deg[MAXN],a[MAXN],r[MAXN];
vector<int> G[MAXN];
vector<int> gr[MAXN];
vector<int> adj[MAXN];
bool cmp(int x,int y)
{
    return deg[x]<deg[y];
}
vector<int> s[100005];
vector<int> dis;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        dis.clear();
        for(int i=1;i<=n;i++) s[i].clear();
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            for(int j=0;j<x;j++)
            {
                int y;
                scanf("%d",&y);
                s[i].push_back(y);
                dis.push_back(y);
            }
        }
        sort(dis.begin(),dis.end());
        dis.erase(unique(dis.begin(),dis.end()),dis.end());
        int N=n+(int)dis.size();
        for(int i=1;i<=N;i++) a[i]=i,deg[i]=0,G[i].clear(),gr[i].clear();
        for(int i=1;i<=n;i++)
            for(int j=0;j<(int)s[i].size();j++)
            {
                int v=lower_bound(dis.begin(),dis.end(),s[i][j])-dis.begin()+1;
                G[i].push_back(n+v);
                G[n+v].push_back(i);
                deg[i]++; deg[n+v]++;
            }
        sort(a+1,a+N+1,cmp);
        for(int i=1;i<=N;i++) r[a[i]]=i;
        for(int i=1;i<=N;i++)
            for(auto to:G[i]) if(r[to]>r[i]) gr[i].push_back(to); 
        int ans=0,x=-1,y=-1;
        for(int i=1;i<=N;i++)
        {
            for(auto u:G[i])
            {
                for(auto to:gr[u])
                {
                    if(r[to]>r[i]) 
                    {
                        if(adj[to].size())
                        {
                            if(to<=n)
                            {
                                x=to;
                                y=i;
                            }
                            else
                            {
                                x=adj[to].back();
                                y=u;
                            }
                        }
                        adj[to].push_back(u);
                    }
                }
            }
            for(auto u:G[i])
            {
                for(auto to:gr[u])
                {
                    if(r[to]>r[i]) adj[to].pop_back();
                }
            }
        }
        if(x==-1&&y==-1) puts("-1");
        else printf("%d %d\n",x,y);
    }
    return 0;
}