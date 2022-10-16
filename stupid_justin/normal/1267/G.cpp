#include<bits/stdc++.h>
#define int long long 
#define rd(x) x=read()
#define ri register signed
using namespace std;
const int mod=998244353;
const int MOD=mod-1;
const int N=1e4+5;
inline int read(){int x=0,f=1;char ch=getchar();while((ch>'9' || ch<'0')){if(ch=='-') f=-1;ch=getchar();}while('0'<=ch && ch<='9') x=x*10+(ch^48),ch=getchar();return x*f;}
inline int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1LL) ret=ret*x%mod;x=x*x%mod;y>>=1LL;}return ret;}
int n,sum;
double x,ans;
int c[N];
double f[105][N];
signed main()
{
    rd(n);rd(x);x/=2;
    for (ri i=1;i<=n;i++) rd(c[i]);
    for (ri i=1;i<=n;i++) sum+=c[i];
    f[0][0]=1;
    for (ri i=1;i<=n;i++) for (ri k=i;k>=1;k--) for (ri j=c[i];j<=sum;j++)
    f[k][j]+=f[k-1][j-c[i]]*k/(1.0*(n-k+1));
    for (ri k=1;k<=n;k++) for (ri j=0;j<=sum;j++) ans+=f[k][j]*min((n*1.0/k+1)*x,j*1.0/k);
    printf("%.12lf\n",ans);
}