#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(a) a.begin(),a.end()
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
int t,n,N=200000,m,a[400001],p[200001],fac[400001],inv[400001];
const int mod=998244353;
int lowbit(int x)
{
	return x&(-x);
}
void add(int x,int v)
{
	for(;x<=N;x+=lowbit(x))
		a[x]+=v;
}
int query(int x)
{
	int ans=0;
	for(int i=17;i>=0;i--)
		if(ans+(1<<i)<=N&&x>=a[ans+(1<<i)])
		{
			x-=a[ans+(1<<i)];
			ans+=(1<<i);
		}
	return ans+1;
}
int C(int x,int y)
{
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
void solve()
{
	n=read();
	m=read();
	vector<int> v1,v2;
	for(int i=1;i<=m;i++)
	{
		read();
		p[i]=read();
	}
	for(int i=m;i>=1;i--)
	{
		int x=query(p[i]+1),y=query(p[i]); 
		v1.push_back(y);
		v2.push_back(x);
		add(y,-1);
	}
	for(int i:v1)
		add(i,1);
	sort(ALL(v2));
	v2.resize(unique(ALL(v2))-v2.begin());
	cout<<C(2*n-1-v2.size(),n)<<endl;
}
signed main()
{
	fac[0]=1;
	for(int i=1;i<=4e5;i++)
		fac[i]=(fac[i-1]*i)%mod;
	inv[0]=inv[1]=1;
	for(int i=2;i<=4e5;i++)
		inv[i]=(mod-inv[mod%i]*(mod/i)%mod);
	for(int i=2;i<=4e5;i++)
		(inv[i]*=inv[i-1])%=mod;
	t=read();
	for(int i=1;i<=200000;i++)
		add(i,1);
	while(t--)
		solve();	
	return 0;
}