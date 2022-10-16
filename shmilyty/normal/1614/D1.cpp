#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
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
const int N=5e6;
int n,a[100001],p[N+1],s[N+1],f[N+1];
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		p[a[i]]++;
	}
	for(int i=1;i<=N;i++)
		for(int l=i;l<=N;l+=i)
			s[i]+=p[l];
	for(int i=1;i<=N;i++)
		f[i]=s[i]*i;
	for(int i=N;i;i--)
	{
		int t=0;
		for(int l=i;l<=N;l+=i)
			t=max(t,f[l]+(s[i]-s[l])*i);
		f[i]=t;
	}
	cout<<f[1];
}
signed main()
{
	solve(); 
	return 0;
}