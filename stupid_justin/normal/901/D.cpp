#include<bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
const int N=2e5+5;
const int M=70;
const int SZ=450;
const int mod=1e9+7;
const int inf=0x3f3f3f3f3f3f3f3f;
const double k=0.5;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int n,m;
int a[N],b[N],c[N],w[N];
vector<int> G[N],T[N];
map<int,int> Map[N];
int vis[N],fa[N],dep[N];
void dfs(int u,int Fa)
{
    fa[u]=Fa;T[Fa].push_back(u);vis[u]=1;dep[u]=dep[Fa]+1;
    for (int v:G[u]) if (!vis[v]) dfs(v,u);
}
void solve(int u)
{
    for (int v:T[u]) solve(v);
    if (u!=1) w[Map[u][fa[u]]]=-c[u],c[fa[u]]+=-c[u],c[u]=0;
}
void fix(int a,int b)
{
    w[Map[a][b]]+=(dep[a]%2)?-c[1]/2:c[1]/2;
    while (a!=1) w[Map[a][fa[a]]]+=(dep[a]%2)?c[1]/2:-c[1]/2,a=fa[a];
    while (b!=1) w[Map[b][fa[b]]]+=(dep[b]%2)?c[1]/2:-c[1]/2,b=fa[b];
    c[1]=0;
}
signed main()
{
    rd(n);rd(m);for (int i=1;i<=n;i++) rd(c[i]),c[i]*=-1;
    for (int i=1,x,y;i<=m;i++) rd(x),rd(y),a[i]=x,b[i]=y,Map[x][y]=Map[y][x]=i,G[x].push_back(y),G[y].push_back(x);
    dfs(1,0);solve(1);
    if (c[1]!=0) for (int i=1;i<=m;i++) if (dep[a[i]]%2==dep[b[i]]%2){fix(a[i],b[i]);break;}
    if (c[1]!=0) {puts("NO");return 0;}
    puts("YES");for (int i=1;i<=m;i++) cout<<w[i]<<"\n";
}
/*

*/