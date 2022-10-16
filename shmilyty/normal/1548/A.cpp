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
int t,n,m,q,num[200001];
void solve()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
		num[i]=0;
	int ans=n;
	while(m--)
	{
		int x=read(),y=read();
		if(x>y)
			swap(x,y);
		if(!num[x])
			ans--;
		num[x]++;
	} 
	q=read();
	while(q--)
	{
		int opt=read(),x,y;
		if(opt!=3)
		{
			x=read();
			y=read();
			if(x>y)
				swap(x,y);
		}
		else
			cout<<ans<<endl;
		if(opt==1)
		{
			if(!num[x])
				ans--;
			num[x]++;
		}
		if(opt==2)
		{
			num[x]--;
			if(!num[x])
				ans++;
		}
	}
}
signed main()
{
	solve();
	return 0;
}