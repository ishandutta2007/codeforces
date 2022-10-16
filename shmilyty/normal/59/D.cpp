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
int n,k,vis[300001],out[300001];
queue<int> q;
array<int,3> a[300001];
vector<int> v1;
signed main()
{
	n=read();
	for(int i=1;i<=3*n;i++)
		q.push(read());
	for(int i=1;i<=n;i++)
	{
		int x=read(),y=read(),z=read();
		a[i]={x,y,z};
	}
	k=read();
	for(int i=1;i<=n;i++)
	{
		while(vis[q.front()])
			q.pop();
		int f=q.front();
		q.pop();
		vis[a[i][0]]=vis[a[i][1]]=vis[a[i][2]]=1;
		if(a[i][0]!=k&&a[i][1]!=k&&a[i][2]!=k)
			continue;
		if(f!=k)
		{
			for(int l=1;l<=3*n;l++)
				if(k!=l)
					cout<<l<<" ";
			return 0;
		}
		int x=0;
		for(int l=0;l<3;l++)
			if(a[i][l]!=f)
				x=max(x,a[i][l]);
		for(int l=1;l<=x;l++)
			if(vis[l]&&(f!=l))
				cout<<l<<" ";
		for(int l=1;l<=3*n;l++)
			if(((!vis[l])||l>x)&&(f!=l))
				cout<<l<<" ";
		return 0;
	}
	return 0;
}