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
int t,n,a[50001][5];
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
		for(int l=0;l<5;l++)
			a[i][l]=read();
	int id=1;
	for(int i=2;i<=n;i++)
	{
		int tot=0;
		for(int l=0;l<5;l++)
			if(a[id][l]>a[i][l])
				tot++;
		if(tot>=3)
			id=i;
	}
	for(int i=1;i<=n;i++)
	{
		if(i==id)
			continue;
		int tot=0;
		for(int l=0;l<5;l++)
			if(a[id][l]<a[i][l])
				tot++;
		if(tot<3)
		{
			puts("-1");
			return ;
		}
	}
	cout<<id<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}