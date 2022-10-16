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
int n,m,ans,num[100000],f[21][1<<20]; 
signed main()
{
	n=read();
	m=read();
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		for(int l=0;l<m;l++)
		{
			num[l]<<=1;
			if(s[l]=='1')
				num[l]|=1; 
		}
	}
	for(int i=0;i<m;i++)
		f[0][num[i]]++;
	for(int i=0;i<n;i++)
		for(int l=n;l;l--)
			for(int j=0;j<(1<<n);j++)
				f[l][j]+=f[l-1][j^(1<<i)];
	ans=n*m;
	for(int i=0;i<(1<<n);i++)
	{
		int res=0;
		for(int l=0;l<=n;l++)
			res+=f[l][i]*min(l,n-l);
		ans=min(res,ans);
	}
	cout<<ans;
	return 0;
}