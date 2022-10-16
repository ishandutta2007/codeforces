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
int n,m,cnt,fa[200001];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int mod=1e9+7;
int qp(int y)
{
	if(y==1)
		return 2;
	if(y==0)
		return 1;
	int ans=qp(y/2);
	(ans*=ans)%=mod;
	if(y&1)
		(ans<<=1)%=mod;
	return ans;
}
signed main()
{
	n=read();
	m=read();
	for(int i=1;i<=2*n;i++)
		fa[i]=i;
	while(m--)
	{
		int x=read(),y=read(),z=read();
		if(z==1)
		{
			if(find(x)==find(y+n))
			{
				puts("0");
				return 0;
			}
			fa[find(x)]=find(y);
			fa[find(x+n)]=find(y+n);
		}
		else
		{
			if(find(x)==find(y))
			{
				puts("0");
				return 0;
			}
			fa[find(x+n)]=find(y);
			fa[find(y+n)]=find(x);
		}
	}
	for(int i=1;i<=2*n;i++)
		if(find(i)==i)
			cnt++;
	cnt/=2;
	cout<<qp(cnt-1);
	return 0;
}