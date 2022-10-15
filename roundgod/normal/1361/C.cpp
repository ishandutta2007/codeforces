#include<bits/stdc++.h>
#define MAXN (1<<20)
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
int cnt[MAXN],ans[MAXN],sz[MAXN];
bool used[MAXN];
vector<P> G[MAXN];
vector<int> sg[MAXN];
vector<int> db[MAXN];
int save[MAXN];
int p[MAXN],r[MAXN],cur;
void init(int n)
{
    for(int i=0;i<n;i++)
    {
        p[i]=i;
        r[i]=0;
        sz[i]=0;
    }
}
int find(int x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void add(int x)
{
    sz[find(x)]+=2;
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) {add(x); return;}
    if(r[x]<r[y]) {p[x]=y; sz[y]+=sz[x]+2;}
    else
    {
        p[y]=x;
        sz[x]+=sz[y]+2;
        if(r[x]==r[y]) r[x]++;
    }
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
bool check(int x)
{
    memset(cnt,0,sizeof(cnt));
    init((1<<20));
    for(int i=0;i<n;i++)
    {
        int mask1=a[2*i]&((1<<x)-1),mask2=a[2*i+1]&((1<<x)-1);
        cnt[mask1]++; cnt[mask2]++;
        if(mask1!=mask2) unite(mask1,mask2);
        else add(mask1);
    }
    for(int i=0;i<(1<<20);i++)
    {
        if(!cnt[i]) continue;
        if(cnt[i]&1) return false;
        if(sz[find(i)]!=2*n) return false;
    }
    return true; 
}
void dfs(int v)
{
    for(int &i=save[v];i<(int)G[v].size();i++)
    {
        P p=G[v][i];
        if(used[p.F>>1]) continue;
        used[p.F>>1]=true;
        dfs(p.S);
        ans[cur++]=p.F;
        ans[cur++]=p.F^1;
    }
}
void construct(int x)
{
    memset(used,false,sizeof(used));
    int id=-1;
    for(int i=0;i<n;i++)
    {
        int mask1=a[2*i]&((1<<x)-1),mask2=a[2*i+1]&((1<<x)-1);
        id=mask1;
        G[mask1].push_back(P(2*i+1,mask2));
        G[mask2].push_back(P(2*i,mask1));
    }
    cur=0;
    dfs(id);
    assert(cur==2*n);
    for(int i=0;i<n-1;i++)
    {
        int mask1=a[ans[2*i+1]]&((1<<x)-1),mask2=a[ans[2*i+2]]&((1<<x)-1);
        //assert(mask1==mask2);
    }
    for(int i=0;i<2*n;i++) printf("%d ",ans[i]+1);
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<2*n;i++) scanf("%d",&a[i]);
    assert(check(0));
    for(int i=1;i<=20;i++)
    {
        if(!check(i))
        {
            printf("%d\n",i-1);
            construct(i-1);
            return 0;
        }
    }
    printf("%d\n",20);
    construct(20);
    return 0;
}