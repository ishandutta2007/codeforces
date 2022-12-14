#include <bits/stdc++.h>
using namespace std;
struct LiChaoTree
{
    typedef long long ftype;
    #define MX 1e18
    #define MAX_QUERY 1e6
    #define MIN_QUERY -1e6
    struct Line
    {
        ftype m,c;
        Line(ftype M,ftype C){m=M;c=C;}
        Line(){};
    };
    ftype f(Line l,  ftype x)
    {
        return l.m*x+l.c;
    }
    struct node
    {
        Line line;
        node* L = NULL;
        node* R = NULL;
        node(){}
        node(Line l) { line = l; }
    };
    node *root = NULL;
    void init()
    {
        if (root!=NULL)
            clr(root);
        root=NULL;
    }
    void clr(node* &v)
    {
        if (v->L != NULL)clr(v->L);
        if (v->R != NULL)clr(v->R);
        delete(v);
    }
    void Insert(Line nw, node* &v, ftype l=MIN_QUERY, ftype r=MAX_QUERY)
    {
        if (v==NULL)
        {
            v = new node(nw);
            return;
        }
        ftype mid = (l + r) / 2;
        bool LEFT = f(nw, l) < f(v->line, l);
        bool MID = f(nw, mid) < f(v->line, mid);
        bool RIGHT = f(nw, r) < f(v->line, r);
        if (LEFT && RIGHT)
            v->line = nw;
        if (LEFT == RIGHT)
            return;
        if(LEFT!=MID)
        {
            if (RIGHT) swap(v->line,nw);
            Insert(nw, v->L, l, mid);
        }
        else
        {
            if (LEFT) swap(v->line,nw);
            Insert(nw, v->R, mid+1, r);
        }
    }
    ftype Get(ftype x, node *v, ftype l=MIN_QUERY, ftype r=MAX_QUERY)
    {
        if (v==NULL)
            return MX;
        ftype mid = (l + r) / 2;
        if(x <= mid)
            return min(f(v->line, x), Get(x, v->L, l, mid));
        else
            return min(f(v->line, x), Get(x, v->R, mid+1, r));
    }

    void add_line(ftype m,ftype c)
    {
        Insert(Line(m,c),root);
    }
    ftype query(ftype x)
    {
        return Get(x,root);
    }
};

long long dp[2000000];
long long a[2000000];
long long b[2000000];
long long sz[1000000];
vector<int> adj[1000000];
int mx[1000001];
void pre(int v,int pa)
{
    for (auto u:adj[v])
    {
        if (u==pa)continue;
        pre(u,v);
        sz[v]+=sz[u];
        if (mx[v]==0)
            mx[v]=u;
        else if (sz[mx[v]]<sz[u])
            mx[v]=u;
    }
    sz[v]++;
}
vector<pair<long long,long long> > vec[1000000];
LiChaoTree tree[1000000];
void dfs(int v,int pa)
{
    for (auto u:adj[v])
        if (u!=pa)
            dfs(u,v);
    if (mx[v]!=0)
        swap(vec[mx[v]],vec[v]),swap(tree[mx[v]],tree[v]);
    for (auto u:adj[v])
        if (u!=mx[v] && u!=pa)
            for (auto p:vec[u])
                vec[v].emplace_back(p),tree[v].add_line(p.first,p.second);
    if (mx[v]==0)
        dp[v]=0;
    else
        dp[v] = tree[v].query(a[v]);
    if (dp[v]==1e18)return;
    vec[v].emplace_back(b[v],dp[v]);
    tree[v].add_line(b[v],dp[v]);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
        cin>>b[i];
    for (int i=2;i<=n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    pre(1,-1);
    dfs(1,-1);
    for (int i=1;i<=n;i++)
        tree[i].init(),cout<<dp[i]<<' ';
}