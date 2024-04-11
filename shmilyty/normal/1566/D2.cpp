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
int T,n,m,ans,t[301][302],pos[301][302];
array<int,3> a[90001];
bool cmp(array<int,3> x,array<int,3> y)
{
	if(x[0]==y[0])
		return x[1]<y[1];
	return x[0]<y[0];
}
bool c1(array<int,3> x,array<int,3> y)
{
	return x[1]<y[1];
}
void modify(int x,int y)
{
	for(;y<=m+1;y+=y&-y)
		t[x][y]++;
}
int query(int x,int y)
{
	int res=0;
	for(;y;y-=y&-y)
		res+=t[x][y];
	return res;
}
void solve()
{
	n=read();
	m=read();
	ans=0;
	for(int i=1;i<=n*m;i++)
		a[i]={read(),i,0};
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
		a[i][2]=i;
	sort(a+1,a+1+n*m,c1);
	for(int i=1;i<=n;i++)
		for(int l=0;l<=m+1;l++)
			t[i][l]=pos[i][l]=0;
	for(int i=1;i<=n*m;i++)
	{
		int s=a[i][2];
		int x=(s-1)/m+1,y=(s-1)%m+1;
		pos[x][y]=a[i][0];
		ans+=query(x,y);
		modify(x,y);
	}
	for(int i=1;i<=n;i++)
	{
		int lst=0,len=0;
		pos[i][m+1]=-1;
		for(int l=1;l<=m+1;l++)
			if(pos[i][l]!=lst)
			{
				ans-=(len-1)*len/2;
				len=1;
				lst=pos[i][l];
			}
			else
				len++;
	}
	cout<<ans<<endl;
}
signed main()
{
	T=read();
	while(T--)
		solve();
	return 0;
}