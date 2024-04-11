#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
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
int t,n,m,vis[100000],mst[100000],num[100000];
vector<int> p[100000],ok[100000];
bool check(int x)
{
	fill(vis,vis+m,0);
	fill(mst,mst+n,0);
	fill(num,num+n,0);
	for(int i=0;i<m;i++)
		ok[i].clear();
	for(int i=0;i<m;i++)
		for(int l=0;l<n;l++)
			ok[i].push_back(0);
	for(int i=0;i<n;i++)
		for(int l=0;l<m;l++)
			if(p[i][l]>=x)
			{
				ok[l][i]=1;
				vis[l]++;
				num[i]++;
			}
	for(int i=0;i<m;i++)
		if(!vis[i])
			return 0;
	for(int i=0;i<m;i++)
		for(int l=0;l<n;l++)
			if(vis[i]==1&&ok[i][l])
				mst[l]=1;
	int res=0;
	for(int i=0;i<n;i++)
		res+=mst[i];
	if(res>=m)
		return 0;
	for(int i=0;i<n;i++)
		if(num[i]>1)
			return 1;
	return 0;
}
void solve()
{
	n=read();
	m=read();
	for(int i=0;i<n;i++)
	{
		p[i].clear();
		for(int l=1;l<=m;l++)
			p[i].push_back(read());
	}
//	cout<<check(9)<<endl;
//	/*
	int l=1,r=1000000000;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
			l=mid+1;
		else
			r=mid-1;
	}
	cout<<l-1<<endl;
//	*/
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}