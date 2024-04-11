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
const int N=4e6+5;
const int M=6e5+5;
const int SZ=550;
const double eps=1e-9;
const int mod=1e9+7;
const int inf=0x3f3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
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
int n,m;
int l[N],r[N],h[N];
pair<double,int> p[N];
double x[N],y[N],ans=1e20;
double solve(double t){double L=1e20,R=-1e20;for (int i=1;i<=n;i++) R=max(R,r[i]-h[i]*t),L=min(L,l[i]-h[i]*t);return R-L;}
signed main()
{
    rd(n);for (int i=1;i<=n;i++) rd(l[i]),rd(r[i]),rd(h[i]);
    for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) if (h[i]>h[j]) p[++m]=mp((l[i]-r[j])*1.0/(h[i]-h[j]),1),p[++m]=mp((r[i]-l[j])*1.0/(h[i]-h[j]),-1);
    if (m==0) {printf("%.8lf\n",solve(0));return 0;}
    sort(p+1,p+m+1);int L=1,R=0,s=0;
    for (int i=1;i<=m;i++){if (!s) x[++R]=p[i].fi;if (s==1 && p[i].se==-1) x[++R]=p[i].fi;s+=p[i].se;}
    while (L+2<R){int mid1=(L*2+R)/3,mid2=(L+R*2)/3;if (solve(x[mid1])<solve(x[mid2])) R=mid2;else L=mid1;}
    for (int i=L;i<=R;i++) ans=min(ans,solve(x[i]));printf("%.8lf\n",ans);

}
/*
*/