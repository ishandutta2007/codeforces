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
int n,mp[51][51],f[51][51][51][51];
int dfs(int x,int xx,int y,int yy)
{
	if(~f[x][xx][y][yy])
		return f[x][xx][y][yy];
	if(x==xx||y==yy)
	{
		int res=0;
		for(int i=x;i<=xx;i++)
			for(int l=y;l<=yy;l++)
				res+=mp[i][l];
		return res;
	}
	int &res=f[x][xx][y][yy];
	res=max(xx-x+1,yy-y+1);
	for(int i=x;i<xx;i++)
		res=min(res,dfs(x,i,y,yy)+dfs(i+1,xx,y,yy));
	for(int i=y;i<yy;i++)
		res=min(res,dfs(x,xx,y,i)+dfs(x,xx,i+1,yy));
	return res;	
} 
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		for(int l=0;l<n;l++)
			if(s[l]=='#')
				mp[i][l+1]=1;
	}
	memset(f,-1,sizeof(f)); 
	cout<<dfs(1,n,1,n);
	return 0;
}