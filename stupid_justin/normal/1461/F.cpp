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
int n,m,k,ans;
int a[N],b[N];
int f[25][25],g[25];
int T[25][25];
int p[N],q[N],cnt;
void solve(int l,int r)
{
    if (r<l) return;
    bool flag=0;
    for (int i=l;i<=r;i++) if (a[i]>1) flag=1;
    if (!flag) {for (int i=l;i<r;i++) b[i]=0;return;}
    while (a[l]==1) b[l]=0,l++;while (a[r]==1) r--,b[r]=0;
    flag=0;int t=1;
    for (int i=l;i<=r;i++) {t=t*a[i];if (t>1000000) {flag=1;break;}}
    if (flag==1) {for (int i=l;i<r;i++) b[i]=1;return;}
    m=0;for (int i=l;i<=r;i++) if (a[i]>1) p[++m]=i,q[m]=a[i];
    for (int i=1;i<=m;i++){int t=1;for (int j=i;j<=m;j++) t=t*q[j],T[i][j]=t;}
    memset(f,0,sizeof(f));
    f[1][1]=f[1][0]=q[1];p[0]=p[1]-1;
    for (int i=2;i<=m;i++) for (int j=1;j<=i;j++)
    {
        f[i][j]=T[i-j+1][i]+f[i-j][0]+(p[i-j+1]-p[i-j]-1);
        if (f[i][j]>f[i][0]) f[i][0]=f[i][j],g[i]=j-1;
    }
    int x=m;
    while (x)
    {
        for (int i=p[x-g[x]];i<p[x];i++) b[i]=1;
        x=x-g[x]-1;
    }
}
string s;
signed main()
{
    rd(n);for (int i=1;i<=n;i++) cin>>a[i];cin>>s;
    if (s.size()==1) {for (int i=1;i<n;i++) cout<<a[i]<<s;cout<<a[n]<<endl;return 0;}
    if (s=="-+" || s=="+-") {for (int i=1;i<n;i++) cout<<a[i]<<"+";cout<<a[n]<<endl;return 0;}
    if (s=="-*" || s=="*-") {cout<<a[1];for (int i=2;i<=n;i++) if (a[i]==0) cout<<'-'<<a[i];else cout<<"*"<<a[i];cout<<endl;return 0;}
    int la=1;
    for (int i=1;i<=n+1;i++) if (a[i]==0) solve(la,i-1),la=i+1;
    
    for (int i=1;i<n;i++) cout<<a[i]<<"+*"[b[i]];cout<<a[n]<<endl;

}
/*

*/