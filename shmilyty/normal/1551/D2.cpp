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
int t,n,m,k;
char ans[101][101];
void o1(int x,int y,int z)
{
	for(int i=0;i<x/2;i++)
	{
		for(int l=0;l<y/2;l++)
		{
			if(z)
			{
				z-=2;
				if(i%2==l%2)
				{
					ans[i*2][l*2]=ans[i*2][l*2+1]='a';
					ans[i*2+1][l*2]=ans[i*2+1][l*2+1]='b';
				}
				else
				{
					ans[i*2][l*2]=ans[i*2][l*2+1]='c';
					ans[i*2+1][l*2]=ans[i*2+1][l*2+1]='d';
				}
			}
			else
			{
				if(i%2==l%2)
				{
					ans[i*2][l*2]=ans[i*2+1][l*2]='a';
					ans[i*2][l*2+1]=ans[i*2+1][l*2+1]='b';
				}
				else
				{
					ans[i*2][l*2]=ans[i*2+1][l*2]='c';
					ans[i*2][l*2+1]=ans[i*2+1][l*2+1]='d';
				}
			}
		}
	}
}
void outp(int x,int y)
{
	for(int i=0;i<x;i++)
	{
		for(int l=0;l<y;l++)
			cout<<ans[i][l];
		cout<<endl;
	}
}
void solve()
{
	n=read();
	m=read();
	k=read();
	if(n%2==0&&m%2==0)
	{
		if(k&1)
			puts("NO");
		else
		{
			puts("YES");
			o1(n,m,k);
			outp(n,m);
		}
		return ;
	}
	int kk=n*m/2-k;
	if(n&1)
	{
		m/=2;
		if(kk&1)
			puts("NO");
		else
		if(m%2==k%2&&k>=m)
		{
			puts("YES");
			o1(n-1,m*2,k-m);
			for(int i=0;i<m;i++)
			{
				if(i&1)
					ans[n-1][i*2]=ans[n-1][i*2+1]='e';
				else
					ans[n-1][i*2]=ans[n-1][i*2+1]='f'; 
			}
			outp(n,m*2);
		}
		else
			puts("NO");
		return ;
	}
	n/=2;
	if(k&1)
		puts("NO");
	else
	if(n%2==kk%2&&kk>=n)
	{
		puts("YES");
		o1(n*2,m-1,k);
		for(int i=0;i<n;i++)
		{
			if(i&1)
				ans[i*2][m-1]=ans[i*2+1][m-1]='e';
			else
				ans[i*2][m-1]=ans[i*2+1][m-1]='f';
		}
		outp(n*2,m);
	}
	else
		puts("NO");
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}