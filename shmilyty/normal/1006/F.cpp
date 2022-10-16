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
int n,m,k,ans,a[21][21];
unordered_map<int,int> num[21];
void dfs(int x,int y,int cnt)
{
	if(x+y==n+1)
	{
		num[x][cnt]++;
//		cout<<x<<" "<<y<<" "<<cnt<<endl;
		return ;
	}
	cnt^=a[x][y];
	if(x!=n)
		dfs(x+1,y,cnt);
	if(y!=m)
		dfs(x,y+1,cnt);
}
void dfs1(int x,int y,int cnt)
{
	cnt^=a[x][y];
//	cout<<x<<" "<<y<<" "<<cnt<<endl;
	if(x+y==n+1)
	{
//		cout<<x<<" "<<y<<" "<<cnt<<endl;
		ans+=num[x][cnt^k];
		return ;
	}
	if(x!=1)
		dfs1(x-1,y,cnt);
	if(y!=1)
		dfs1(x,y-1,cnt);
}
signed main()
{
//	freopen("data.txt","r",stdin);
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=n;i++)
		for(int l=1;l<=m;l++)
			a[i][l]=read();
	dfs(1,1,0);
	dfs1(n,m,0);
	cout<<ans;
	return 0;
}