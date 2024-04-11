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
int n,ans,a[5002];
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	ans=INF;
	for(int i=1;i<=n;i++)
	{
		int res=0;
		int lst=0;
		for(int l=i-1;l;l--)
		{
			int x=lst/a[l]+1;
			res+=x;
			lst=a[l]*x;
		}
		lst=0;
		for(int l=i+1;l<=n;l++)
		{
			int x=lst/a[l]+1;
			res+=x;
			lst=a[l]*x;
		}
		ans=min(ans,res);
	}
	cout<<ans;
	return 0;
}