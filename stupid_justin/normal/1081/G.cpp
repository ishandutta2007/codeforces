#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
#define ri register signed
#define fi first
#define se second
#define IT map<int,int>::iterator
using namespace std;
int mod=998244353;
const int N=1e5+5;
inline int read(){int x=0,f=1;char ch=getchar();while((ch>'9' || ch<'0')){if(ch=='-') f=-1;ch=getchar();}while('0'<=ch && ch<='9') x=x*10+(ch^48),ch=getchar();return x*f;}
inline int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1LL) ret=ret*x%mod;x=x*x%mod;y>>=1LL;}return ret;}
int inv[N],sum[N];
void init(int n)
{
	inv[1]=1;for (ri i=2;i<=n;i++)inv[i]=inv[mod%i]*(mod-mod/i)%mod;
	for (ri i=1;i<=n;i++) sum[i]=(sum[i-1]+inv[i])%mod;
}

int k,n,ans;
map<int,int> S;

void MS(int l,int r,int h)
{
	//printf("MS(%lld,%lld,%lld)\n",l,r,h);
	if (h==k || l==r) {S[r-l+1]++;return;}
	int mid=(l+r)>>1;
	MS(l,mid,h+1);MS(mid+1,r,h+1);
}
int calc(int x,int y)
{
	int res=x*y%mod;
	for(ri i=1;i<=x;++i) res-=(sum[i+y]-sum[i])*2,res%=mod;
	return (res%mod+mod)%mod;
}
signed main()
{
	rd(n);rd(k);rd(mod);init(n);
	MS(1,n,1);
	for (IT X=S.begin();X!=S.end();X++)
	{
		int x=X->fi,y=X->se;
		ans+=x*(x-1)%mod*inv[2]%mod*y%mod;ans%=mod;
		ans+=y*(y-1)%mod*inv[2]%mod*calc(x,x)%mod;ans%=mod;
	}
	for (IT X=S.begin();X!=S.end();X++)
	for (IT Y=S.begin();Y!=S.end();Y++)
	{
		int x=X->fi,y=Y->fi,a=X->se,b=Y->se;
		if (x>=y) continue;
		ans+=calc(x,y)*a%mod*b%mod;ans%=mod;
	}
	ans=ans*inv[2]%mod;ans+=mod;ans%=mod;
	cout<<ans<<'\n';
}