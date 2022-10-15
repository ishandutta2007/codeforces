#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
int n,m,k;
int a[MAXN],c[MAXN][2];
vector<int> G[MAXN];
vector<int> rG[MAXN];
vector<int> vs;
bool used[MAXN];
int cmp[MAXN],cnt[MAXN];
bool deg[MAXN];
void add_edge(int from,int to)
{
    G[from].push_back(to);
    rG[to].push_back(from);
}
void dfs(int v)
{
    used[v]=true;
    for(int i=0;i<G[v].size();i++)
        if(!used[G[v][i]]) dfs(G[v][i]);
    vs.push_back(v);
}
void rdfs(int v,int k)
{
    used[v]=true;
    cmp[v]=k;
    for(int i=0;i<rG[v].size();i++)
        if(!used[rG[v][i]]) rdfs(rG[v][i],k);
}
int scc()
{
    memset(used,0,sizeof(used));
    vs.clear();
    for(int v=0;v<n;v++)
    {
        if(!used[v]) dfs(v);
    }
    int k=0;
    memset(used,0,sizeof(used));
    for(int i=vs.size()-1;i>=0;i--)
    {
        if(!used[vs[i]]) rdfs(vs[i],k++);
    }
    return k;
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<m;i++)
        scanf("%d%d",&c[i][0],&c[i][1]);
    for(int i=0;i<m;i++)
    {
        int l=a[c[i][0]-1],r=a[c[i][1]-1];
        if((l+1)%k==r) add_edge(c[i][0]-1,c[i][1]-1);
        if((r+1)%k==l) add_edge(c[i][1]-1,c[i][0]-1); 
    }
    int p=scc();
    memset(deg,true,sizeof(deg));
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<n;i++)
        cnt[cmp[i]]++;
    int ans=n+1,res=-1;
    for(int i=0;i<n;i++)
        for(int j=0;j<G[i].size();j++)
            if(cmp[i]!=cmp[G[i][j]]) deg[cmp[i]]=false;
    for(int i=0;i<p;i++)
        if(deg[i]&&cnt[i]<ans)
        {
            ans=cnt[i];
            res=i;
        }
    printf("%d\n",ans);
    for(int i=0;i<n;i++)
        if(cmp[i]==res) printf("%d ",i+1);
    return 0;
}