# include <iostream>
# include <algorithm>
# include <vector>
using namespace std;
int euler[1000000];
int level[1000000];
int h[1000000];
bool vis[1000000];
int tot=0;
int has[1000000];
vector<int> adj[1000000];
vector<int> num[1000000];
int get_euler(int v,int lev)
{
    euler[tot]=v;
    level[tot]=lev;
    h[v]=tot;
    vis[v]=1;
    tot++;
    int n=adj[v].size();
    for (int i=0;i<n;i++)
    {
        int u=adj[v][i];
        if (vis[u])
            continue;
        get_euler(u,lev+1);
        euler[tot]=v;
        level[tot]=lev;
        tot++;
    }
}
int tree[4000000];
void build(int x,int l,int r)
{
    if (l==r)
        tree[x]=l;
    else
    {
        build(2*x,l,(l+r)/2);
        build(2*x+1,(l+r)/2+1,r);
        if (level[tree[x*2]]<level[tree[x*2+1]])
            tree[x]=tree[x*2];
        else
            tree[x]=tree[x*2+1];
    }
}
int query(int x,int l,int r,int s,int e)
{
    if (s>r || e<l)
        return -1;
    if (l>=s && r<=e)
        return tree[x];
    int p1=query(x*2,l,(l+r)/2,s,e);
    int p2=query(x*2+1,(l+r)/2+1,r,s,e);
    if (p1==-1)
        return p2;
    if (p2==-1)
        return p1;
    if (level[p1]<level[p2])
        return p1;
    return p2;
}
bool vi[1000000];
int ret[1000000];
void dfs(int v)
{
    vi[v]=1;
    int n=adj[v].size();
    for (int i=0;i<n;i++)
    {
        int u=adj[v][i];
        int k=num[v][i];
        if (vi[u])
            continue;
        dfs(u);
        ret[k]+=has[u];
        has[v]+=has[u];
    }
}
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        num[a].push_back(i);
        num[b].push_back(i);
    }
    get_euler(0,0);
    build(1,0,2*n);
    int k;
    cin>>k;
    for (int i=0;i<k;i++)
    {
        int a,b;
        cin>>a>>b;
        int f=euler[query(1,0,2*n,min(h[a-1],h[b-1]),max(h[b-1],h[a-1]))];
        a--;b--;
        has[f]-=2;
        has[b]++;
        has[a]++;
    }
    dfs(0);
    for (int i=0;i<n-1;i++)
    {
        cout<<ret[i]<<" ";
    }
    cout<<endl;
}