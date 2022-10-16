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
int n,m;
array<int,2> a[502];
vector<int> v[200001],v1[200001];
signed main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		int x=read(),y=read();
		a[i]={x,y};
	}
	a[0]=a[n];
	a[n+1]=a[1];
	for(int i=1;i<=m;i++)
		v[read()].push_back(i);
	for(int i=1;i<=200000;i++)
		v1[i]=v[i];
	bool ok=1;
	for(int i=1;i<=n;i+=2)
	{
		int d=abs(a[i][0]-a[i-1][0])+abs(a[i][1]-a[i-1][1])+abs(a[i+1][0]-a[i][0])+abs(a[i+1][1]-a[i][1]);
		if(v1[d].empty())
		{
			ok=0;
			break;
		}
		v1[d].pop_back();
	}
	if(ok)
	{
		puts("YES");
		for(int i=1;i<=200000;i++)
			v1[i]=v[i];
		for(int i=1;i<=n;i++)
		{
			if(i%2==0)
			{
				cout<<"-1 ";
				continue;
			}
			int d=abs(a[i][0]-a[i-1][0])+abs(a[i][1]-a[i-1][1])+abs(a[i+1][0]-a[i][0])+abs(a[i+1][1]-a[i][1]);
			cout<<v1[d].back()<<" ";
			v1[d].pop_back();
		}
		return 0;
	}
	for(int i=1;i<=200000;i++)
		v1[i]=v[i];
	ok=1;
	for(int i=2;i<=n;i+=2)
	{
		int d=abs(a[i][0]-a[i-1][0])+abs(a[i][1]-a[i-1][1])+abs(a[i+1][0]-a[i][0])+abs(a[i+1][1]-a[i][1]);
		if(v1[d].empty())
		{
			ok=0;
			break;
		}
		v1[d].pop_back();
	}
	if(ok)
	{	
		puts("YES");
		for(int i=1;i<=200000;i++)
			v1[i]=v[i];
		for(int i=1;i<=n;i++)
		{
			if(i&1)
			{
				cout<<"-1 ";
				continue;
			}
			int d=abs(a[i][0]-a[i-1][0])+abs(a[i][1]-a[i-1][1])+abs(a[i+1][0]-a[i][0])+abs(a[i+1][1]-a[i][1]);
			cout<<v1[d].back()<<" ";
			v1[d].pop_back();
		}
		return 0;
	}
	puts("NO");
	return 0;
}