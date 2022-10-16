#include<bits/stdc++.h>
#pragma comment(linker,"/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define rd(x) x=read()
#define ll long long
#define ri register int
#define ull unsigned long long
#define int long long
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))
using namespace std;
const int mod=998244353;
const int N=2e5+5;
const int g=3;
inline int read(){int x=0,f=1;char ch=getchar();while((ch>'9' || ch<'0')){if(ch=='-') f=-1;ch=getchar();}while('0'<=ch && ch<='9') x=x*10+(ch^48),ch=getchar();return x*f;}
inline ll ksm(ll x,int y=mod-2,int z=mod){ll ret=1;while (y){if (y&1) ret=ret*x%mod;x=x*x%mod;y>>=1;}return ret;}
const int invg=ksm(g);
int invn;
int TMP1[N<<1],TMP2[N<<1];
int TmP1[N<<1],TmP2[N<<1];
int S[N<<1];
int inv[N];
int tr[N<<1],tf;
void Init(int n){inv[1]=1;for (ri i=2;i<=n;i++)inv[i]=1ll*inv[mod%i]*(mod-mod/i)%mod;}
void print(int *f,int n){for (ri i=0;i<n;i++) printf("%lld ",f[i]);puts("");}
void XC(int *f,int *G,int n){for (ri i=0;i<n;i++) f[i]=1ll*f[i]*G[i]%mod;}

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
void times(int *f,int *G,int len,int lim)
{
    int n=1;for (n;n<len+len;n<<=1);
    cpy(S,G,n);
    for (ri i=len;i<n;i++) S[i]=0;
    NTT(f,1,n);NTT(S,1,n);XC(f,S,n);NTT(f,0,n);
    for (ri i=lim;i<n;i++) f[i]=0;
    clr(S,n);
}
void invp(int *f,int m)
{
    int n=1;for (;n<m;n<<=1);
    #define w TmP1
    #define r TmP2
    w[0]=ksm(f[0]);
    for (ri l=2;l<=n;l<<=1)
    {
        for (ri i=0;i<(l>>1);i++) r[i]=(w[i]<<1)%mod;
        cpy(S,f,l);
        NTT(w,1,l<<1);XC(w,w,l<<1);
        NTT(S,1,l<<1);XC(w,S,l<<1);
        NTT(w,0,l<<1);clr(w+l,l);
        for (ri i=0;i<l;i++) w[i]=(r[i]-w[i]+mod)%mod;
    }
    cpy(f,w,m);clr(S,n*2);clr(w,n*2);clr(r,n*2);
    #undef w
    #undef r
}
void sqrtp(int *f,int m)
{
    int n=1;for (;n<m;n<<=1);
    #define b1 TMP1
    #define b2 TMP2
    b1[0]=1;
    for (ri l=2;l<=n;l<<=1)
    {
        for (ri i=0;i<(l>>1);i++) b2[i]=(b1[i]<<1)%mod;
        invp(b2,l);
        NTT(b1,1,l);XC(b1,b1,l);NTT(b1,0,l);
        for (ri i=0;i<l;i++) b1[i]=(f[i]+b1[i])%mod;
        times(b1,b2,l,l);
    }
    cpy(f,b1,m);clr(b1,n*2);clr(b2,n*2);
    #undef b1
    #undef b2
}
int F[N<<1],G[N<<1];
int C[N<<1];
int n,m;
string K;

signed main()
{
    rd(n);rd(m);m++;
    for (int i=1;i<=n;i++) rd(C[i]);
    for (int i=1;i<=n;i++) F[C[i]]=4;
    for (int i=0;i<m;i++) F[i]=mod-F[i];F[0]++;F[0]%=mod;
    sqrtp(F,m);
    F[0]++;F[0]%=mod;
    invp(F,m);
    for (int i=0;i<m;i++) F[i]=F[i]*2%mod;
    for (int i=1;i<m;i++) cout<<F[i]<<"\n";
}