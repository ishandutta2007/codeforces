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
int n,m,k,ans,cnt,a[101];
signed main()
{
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=k;i++)
		a[i]=read();
	while(n--)
		for(int i=1;i<=m;i++)
		{
			int x=read();
			for(cnt=1;a[cnt]!=x;cnt++);
			ans+=cnt;
			for(;cnt>1;cnt--)
				swap(a[cnt],a[cnt-1]);
		}
	cout<<ans;
	return 0;
}