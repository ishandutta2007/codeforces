
#include<bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define wt(x) write(x)
#define pos(x) (((x)-1)/SZ+1)
#define endl "\n"
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define ls (rt<<1)
#define rs (rt<<1|1)
#define y1 _________
using namespace std;
const int N=6e5+5;
const int M=70;
const int SZ=450;
const int mod=1e9+7;
const int inf=0x3f3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}

int n,m,q,tot,ans,cnt;
vector<pii> G[N];
int fa[N];
int getfa(int x){return x==fa[x]?x:fa[x]=getfa(fa[x]);}
void merge(int u,int v){u=getfa(u);v=getfa(v);if (u!=v) fa[u]=v;}
int dfn[N],t;
int x[N],y[N];
vector<int> E[N];
int dfs(int u,int id,int fr)
{
    dfn[u]=++cnt;
    int mn=u;
    for (pii e:G[u]) if (e.first!=fr)
    {
        int x;
        if (!dfn[e.first])
        {
            x=dfs(e.first,e.second,u);
            if (dfn[x]<dfn[u]) merge(id,e.second);
            if (dfn[mn]>=dfn[x]) mn=x;
        } else
        {
            if (dfn[mn]>=dfn[e.first]) mn=e.first;
            if (dfn[e.first]<=dfn[fr]) merge(e.second,id);
        }
    }
    return mn;
}
int nxt[N];
int sum[N];
int R[N],c[N];
void get()
{
    for (int i=1;i<=m;i++)
    {
        rd(x[i]);rd(y[i]);
        G[x[i]].emplace_back(y[i],i);
        G[y[i]].emplace_back(x[i],i);
    }
    for (int i=1;i<=m;i++) fa[i]=i;
    for (int i=1;i<=n;i++) if (!dfn[i]) dfs(i,0,0);
    for (int i=1;i<=m;i++) E[getfa(i)].emplace_back(i);
    int aaa=0;
    for (int i=1;i<=m;i++) if (E[i].size()>2)
    {
        aaa++;
        for (int j:E[i]) c[x[j]]=c[y[j]]=aaa;
    }
    for (int i=1;i<=n;i++) R[c[i]]=max(R[c[i]],i);
    //for (int i=1;i<=n;i++) cout<<c[i]<<" ";cout<<"\n";

}
set<int> S;
signed main()
{
    rd(n);rd(m);get();
    for (int i=1;i<=m;i++) if (R[i]) S.insert(R[i]);
    for (int i=1;i<=n;i++)
    {
        if (S.empty()) nxt[i]=n+1;else  nxt[i]=(*S.begin());
        S.erase(R[c[i]]);
    }
    for (int i=1;i<=n;i++) sum[i]=sum[i-1]+nxt[i]-i;
    rd(q);

    while (q--)
    {
        int l,r;rd(l);rd(r);
        int p=upper_bound(nxt+l,nxt+r+1,r)-nxt-1;

        ans=sum[p]-sum[l-1];
        int t=r-p;ans+=t*(t+1)/2;
        cout<<ans<<"\n";
    }
}
/*

*/