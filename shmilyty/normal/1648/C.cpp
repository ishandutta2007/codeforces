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
const int N=200000;
const int mod=998244353;
int n,m,cnt=1,sum,ans,a[200001],b[200001],fac[200001],t[200001],inv[200001],Inv[N+1];
int C(int x,int y)
{
	return fac[x]*Inv[y]%mod*Inv[x-y]%mod;
}
void add(int x,int y)
{
	for(;x<=N;x+=lowbit(x))
		t[x]+=y;
}
int query(int x)
{
	int res=0;
	for(;x;x^=lowbit(x))
		res+=t[x];
	return res;
}
signed main()
{
	n=read();
	m=read();
	fac[0]=inv[0]=inv[1]=Inv[0]=1;
	for(int i=1;i<=N;i++)
		fac[i]=fac[i-1]*i%mod;
	for(int i=2;i<=N;i++)
		inv[i]=mod-mod/i*inv[mod%i]%mod;
	for(int i=1;i<=N;i++)
		Inv[i]=Inv[i-1]*inv[i]%mod;
	for(int i=1;i<=n;i++)
	{
		int x=read();
		a[x]++;
		add(x,1);
	}
	for(int i=1;i<=m;i++)
		b[i]=read();
	for(int i=1;i<=N;i++)
		if(a[i])
		{
			(cnt*=C(sum+a[i],a[i]))%=mod;
			sum+=a[i];
		}
	for(int i=1;i<=n;i++)
	{
		(ans+=query(b[i]-1)*inv[n-i+1]%mod*cnt%mod)%=mod;
		if(!a[b[i]])
			break;
		if(i==m)
			break;
		if(i==n)
			(ans+=1)%=mod;
		(cnt*=inv[n-i+1]*a[b[i]]%mod)%=mod;
		a[b[i]]--;
		add(b[i],-1);
	}
	cout<<ans;
	return 0;
}