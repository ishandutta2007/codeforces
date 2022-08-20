#include<bits/stdc++.h>

using namespace std;

const int maxn=1010;

int n,m,ans;

int mp[maxn][maxn];

bool r[maxn][maxn],l[maxn][maxn],u[maxn][maxn],d[maxn][maxn];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&mp[i][j]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			l[i][j]=l[i][j-1]|mp[i][j];
		for(int j=m;j;j--)
			r[i][j]=r[i][j+1]|mp[i][j];
		for(int j=1;j<=m;j++)
		if(!mp[i][j])
			ans+=l[i][j]+r[i][j];
	}
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=n;i++)
			u[i][j]=u[i-1][j]|mp[i][j];
		for(int i=n;i;i--)
			d[i][j]=d[i+1][j]|mp[i][j];
		for(int i=1;i<=n;i++)
		if(!mp[i][j])
			ans+=u[i][j]+d[i][j];
	}
	cout<<ans<<endl;
}