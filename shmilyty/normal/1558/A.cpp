#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
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
int t,a,b,n,ok[200001];
void solve()
{
	a=read();
	b=read();
	n=a+b;
	for(int i=0;i<=n;i++)
		ok[i]=0;
	for(int i=0;i<=(n+1)/2;i++)//abababa... 
	{
		int x=i,y=a-i;
		int xx=(n+1)/2-x,yy=n/2-y;
		if(y<0||xx<0||yy<0)
			continue;
		ok[y+xx]=1;
	} 
	for(int i=0;i<=n/2;i++)//babababa
	{
		int x=i,y=a-i;
		int xx=n/2-x,yy=(n+1)/2-y;
		if(y<0||xx<0||yy<0)
			continue;
		ok[y+xx]=1;
	}
	int num=0;
	for(int i=0;i<=n;i++)
		num+=ok[i];
	cout<<num<<endl;
	for(int i=0;i<=n;i++)
		if(ok[i])
			cout<<i<<" ";
	cout<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}