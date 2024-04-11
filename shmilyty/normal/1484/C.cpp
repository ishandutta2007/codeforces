#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	bool flag=1;
	int x=0;
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
int t,n,m,vis[100001],x[100001],num[100001];
vector<int> v[100001];
void solve()
{
	n=read();
	m=read();
	for(int i=1;i<=m;i++)
		v[i].clear();
	memset(vis,0,sizeof(vis));
	memset(num,0,sizeof(num));
	for(int i=1;i<=m;i++)
	{
		int x=read();
		while(x--)
			v[i].push_back(read());
	}
	for(int i=1;i<=m;i++)
		if(v[i].size()==1)
		{
			num[v[i][0]]++;
			if(num[v[i][0]]>(m+1)/2)
			{
				puts("NO");
				return ;
			}
			vis[i]=v[i][0];
		}
	for(int i=1;i<=m;i++)
		if(!vis[i])
		{
			for(int l:v[i])
				if(num[l]<(m+1)/2)
				{
					num[l]++;
					vis[i]=l;	
					break;
				}	
			if(!vis[i])
			{
				puts("NO");
				return ;
			}
		}	
	puts("YES");
	for(int i=1;i<=m;i++)
		cout<<vis[i]<<" ";
	cout<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	
	return 0;
}