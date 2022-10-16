#include<bits/stdc++.h>
#define rd(x) x=read()
#define ll long long
#define ri register int
#define ull unsigned long long
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))
using namespace std;
const int mod=998244353;
const int N=2e6+5;
const int g=3;
inline int read(){int x=0,f=1;char ch=getchar();while((ch>'9' || ch<'0')){if(ch=='-') f=-1;ch=getchar();}while('0'<=ch && ch<='9') x=x*10+(ch^48),ch=getchar();return x*f;}
inline ll ksm(ll x,int y=mod-2,int z=mod){ll ret=1;while (y){if (y&1) ret=ret*x%mod;x=x*x%mod;y>>=1;}return ret;}
const int invg=ksm(g);
int invn;
int S[N<<1];
int inv[N];
int tr[N<<1],tf;
void Init(int n){inv[1]=1;for (ri i=2;i<=n;i++)inv[i]=1ll*inv[mod%i]*(mod-mod/i)%mod;}
//void print(int *f,int n){for (ri i=0;i<n;i++) printf("%lld ",f[i]);puts("");}
void XC(int *f,int *G,int n){for (ri i=0;i<n;i++) f[i]=1ll*f[i]*G[i]%mod;}
void rev(int *f,int n){for (ri i=0;i<n/2;i++) swap(f[i],f[n-i-1]);}
void QD(int *f,int m){for (ri i=1;i<m;i++)f[i-1]=1ll*f[i]*i%mod;f[m-1]=0;}
void JF(int *f,int m){for (ri i=m;i;i--)f[i]=1ll*f[i-1]*inv[i]%mod;f[0]=0;}

void init(int n)
{
    if (tf==n) return;tf=n;
    for (ri i=0;i<n;i++) tr[i]=(tr[i>>1]>>1)|((i&1)?n>>1:0);
}
void NTT(int *G,bool flag,int n)
{
    init(n);
    static ull f[N<<1],W[N<<1];
    W[0]=1;
    for (ri i=0;i<n;i++) f[i]=(((ll)mod<<5)+G[tr[i]])%mod;
    for (ri l=1;l<n;l<<=1)
    {
        int tG=ksm(flag?g:invg,(mod-1)/(l<<1));
        for (ri i=1;i<l;i++) W[i]=W[i-1]*tG%mod;
        for (ri k=0;k<n;k+=(l<<1))
        {
            for (ri p=0;p<l;p++)
            {
                int tt=W[p]*f[k|l|p]%mod;
                f[k|l|p]=f[k|p]+mod-tt;
                f[k|p]+=tt;
            }
        }
        if (l==(1<<10)) for (ri i=0;i<n;i++) f[i]%=mod;
    }
    if (flag==0) {int invn=ksm(n);for (ri i=0;i<n;i++) G[i]=f[i]%mod*invn%mod;}
    else for (ri i=0;i<n;i++) G[i]=f[i]%mod;
}
int F[3][N],G[5][N<<1];
void times2(int n)
{
    int m=1;
    while (m<=n*2) m<<=1;
    for (ri i=0;i<m;i++) G[0][i]=G[1][i]=G[2][i]=G[3][i]=G[4][i]=0;
    NTT(F[0],1,m);NTT(F[1],1,m);NTT(F[2],1,m);
    for (ri i=0;i<m;i++)
    {
        G[0][i]=(ll)F[0][i]*F[0][i]%mod;
        G[1][i]=(ll)F[0][i]*F[1][i]%mod;
        G[2][i]=(ll)F[1][i]*F[1][i]%mod;
        G[3][i]=(ll)F[1][i]*F[2][i]%mod;
        G[4][i]=(ll)F[2][i]*F[2][i]%mod;
        F[0][i]=F[1][i]=F[2][i]=0;
    }
    NTT(G[0],0,m);NTT(G[1],0,m);NTT(G[2],0,m);NTT(G[3],0,m);NTT(G[4],0,m);
    F[0][0]=G[0][0];F[1][0]=G[1][0];F[2][0]=G[2][0];
    for (ri i=1;i<m;i++)
    {
        F[0][i]=(G[0][i]+G[2][i-1])%mod;
        F[1][i]=(G[1][i]+G[3][i-1])%mod;
        F[2][i]=(G[2][i]+G[4][i-1])%mod;
    }
    for (ri i=0;i<m;i++) G[0][i]=G[1][i]=G[2][i]=G[3][i]=G[4][i]=0;
    for (ri i=n;i<m;i++) F[0][i]=F[1][i]=F[2][i]=0;
}
void plus1(int n)
{
    for (ri i=0;i<n;i++) F[2][i]=F[1][i],F[1][i]=F[0][i],F[0][i]=0;
    F[0][0]=1;
    for (ri i=1;i<n;i++) F[0][i]=((F[1][i-1]+F[2][i-1])%mod+F[1][i])%mod;
}

int n,m,k;
string K;

signed main()
{
    rd(n);rd(k);
    F[0][0]=F[1][0]=F[0][1]=1;
    m=log2(n);
    for (ri i=m-1;i>=0;i--)
    {
        times2(k+10);
        if (n>>i&1) plus1(k+10);
    }
    for (ri i=1;i<=k;i++) printf("%d ",F[0][i]);puts("");
}