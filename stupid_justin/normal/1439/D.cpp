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
const int N=2e6+5;
const int M=505;
const int SZ=450;
int mod=1e9+7;
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
int n,m,k,ans;
int f[M][M],g[M][M];
bool vf[M][M],vg[M][M];
int F(int n,int m);
int G(int n,int m);
int F(int n,int m)
{
    if (vf[n][m]) return f[n][m];int ret=0;
    if (n==m) 
    {
        for (int i=1;i<=n;i++) ret+=C(n-1,i-1)*(n+1)%mod*((G(i-1,i-1)*F(n-i,n-i)+G(n-i,n-i)*F(i-1,i-1))%mod),ret%=mod;
        for (int i=1;i<=n;i++) ret+=C(n-1,i-1)*G(i-1,i-1)%mod*G(n-i,n-i)%mod*((i-1)*i/2+(n-i)*(n-i+1)/2),ret%=mod;
    } else {ret+=F(n-1,m);for (int i=1;i<=m;i++) ret+=C(m,i)*(F(n-i-1,m-i)*G(i,i)%mod+F(i,i)*G(n-i-1,m-i)%mod),ret%=mod;}
    vf[n][m]=1;return f[n][m]=ret;
}
int G(int n,int m)
{
    if (n==0 && m==0) return 1;
    if (vg[n][m]) return g[n][m];int ret=0;
    if (n==m){for (int i=1;i<=n;i++) ret+=G(i-1,i-1)*G(n-i,n-i)%mod*C(n-1,i-1),ret%=mod;ret=ret*(n+1)%mod;}
    else {ret=G(n-1,m);for (int i=1;i<=m;i++) ret+=G(n-i-1,m-i)*G(i,i)%mod*C(m,i),ret%=mod;}
    vg[n][m]=1;return g[n][m]=ret;
}
signed main()
{
    rd(n);rd(m);rd(mod);Init(N-1);
    cout<<F(n,m)<<endl;
}
/*

*/