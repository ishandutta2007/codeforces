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
const int M=5e5+5;
const int g=3;
inline int read(){int x=0,f=1;char ch=getchar();while((ch>'9' || ch<'0')){if(ch=='-') f=-1;ch=getchar();}while('0'<=ch && ch<='9') x=x*10+(ch^48),ch=getchar();return x*f;}
inline ll ksm(ll x,int y=mod-2,int z=mod){ll ret=1;while (y){if (y&1) ret=ret*x%mod;x=x*x%mod;y>>=1;}return ret;}
const int invg=ksm(g);
int invn;
int S[N];
int inv[N];
int tr[N],tf;
void Init(int n){inv[1]=1;for (int i=2;i<=n;i++)inv[i]=1ll*inv[mod%i]*(mod-mod/i)%mod;}
void print(int *f,int n){for (ri i=0;i<n;i++) printf("%d ",f[i]);puts("");}
void XC(int *f,int *G,int n){for (ri i=0;i<n;i++) f[i]=1ll*f[i]*G[i]%mod;}
void rev(int *f,int n){for (ri i=0;i<n/2;i++) swap(f[i],f[n-i-1]);}
void QD(int *f,int m){for (int i=1;i<m;i++)f[i-1]=1ll*f[i]*i%mod;f[m-1]=0;}
void JF(int *f,int m){for (int i=m;i;i--)f[i]=1ll*f[i-1]*inv[i]%mod;f[0]=0;}

void init(int n)
{
    if (tf==n) return;tf=n;
    for (ri i=0;i<n;i++) tr[i]=(tr[i>>1]>>1)|((i&1)?n>>1:0);
}
void NTT(int *G,bool flag,int n)
{
    init(n);
    static ull f[N],W[N];
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
int F[N],G[N],k[N];
int n,x,y,t,q;
vector<int> P[N];
signed main()
{
    rd(n);rd(x);rd(y);Init(n);
    for (int i=1;i<=5e5;i++) for (int j=i;j<=5e5;j+=i) P[j].push_back(i);
    for (int i=0;i<=n;i++) rd(t),F[t]=1;
    for (int i=M;i>=0;i--) G[i]=F[M-i];
    times(F,G,M+1,2*M);
    for (int i=M;i<2*M;i++) if (F[i]) k[i-M]=1;
    rd(q);
    while (q--)
    {
        int l,ans=-1;rd(l);l/=2;
        for (int u:P[l])
        {
            if (u<=y) continue;
            if (k[u-y]) ans=max(ans,u*2);
        }
        cout<<ans<<" ";
    }
}
/*

 l_i<-l_i/2
 a_i-a_j+y | l_i

 $\sum \le 5e5$   

~~ bitset  $O(nl/w)$ ~~  

 $f_n = \sum_{i-j=n} g_i*g_j$ $g_i=0/1$  $a_k=i$  
  

*/