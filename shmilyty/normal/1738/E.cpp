#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
inline int read()
{
	int x=0;
	bool flag=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
const int mod=998244353;
int t,n,ans,a[100001],b[100001],fac[200001],inv[200001],p[200001];
int C(int x,int y)
{
	if(x<y||y<0)
		return 0;
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int calc(int l,int r)//+1
{
	int res=0;
	for(int i=1;i<=min(l,r);i++)
		(res+=C(l,i)*C(r,i)%mod)%=mod;
	return res;
}
int solve(int l,int r)
{
	// cout<<l<<" "<<r<<'\n';
	if(l>=r)
		return 1;
	int res=1,s1=0,s2=a[r],R=r;
	for(int i=l;i<R;i++)
	{
		s1+=a[i];
		while(r-1>i&&(s2+a[r-1]<s1||(s2+a[r-1]==s1&&a[r-1])))
		{
			r--;
			s2+=a[r];
		}
		// cout<<i<<" "<<r<<'\n';
		if(r<=i)
			break;
		if(s1!=s2)
			continue;
		if(b[r-1]==b[i])
			return p[r-i];
		int ll=1,rr=1;
		for(int j=i+1;j<r;j++)
			if(a[j])
				break;
			else
				ll++;
		for(int j=r-1;j>i;j--)
			if(a[j])
				break;
			else
				rr++;
		int val=solve(ll+i,r-rr);
		(res+=val+mod-1+val*calc(ll,rr)%mod)%=mod;
		break;
	}
	return res;
}
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
		b[i]=b[i-1]+a[i];
	cout<<solve(1,n)<<'\n';
}
signed main()
{
	fac[0]=inv[0]=inv[1]=p[0]=1;
	for(int i=1;i<=200000;i++)
		p[i]=p[i-1]*2%mod;
	for(int i=1;i<=200000;i++)
		fac[i]=fac[i-1]*i%mod;
	for(int i=2;i<=200000;i++)
		inv[i]=mod-mod/i*inv[mod%i]%mod;
	for(int i=2;i<=200000;i++)
		(inv[i]*=inv[i-1])%=mod;
	t=read();
	while(t--)
		solve();
	return 0;
}