#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
vector<int> G[MAXN];
int dep[MAXN],sz[MAXN];
bool cmp(int x,int y)
{
    return dep[x]-sz[x]>dep[y]-sz[y];
}
void dfs(int v,int p,int d)
{
    sz[v]=1; dep[v]=d;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v,d+1);
        sz[v]+=sz[to];
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    dfs(1,0,0);
    vector<int> v;
    for(int i=1;i<=n;i++) v.push_back(i);
    ll ans=0;
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<k;i++) ans+=dep[v[i]]-sz[v[i]]+1;
    printf("%lld\n",ans);
    return 0;
}