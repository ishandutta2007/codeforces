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
int n,m,k,s,vis[300001],a[300001];
vector<pair<int,int> > e[300001];
deque<int> ans1,ans2;
void dfs(int x,int fa,int ed)
{
	vis[x]=1;
	for(pair<int,int> i:e[x])
		if(!vis[i.first])
			dfs(i.first,x,i.second);
	if(fa)
	{
		if(a[x]>=k)
		{
			a[fa]+=a[x]-k;
			ans1.push_back(ed);
		}
		else
			ans2.push_front(ed);
	}
}
signed main()
{
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		s+=a[i];
	}
	if(s<(n-1)*k)
	{
		puts("NO");
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		e[x].push_back({y,i});
		e[y].push_back({x,i});
	}
	dfs(1,0,0);
	puts("YES");
	for(int i:ans1)
		cout<<i<<endl;
	for(int i:ans2)
		cout<<i<<endl;
	return 0;
}
//1