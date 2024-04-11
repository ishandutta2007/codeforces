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
int n,k,a[501][501],num[250001],mx1[250001],mx2[250001],mn1[250001],mn2[250001],f[502][502];
void add(int x,int y,int xx,int yy)
{
	x=max(x,1ll);
	y=max(y,1ll);
	f[x][y]++;
	f[x][yy+1]--;
	f[xx+1][y]--;
	f[xx+1][yy+1]++;
}
signed main()
{
	n=read();
	k=read();
	memset(mn1,0x3f,sizeof(mn1));
	memset(mn2,0x3f,sizeof(mn2));
	for(int i=1;i<=n;i++)
		for(int l=1;l<=n;l++)
		{
			a[i][l]=read();
			num[a[i][l]]=1;
			mn1[a[i][l]]=min(mn1[a[i][l]],i);
			mn2[a[i][l]]=min(mn2[a[i][l]],l);
			mx1[a[i][l]]=max(mx1[a[i][l]],i);
			mx2[a[i][l]]=max(mx2[a[i][l]],l);
		}
	int sum=0;
	for(int i=1;i<=n*n;i++)
		sum+=num[i];
	if(sum<=k)
	{
		cout<<k-sum<<'\n';
		return 0;
	}
	if(k==1)
	{
		puts("1");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int l=1;l<=n;l++)
			for(int j=1;j<=n;j++)
				f[l][j]=0;
		for(int l=1;l<=n*n;l++)
			if(num[l]&&mn1[l]+i-1>=mx1[l]&&mn2[l]+i-1>=mx2[l])
				add(mx1[l]-i+1,mx2[l]-i+1,mn1[l],mn2[l]);
		for(int l=1;l<=n-i+1;l++)
			for(int j=1;j<=n-i+1;j++)
			{
				f[l][j]+=f[l-1][j]+f[l][j-1]-f[l-1][j-1];
				if(sum-f[l][j]==k||sum-f[l][j]==k-1)
				{
					puts("1");
					return 0;
				}
			}
	}
	puts("2");
	return 0;
}