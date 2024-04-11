#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
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
int n,m,ans,minn;
signed main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		minn=114514114514114514;
		for(int l=1;l<=m;l++)
			minn=min(minn,read());
		ans=max(ans,minn);
	}
	cout<<ans;
	return 0;
}