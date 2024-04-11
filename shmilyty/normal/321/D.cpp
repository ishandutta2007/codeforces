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
int n,k,ans,a[40][40],b[40][40];
void ad(int &res,int x,int y)
{
	res+=b[x][y]?-a[x][y]:a[x][y];
}
int solve1(int x,int y,int v)
{
	b[x][y]=v;
	b[x+k][y]=b[x][y]^b[k-1][y];
	b[x][y+k]=b[x][y]^b[x][k-1];
	b[x+k][y+k]=b[x+k][y]^b[x+k][k-1];
	assert(b[x+k][y+k]==(b[x][y+k]^b[k-1][y+k]));
	int res=0;
	ad(res,x,y);
	ad(res,x+k,y);
	ad(res,x,y+k);
	ad(res,x+k,y+k);
	return res;
}
int solve(int x,int v)
{
	b[x][k-1]=v;
	b[x+k][k-1]=v^b[k-1][k-1];
	int res=0;
	ad(res,x,k-1);
	ad(res,x+k,k-1);
	for(int i=0;i<k-1;i++)
		res+=max(solve1(x,i,0),solve1(x,i,1));
	return res;
}
signed main()
{
	n=read();
	for(int i=0;i<n;i++)
		for(int l=0;l<n;l++)
			a[i][l]=read();
	k=(n+1)/2;
	for(int i=0;i<(1<<k);i++)
	{
		for(int l=0;l<k;l++)
			b[k-1][l]=((i>>l)&1);
		for(int l=k;l<n;l++)
			b[k-1][l]=(b[k-1][k-1]^b[k-1][l-k]);
		int res=0;
		for(int l=0;l<n;l++)
			ad(res,k-1,l);
		for(int l=0;l<k-1;l++)
			res+=max(solve(l,0),solve(l,1));
		ans=max(ans,res);
	}
	cout<<ans;
	return 0;
}