
#include<bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define endl "\n"
#define rd(x) x=read()
#define wt(x) write(x)
#define pos(x) (((x)-1)/SZ+1)
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define ls (rt<<1)
#define rs (rt<<1|1)
#define y1 _________
using namespace std;
const int N=1e6+5;
const int M=70;
const int SZ=450;
const int mod=1e9+7;
const int inf=0x3f3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int inv[N],fac[N],ifc[N]; 
void Init(int n)
{
    inv[1]=1;for (int i=2;i<=n;i++) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    fac[0]=1;for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
    ifc[0]=1;for (int i=1;i<=n;i++) ifc[i]=ifc[i-1]*inv[i]%mod;
}
int C(int n,int m){if (m<0 || m>n) return 0;return fac[n]*ifc[m]%mod*ifc[n-m]%mod;}
void add(int &x,int y) {x+=y;if (x>=mod) x-=mod;}
int n,m,q,a,b;
vector<int> G[N],T[N];
bool vis[N];
int w[N],dep[N],Fa[N];
vector<pii> ans;
void abab(int a,int b)
{
    if (dep[a]<dep[b]) swap(a,b);
    while (dep[a]>dep[b]) w[a]^=1,a=Fa[a];
    while (a!=b) w[a]^=1,a=Fa[a],w[b]^=1,b=Fa[b];
}
vector<int> tmp,tmp1,tmp2;
void out(int a,int b)
{
    tmp.clear();tmp1.clear();tmp2.clear();
    bool flag=0;
    if (dep[a]<dep[b]) swap(a,b),flag=1;
    while (dep[a]>dep[b]) tmp1.push_back(a),a=Fa[a];
    while (a!=b) tmp1.push_back(a),tmp2.push_back(b),a=Fa[a],b=Fa[b];
    for (int x:tmp1) tmp.push_back(x);tmp.push_back(a);reverse(tmp2.begin(),tmp2.end());
    for (int x:tmp2) tmp.push_back(x);
    if (flag) reverse(tmp.begin(),tmp.end());
    cout<<tmp.size()<<"\n";
    for (int x:tmp) cout<<x<<" ";cout<<"\n";
}
void dfs(int u,int fa)
{
    dep[u]=dep[fa]+1;vis[u]=1;Fa[u]=fa;
    if (fa) T[u].push_back(fa),T[fa].push_back(u);
    for (int v:G[u]) if (!vis[v]) dfs(v,u);
}
void DFS(int u,int fa)
{
    vector<int> TMP;
    for (int v:T[u]) if (v!=fa)
    {
        DFS(v,u);
        if (w[v]) TMP.push_back(w[v]);
    }

    if (TMP.size()%2==0)
    {
        for (int i=0;i+1<TMP.size();i+=2) ans.push_back({TMP[i],TMP[i+1]});
        if (w[u]==1) w[u]=u;
    } else 
    {
        for (int i=0;i+1<TMP.size();i+=2) ans.push_back({TMP[i],TMP[i+1]});
        if (w[u]==1) w[u]=TMP.back();else ans.push_back({u,TMP.back()});
    }
    if (fa==0 && w[u]) ans.push_back({w[u],u});
}
void DOIT()
{
    rd(n);rd(m);
    for (int i=1,x,y;i<=m;i++) rd(x),rd(y),G[x].push_back(y),G[y].push_back(x);
    dfs(1,0);
    rd(q);
    while (q--)
    {
        rd(a);rd(b);abab(a,b);ans.push_back({a,b});
    }
    q=ans.size();
    bool flag=1;
    for (int i=1;i<=n;i++) if (w[i]==1) flag=0;
    if (flag) puts("YES");else puts("NO");
    DFS(1,0);
    if (flag) 
    {
        for (pii x:ans) {out(x.fi,x.se);}
    } else cout<<ans.size()-q<<endl;


}
signed main()
{
    DOIT();
}
/*
*/