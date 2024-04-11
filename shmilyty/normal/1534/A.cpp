#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
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
int t,n,m,mp[51][51],p1,p2; 
void solve()
{
	n=read();
	m=read();
	p1=p2=-1;
	memset(mp,0,sizeof(mp));
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		for(int l=0;l<m;l++)
		{
			if(s[l]=='R')
			{
				p1=(i+l+1)%2;
				mp[i][l+1]=1;
			}
			if(s[l]=='W')
			{
				p2=(i+l+1)%2;
				mp[i][l+1]=2;
			}
		}	
	}
	if(p1==-1&&p2==-1)
	{
		p1=1;
		p2=0;
	}
	if(p1==-1)
		p1=1-p2;
	if(p2==-1)
		p2=1-p1;
	if(p1==p2)
	{
		puts("No");
		return ;
	}
	for(int i=1;i<=n;i++)
		for(int l=1;l<=m;l++)
			if((i+l)%2==p1)
			{
				if(mp[i][l]==2)
				{
					puts("No");
					return ;
				}
				mp[i][l]=1;
			}
			else
			{
				if(mp[i][l]==1)
				{
					puts("No");
					return ;
				}
				mp[i][l]=2;
			}
	puts("Yes");
	for(int i=1;i<=n;i++)
	{
		for(int l=1;l<=m;l++)
			cout<<(mp[i][l]==1?"R":"W");
		cout<<endl;
	}
	return ;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}