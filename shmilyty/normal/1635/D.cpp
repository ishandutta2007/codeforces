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
int n,p,ans,a[200001],f[200001];
const int mod=1e9+7;
set<int> s;
signed main()
{
	n=read();
	p=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		int x=a[i],ok=1;
		while(x)
		{
			if(x&1)
				x>>=1;
			elif(x%4==0)
				x>>=2;
			else
				break;
			if(s.find(x)!=s.end())
			{
				ok=0;
				break;
			}
		}
		if(ok)
		{
			s.insert(a[i]);
			f[(int)log2(a[i])]++;
		}
	}
	ans=f[0];
	for(int i=1;i<p;i++)
	{
		(f[i]+=f[i-1])%=mod;
		if(i!=1)
			(f[i]+=f[i-2])%=mod;
		(ans+=f[i])%=mod;
	}
	cout<<ans;
	return 0;
}