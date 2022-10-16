#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
long long a[111][111],b[111][111];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>a[i][j];
				a[i][j]-=(i+j-2);
			}
		}
		for(int i=2;i<=n;i++)b[i][0]=1e18;
		for(int j=2;j<=m;j++)b[0][j]=1e18;
		long long ans=1e18;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
//				cerr<<i<<' '<<j<<' '<<a[i][j]<<endl;
				for(int x=1;x<=n;x++)
				{
					for(int y=1;y<=m;y++)
					{
						if(a[x][y]<a[i][j])b[x][y]=1e18;
						else b[x][y]=min(b[x-1][y],b[x][y-1])+a[x][y]-a[i][j];
//						cerr<<x<<' '<<y<<' '<<abs(a[x][y]-a[i][j])<<' '<<b[x][y]<<endl;
					}
				}
//				cerr<<i<<' '<<j<<' '<<ok<<' '<<b[n][m]<<endl;
				ans=min(ans,b[n][m]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}