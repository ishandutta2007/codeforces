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
int n,a[101],sx,sy,tx,ty,ans;
signed main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	sx=read();
	sy=read();
	tx=read();
	ty=read();
	for(int i=min(sx,tx);i<=max(sx,tx);i++)
		sy=min(sy,a[i]+1);
	ans=INF;
	for(int i=min(sx,tx),l=sy;i>=1;i--)
	{
		l=min(l,a[i]+1);
		ans=min(ans,abs(l-ty)+2*(min(sx,tx)-i)+abs(sx-tx));
	}
	for(int i=max(sx,tx),l=sy;i<=n;i++)
	{
		l=min(l,a[i]+1);
		ans=min(ans,abs(l-ty)+2*(i-max(sx,tx))+abs(sx-tx));
	}
	cout<<ans;
	return 0;
}