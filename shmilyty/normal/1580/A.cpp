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
int t,n,m,ans,f[401][401];
int area(int x,int y,int xx,int yy)
{
	return max(0ll,f[xx][yy]+f[x-1][y-1]-f[x-1][yy]-f[xx][y-1]);
}
int cal(int x,int y,int xx,int yy)
{
	return area(x+1,y+1,xx-1,yy-1)+(xx-x-1)*2+(yy-y-1)*2-area(x+1,y,xx-1,y)-area(x+1,yy,xx-1,yy)-area(x,y+1,x,yy-1)-area(xx,y+1,xx,yy-1);
}
void solve()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		for(int l=1;l<=m;l++)
			f[i][l]=f[i-1][l]+f[i][l-1]-f[i-1][l-1]+s[l-1]-'0';
	}
	ans=INF;
	for(int i=1;i+4<=n;i++)
		for(int l=1;l+3<=m;l++)
			for(int k=l+3;k<=m;k++)
				for(int j=i+4;j<=n;j++)
				{
					int res=area(i+1,l+1,j-1,k-1)+(j-i-1)*2+(k-l-1)-area(i+1,l,j-1,l)-area(i+1,k,j-1,k)-area(i,l+1,i,k-1);
					if(res>ans)
						break;
					res+=(k-l-1)-area(j,l+1,j,k-1);
					ans=min(ans,res);
				}
	cout<<ans<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}