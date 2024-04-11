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
const int mod=1e9+7;
int n,cnt,a[200001],f[2][2][31],ans;
vector<int> v;
int qp(int x,int y)
{
	int res=1;
	while(y)
	{
		if(y&1)
			(res*=x)%=mod;
		y>>=1;
		(x*=x)%=mod;
	}
	return res;
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	ans=qp(2,n);
	for(int i=1;i<=n;i++)
	{
		int res=0,x=a[i];
		while(x%2==0)
		{
			res++;
			x>>=1;
		}
		if(res)
			v.push_back(res);
	}
	f[0][0][30]=1;
	for(int i=0;i<v.size();i++,cnt^=1)
	{
		for(int l=0;l<31;l++)
		{
			f[cnt^1][0][l]=f[cnt][0][l];
			f[cnt^1][1][l]=f[cnt][1][l];
		}
		for(int l=0;l<31;l++)
			if(l>v[i])
				(f[cnt^1][0][v[i]]+=f[cnt][0][l]+f[cnt][1][l])%=mod;
			elif(l==v[i])
			{
				(f[cnt^1][0][l]+=f[cnt][1][l])%=mod;
				(f[cnt^1][1][l]+=f[cnt][0][l])%=mod;
			}
			else
			{
				(f[cnt^1][0][l]+=f[cnt][0][l])%=mod;
				(f[cnt^1][1][l]+=f[cnt][1][l])%=mod;
			}
	}
	for(int i=0;i<31;i++)
		(ans+=mod-f[cnt][0][i])%=mod;
	cout<<ans;
	return 0;
}