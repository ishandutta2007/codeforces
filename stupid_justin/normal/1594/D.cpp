
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
const int inf=1e18;
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
int n,m,k,ans,cnt;
int fa[N];
int a[N][2];
char s[N];
bool flag=0;
void getfa(int X){if (X*2==fa[X]) return;getfa(fa[X]/2);int u=fa[fa[X]/2],v=fa[X]&1;fa[X]=u^v;return;}
bool merge(int X,int Y,int t)
{
    if (X==Y) return !t;
    getfa(X);getfa(Y);
    if (fa[X]/2!=fa[Y]/2) {fa[fa[X]/2]=fa[Y]^t^(fa[X]&1);return 1;}
    return ((fa[X]&1)^(fa[Y]&1))==t;
}
void DOIT()
{
	rd(n);rd(m);flag=1;
	for (int i=1;i<=n;i++) fa[i]=i*2;
	while (m--)
	{
		int x,y,z,u,v;rd(x);rd(y);scanf("%s",s);
		if (s[0]=='i') z=1;else z=0;
		flag&=merge(x,y,z);
	}
	if (!flag) {puts("-1");return;}
	for (int i=1;i<=n;i++) getfa(i);
	for (int i=1;i<=n;i++) a[i][1]=a[i][0]=0;
	for (int i=1;i<=n;i++) a[fa[i]/2][fa[i]%2]++;
	ans=0;for (int i=1;i<=n;i++) ans+=max(a[i][0],a[i][1]);
	cout<<ans<<endl;
}
signed main()
{
    int JYZ;rd(JYZ);while (JYZ--) DOIT();
}