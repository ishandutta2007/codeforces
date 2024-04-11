#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
using namespace std;
const int N=5e5+5;
const int M=5005;
const int mod=1e9+7;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int S[N][3];
int d[N];
int vis[N];
int can[N];
int cnt[N];
vector<int> vec[N];
int fa[N];
int find(int x){if (fa[x]==x) return x;return fa[x]=find(fa[x]);}
int inv[N],fac[N];
int C(int n,int m)
{
	if (m<0 || m>n) return 0;
	if (m==0 || m==n) return 1;
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int n,m;
signed main()
{
	fac[0]=1;for (int i=1;i<=500000;i++) fac[i]=fac[i-1]*i%mod;
	inv[0]=1;for (int i=0;i<=500000;i++) inv[i]=ksm(fac[i]);
	cin>>n>>m;
	for (int i=1;i<=n;i++) can[i]=1;
	for (int i=1;i<=m+1;i++) fa[i]=i;
	for (int i=1;i<=n;i++)
	{
		int x,y,z;rd(x);rd(y);if (x==2) rd(z);else z=m+1;
		if (find(y)==find(z)) can[i]=0;
		else y=find(y),z=find(z),fa[y]=z;
	}
	for (int i=1;i<=m;i++) cnt[find(i)]++;
	int ans=ksm(2,cnt[find(m+1)]);
	for (int i=1;i<=m;i++) if (cnt[i]>1 && find(i)!=find(m+1))
	{
		int tmp=0;for (int j=0;j<=cnt[i]/2;j++) tmp+=C(cnt[i],j*2),tmp%=mod;
		ans=ans*tmp%mod;
	}
	int CNT=0;
	for (int i=1;i<=n;i++) if (can[i]) CNT++;
	cout<<ans<<" "<<CNT<<endl;
	for (int i=1;i<=n;i++) if (can[i]) cout<<i<<" ";
}