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
const int N=2e5+5;
const int M=6e5+5;
const int SZ=550;
const double eps=1e-9;
const int mod=1e9+7;
const int inf=0x3f3f3f3f3f3f3f3f;
int read(){int x=0,pre=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')pre=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*pre;}
void wt(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int inv[N],fac[N],ifc[N]; 
void Init(int n)
{
    inv[1]=1;for (int i=2;i<=n;i++)inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    fac[0]=1;for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
    ifc[0]=1;for (int i=1;i<=n;i++) ifc[i]=ifc[i-1]*inv[i]%mod;
}
int C(int n,int m){if (m<0 || m>n) return 0;return fac[n]*ifc[m]%mod*ifc[n-m]%mod;}
void add(int &x,int y) {x+=y;if (x>=mod) x-=mod;}
void gmax(int &x,int y) {x=max(x,y);}
int n;
int a[N],fa[N][20],w[N][20],f[N];
vector<int> T[N];
void dfs(int u,int Fa){for (int v:T[u]) if (v!=Fa) dfs(v,u),f[u]+=f[v];}
signed main()
{
    rd(n);for (int i=1;i<=n;i++) rd(a[i]);for (int i=2;i<=n;i++) rd(fa[i][0]),rd(w[i][0]),T[fa[i][0]].push_back(i);
    for (int k=1;k<=19;k++) for (int i=1;i<=n;i++) fa[i][k]=fa[fa[i][k-1]][k-1],w[i][k]=w[i][k-1]+w[fa[i][k-1]][k-1];
    for (int i=1;i<=n;i++)
    {
        int u=i,x=0;
        for (int k=19;k>=0;k--) if (x+w[u][k]<=a[i]) x+=w[u][k],u=fa[u][k];
        u=fa[u][0];f[fa[i][0]]++;f[u]--;
    }
    dfs(1,0);
    for (int i=1;i<=n;i++) cout<<f[i]<<" ";

}
/*
*/