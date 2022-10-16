
#include<bits/stdc++.h>
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
const int N=2e5+5;
const int M=70;
const int SZ=450;
const int mod=1e9+7;
const int inf=0x3f3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int n,m;
int dis[N],ans[N],mx[N];
vector<int> T[N],g[N];
int Q[N],l,r;
inline void dfs(int u,int d1,int d2){if (mx[u]>=d2) return;mx[u]=d2;ans[u]=max(d1,ans[u]);for (int v:T[u]) dfs(v,d1,d2-1);}
signed main()
{
    memset(dis,-1,sizeof(dis));
    rd(n);for (int i=1,x,y;i<n;i++) rd(x),rd(y),T[x].emplace_back(y),T[y].emplace_back(x);
    rd(m);for (int i=1,x;i<=m;i++) rd(x),dis[x]=0,Q[++r]=x;
    while (l<r){l++;int u=Q[l];for (int v:T[u]) if (dis[v]==-1) Q[++r]=v,dis[v]=dis[u]+1;}
    for (int i=1;i<=n;i++) g[dis[i]].emplace_back(i);
    for (int i=n;i>=0;i--) for (int j:g[i]) dfs(j,dis[j],dis[j]);
    for (int i=1;i<=n;i++) cout<<ans[i]<<" ";cout<<endl;
}
/*

*/