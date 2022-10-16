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
const int N=250+5;
const int M=6e5+5;
const int SZ=550;
const double eps=1e-9;
const int mod=998244353;
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
int n,m,x,y;
int a[N][N],b[N][N];
int h[N*N],l[N*N],r[N],c[N];
queue<pii>q;
signed main()
{
    rd(n);rd(m);for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) rd(a[i][j]),r[i]=max(r[i],a[i][j]),c[j]=max(c[j],a[i][j]);
	for (int i=1;i<=n;i++) h[r[i]]=1;for (int i=1;i<=m;i++) l[c[i]]=1;
	for(int i=n*m;i>=1;i--)
	{
		if (h[i]) x++;if (l[i]) y++;
		if (h[i] || l[i]) b[x][y]=i;else {pii p=q.front();q.pop();b[p.fi][p.se]=i;}
		if (h[i]) for(int j=y-1;j>=1;j--)q.push(make_pair(x,j));
		if (l[i]) for(int j=x-1;j>=1;j--)q.push(make_pair(j,y));
	}
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) cout<<b[i][j]<<" \n"[j==m];
}