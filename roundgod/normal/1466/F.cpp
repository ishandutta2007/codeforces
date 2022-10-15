#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge{int u,v,cost;};
bool cmp(const edge &e1,const edge &e2)
{
    return e1.cost<e2.cost;
}
edge es[MAXN];
int n,m,E;
int p[MAXN],r[MAXN];
vector<int> G[MAXN];
vector<int> ans;
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
        r[i]=0;
    }
}
int find(int x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) p[x]=y;
    else
    {
        p[y]=x;
        if(r[x]==r[y]) r[x]++;
    }
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
int kruskal()
{
    sort(es,es+E,cmp);
    int res=0;
    for(int i=0;i<E;i++)
    {
        edge e=es[i];
        if(!same(e.u,e.v))
        {
            unite(e.u,e.v);
            res+=e.cost;
            ans.push_back(e.cost);
        }
    }
    return res;
}
int cur=INF;
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int main()
{
    scanf("%d%d",&m,&n);
    init(n+1);
    for(int i=1;i<=m;i++)
    {
        int k;
        scanf("%d",&k);
        if(k==2)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            es[E++]=(edge){x,y,i};
        }
        else 
        {
            int x;
            scanf("%d",&x);
            es[E++]=(edge){x,n+1,i};
        }
    }
    kruskal();
    int sz=(int)ans.size();
    printf("%d %d\n",pow_mod(2,sz),sz);
    sort(ans.begin(),ans.end());
    for(auto x:ans) printf("%d ",x);
    puts("");
    return 0;
}