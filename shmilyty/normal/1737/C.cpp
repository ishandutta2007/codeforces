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
int T,n;
void solve()
{
	n=read();
	int x1=read(),y1=read(),x2=read(),y2=read(),x3=read(),y3=read();
	int xx=read(),yy=read();
	int x=(x1^x2^x3),y=(y1^y2^y3);
	int tx[4]={1,1,n,n};
	int ty[4]={1,n,1,n};
	// cout<<x<<" "<<y<<'\n';
	x=(x1+x2+x3-x)/2,y=(y1+y2+y3-y)/2;
	// cout<<x<<" "<<y<<'\n';
	for(int i=0;i<4;i++)
		if(x==tx[i]&&y==ty[i])
		{
			// puts("ok");
			if(xx==tx[i]||yy==ty[i])
				puts("YES");
			else
				puts("NO");
			return ;
		}
	if((abs(xx-x)&1)&&(abs(yy-y)&1))
		puts("NO");
	else
		puts("YES");
}
signed main()
{
	T=read();
	while(T--)
		solve();
	return 0;
}