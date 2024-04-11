#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
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
int t,n,cnt,sum,tot,a[100001],jie[100001];
string s;
const int mod=998244353;
int p(int x,int y)
{
	if(x<=1)
		return x;
	if(y==0)
		return 1;
	if(y==1)
		return x;
	int res=p(x,y/2);
	(res*=res)%=mod;
	if(y&1)
		(res*=x)%=mod;
	return res; 
}
int C(int x,int y)
{
	return (jie[y]*p(jie[y-x],mod-2))%mod*p(jie[x],mod-2)%mod; 
}
void solve()
{
	n=read();
	cin>>s;
	cnt=tot=0;
	sum=n;
	for(int i=0;i<n;i++)
		a[i+1]=s[i]-'0';
	for(int i=1;i<=n;i++)
		if(a[i])
		{
			cnt++;
			tot+=cnt/2;
			cnt%=2;
		}
		else
		{
			sum-=cnt;
			cnt=0;
		}
	sum-=cnt;
	cout<<C(tot,sum-tot)<<endl;
}
signed main()
{
	jie[0]=1;
	for(int i=1;i<=100000;i++)
		jie[i]=(jie[i-1]*i)%mod;
	t=read();
	while(t--)
		solve();
	return 0;
}