#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 250005
#define MAXM 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k,dep[MAXN],fa[MAXN],color[MAXN];
vector<int> G[MAXN];
vector<int> ancestors[MAXN];
int leaf=0;
vector<int> leaves;
void dfs(int v,int p,int d)
{
    int cnt=0;
    dep[v]=d;fa[v]=p;color[v]=1;
    for(auto to:G[v])
    {
        if(to==p) continue;
        if(color[to]==0)
        {
            dfs(to,v,d+1); 
            cnt++;
        }
        else if(color[to]==1)
        {
            ancestors[v].push_back(to);
        }
    }
    color[v]=2;
    if(cnt==0) {leaf++; leaves.push_back(v);}
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    memset(color,0,sizeof(color));
    dfs(1,0,0);
    for(int i=1;i<=n;i++)
    {
        if(1LL*(dep[i]+1)*k>n)
        {
            puts("PATH");
            printf("%d\n",dep[i]+1);
            int v=i;
            while(v!=0)
            {
                printf("%d ",v);
                v=fa[v];
            }
            puts("");
            return 0;
        }
    }
    assert(leaf>=k);
    puts("CYCLES");
    int cnt=0;
    for(auto v:leaves)
    {
        cnt++; if(cnt>k) break;
        assert(ancestors[v].size()>=2);
        int u=ancestors[v][0],w=ancestors[v][1];
        int len1=(dep[v]-dep[u]+1),len2=(dep[v]-dep[w]+1);
        assert(len1!=len2);
        if(len1>len2) {swap(u,w); swap(len1,len2);}
        if(len1%3!=0)
        {
            printf("%d\n",len1);
            int now=v;
            while(now!=u)
            {
                printf("%d ",now);
                now=fa[now];
            }
            printf("%d\n",u);
        }
        else if (len2%3!=0)
        {
            printf("%d\n",len2);
            int now=v;
            while(now!=w)
            {
                printf("%d ",now);
                now=fa[now];
            }
            printf("%d\n",w);
        }
        else
        {
            printf("%d\n",len2-len1+2);
            printf("%d ",v);
            int now=u;
            while(now!=w)
            {
                printf("%d ",now);
                now=fa[now];
            }
            printf("%d\n",w);
        }
    }
    return 0;
}