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
int n,fa[2001];
vector<int> dep;
vector<int> query(int x)
{
	vector<int> q;
	cout<<"? "<<x+1<<endl;
	cout.flush();
	for(int i=0;i<n;i++)
	{
		int y=read();
		if(y==1)
			fa[i]=x;
		q.push_back(y);
	}
	return q;
} 
void solve(int x)
{
	vector<int> v=query(x);
	vector<int> path(dep[x]+1);
	path.push_back(x);
	for(int i=0;i<n;i++)
		if(dep[i]+v[i]==dep[x])
			path[dep[i]]=i;
	for(int i=1;i<=dep[x];i++)
		fa[path[i]]=path[i-1];
	for(int i=0;i<n;i++)
		if(dep[i]+v[i]==dep[x]+2)
			fa[i]=path[dep[i]-1];
}
signed main()
{
	n=read();
	memset(fa,-1,sizeof(fa));
	dep=query(0);
	for(int i=1;i<n;i++)
		if(fa[i]==-1)
			solve(i);
	puts("!");
	for(int i=1;i<n;i++)
		cout<<i+1<<" "<<fa[i]+1<<endl;
	return 0;
}