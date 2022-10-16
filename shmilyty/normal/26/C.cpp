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
int n,m,nn,mm,a,b,c;
char ans[101][101];
signed main()
{
	nn=n=read();
	mm=m=read();
	a=read();
	b=read();
	c=read();
	if((n*m)&1)
	{
		puts("IMPOSSIBLE");
		return 0;
	}
	if(2*a+2*b+4*c<n*m)
	{
		puts("IMPOSSIBLE");
		return 0;
	}
	if(n&1)
	{
		if(a*2<m)
		{
			puts("IMPOSSIBLE");
			return 0;
		}
		a-=m/2;
		for(int i=1;i<=m;i+=2)
			if(i%4==1)
				ans[n][i]=ans[n][i+1]='y';
			else
				ans[n][i]=ans[n][i+1]='z';
		n--;
	}
	if(m&1)
	{
		if(b*2<n)
		{
			puts("IMPOSSIBLE");
			return 0;
		}
		b-=n/2;
		for(int i=1;i<=n;i+=2)
			if(i%4==1)
				ans[i][m]=ans[i+1][m]='y';
			else
				ans[i][m]=ans[i+1][m]='z';
		m--;
	}
	for(int i=1;i<=n;i+=2)
		for(int l=1;l<=m;l+=2)
		{
			if(c)
			{
				c--;
				if((i+l)%4==2)
					ans[i][l]=ans[i+1][l]=ans[i][l+1]=ans[i+1][l+1]='a';
				else
					ans[i][l]=ans[i+1][l]=ans[i][l+1]=ans[i+1][l+1]='b';
				continue;
			}
			if(a>1)
			{
				a-=2;
				if((i+l)%4==2)
				{
					ans[i][l]=ans[i][l+1]='c';
					ans[i+1][l]=ans[i+1][l+1]='d';
				}
				else
				{
					ans[i][l]=ans[i][l+1]='e';
					ans[i+1][l]=ans[i+1][l+1]='f';
				}
				continue;
			}
			if(b>1)
			{
				b-=2;
				if((i+l)%4==2)
				{
					ans[i][l]=ans[i+1][l]='g';
					ans[i][l+1]=ans[i+1][l+1]='h';
				}
				else
				{
					ans[i][l]=ans[i+1][l]='i';
					ans[i][l+1]=ans[i+1][l+1]='j';
				}
				continue;
			}
			puts("IMPOSSIBLE");
			return 0;
		}
	for(int i=1;i<=nn;i++)
	{
		for(int l=1;l<=mm;l++)
			cout<<ans[i][l];
		cout<<endl;
	}
	return 0;
}