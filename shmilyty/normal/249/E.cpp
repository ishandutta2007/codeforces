#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int __int128
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
int f(int x,int y)
{
	if(x<y)
		return x*x*(x*x+1)/2+(y-x)*x*(x+1)/2+x*(y*(y-1)*(2*y-1)/6-x*(x-1)*(2*x-1)/6);
	else
		return y*y*(y*y+1)/2-(x-y)*y*(y-1)/2+y*(x*(x+1)*(2*x+1)/6-y*(y+1)*(2*y+1)/6);
}
int t,x,y,x1,y1;
signed main()
{
	t=read();
	while(t--)
	{
		x=read();
		y=read();
		x1=read();
		y1=read();
		int ans=f(x1,y1)+f(x-1,y-1)-f(x-1,y1)-f(x1,y-1);
		if(ans>=10000000000)
		{
			string s;
			for(int i=0;i<10;i++,ans/=10)
				s+=(char)('0'+ans%10);
			s+="...";
			reverse(s.begin(),s.end());
			cout<<s<<'\n';
		}
		else
		{
			long long out=ans;
			cout<<out<<'\n';
		}
	}
	return 0;
}