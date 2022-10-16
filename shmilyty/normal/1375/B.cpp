#include<bits/stdc++.h>
using namespace std;
int t,n,m,a[301][301],b[301][301];
void INIT()
{
	memset(b,0,sizeof(b));
	b[1][1]=b[1][m]=b[n][1]=b[n][m]=2;
	for(int i=2;i<m;i++)
		b[1][i]=b[n][i]=3;
	for(int i=2;i<n;i++)
		b[i][1]=b[i][m]=3;
	for(int i=2;i<n;i++)
		for(int l=2;l<m;l++)
			b[i][l]=4;
}
void solve()
{
	for(int i=1;i<=n;i++)
		for(int l=1;l<=m;l++)
			if(a[i][l]>b[i][l])
			{
				puts("NO");
				return ;
			}
	puts("YES");
	for(int i=1;i<=n;i++)
	{
		for(int l=1;l<=m;l++)
			cout<<b[i][l]<<" ";
		cout<<endl;
	}
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		INIT();
		for(int i=1;i<=n;i++)
			for(int l=1;l<=m;l++)
				scanf("%d",&a[i][l]);
		solve();
	}
	return 0;
}