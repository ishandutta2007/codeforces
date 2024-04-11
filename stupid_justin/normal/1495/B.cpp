#include<bits/stdc++.h>
#define int long long 
#define ri register signed
#define rd(x) x=read()
#define endl '\n'
using namespace std;
const int N=1e6+5;
const int M=317;
const int maxn=5e6+5;
const int mod=998244353;
const int inf=0x3f3f3f3f3f3f3f3f;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
inline int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int inv[N],fac[N],ifc[N]; 
void Init(int n)
{
    inv[1]=1;for (ri i=2;i<=n;i++)inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    fac[0]=1;for (ri i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
    ifc[0]=1;for (ri i=1;i<=n;i++) ifc[i]=ifc[i-1]*inv[i]%mod;
}
int C(int n,int m){if (m<0 || m>n) return 0;return fac[n]*ifc[m]%mod*ifc[n-m]%mod;}
int n;
int p[N];
int nxt[N],pre[N];

int ans;
int a[N];
bool cmp(int x,int y){return x>y;}
signed main()
{
	rd(n);
	for (int i=1,x;i<=n;i++) {rd(p[i]);}
	for (int i=2;i<=n;i++) if (p[i-1]<p[i]) pre[i]=pre[i-1]+1;
	for (int i=n-1;i>=1;i--) if (p[i+1]<p[i]) nxt[i]=nxt[i+1]+1;
	for (int i=1;i<=n;i++) a[i]=max(pre[i],nxt[i]);
	sort(a+1,a+n+1,cmp);
	if (a[1]==a[2]) {puts("0");return 0;}
	for (int i=3;i<=n;i++) if (pre[i] && pre[i]==nxt[i] && (pre[i]%2==0) && pre[i]==a[1]) ans++;
	cout<<ans<<endl;
}