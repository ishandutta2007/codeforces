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
int n,res,a[2],p[100001],ans[100001],to[100001][2];
map<int,int> mp;
signed main()
{
	n=read();
	a[0]=read();
	a[1]=read();
	for(int i=1;i<=n;i++)
	{
		p[i]=read();
		mp[p[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		to[i][0]=to[i][1]=-1;
		for(int l=0;l<2;l++)
			if(mp[a[l]-p[i]])
				to[i][l]=mp[a[l]-p[i]];
	}
	fill(ans+1,ans+1+n,-1);
	for(int i=1;i<=n;i++)
		if(ans[i]==-1)
		{
			if(to[i][0]+to[i][1]==-2)
			{
				puts("NO");
				return 0; 
			}
			if(to[i][0]*to[i][1]>0)
				continue;
			int cnt=(to[i][0]==-1)?1:0,c1=cnt,now=i;
			while(to[now][c1]!=-1)
			{
				ans[now]=cnt;
				now=to[now][c1];
				c1^=1;
			}
			if(c1==cnt)
			{
				puts("NO");
				return 0;
			}
		}
	for(int i=1;i<=n;i++)
		if(ans[i]==-1)
		{
			if(to[i][0]*to[i][1]>0&&to[i][0]!=i&&to[i][1]!=i)
				continue;
			int cnt=(to[i][0]==-1||to[i][1]==i)?1:0,c=cnt,len=1,now=i;
			ans[now]=cnt;
			if(to[i][c]==i)
				c^=1;
			if(now==to[now][c]||to[now][c]==-1)
				continue;
			now=to[now][c];
			c^=1;
			while(1)
			{
				ans[now]=cnt;
				len++;
				now=to[now][c];
				c^=1;
				if(now==-1)
					break;
				if(now==to[now][c])
				{
					len++;
					break;
				}
			}
			if(len&1)
			{
				puts("NO");
				return 0;
			}
		}
	puts("YES");
	for(int i=1;i<=n;i++)
		if(ans[i]==-1)
			cout<<"0 ";
		else
			cout<<ans[i]<<" ";
	return 0;
}