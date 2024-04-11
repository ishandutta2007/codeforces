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
int t,n,m,isbi,a[200001],b[200001],fa[400001];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void solve()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
		b[i]=read();
	for(int i=1;i<=2*n;i++)
		fa[i]=i;
	isbi=1;
	while(m--)
	{
		int x=read(),y=read();
		if(!isbi)
			continue;
		if(find(x)==find(y))
		{
			isbi=0;
			continue;
		}
		fa[find(x)]=find(y+n);
		fa[find(x+n)]=find(y);
	}
	if(isbi)
	{
		int s1=0,s2=0;
		for(int i=1;i<=n;i++)
			if(find(i)==find(1))
			{
				s1+=a[i];
				s2+=b[i];
			}
			else
			{
				s1-=a[i];
				s2-=b[i];
			}
		s1==s2?puts("YES"):puts("NO");
		return ;
	}
	int s1=0,s2=0;
	for(int i=1;i<=n;i++)
	{
		(s1+=abs(a[i]))%=2;
		(s2+=abs(b[i]))%=2;
	}
	s1==s2?puts("YES"):puts("NO");
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}