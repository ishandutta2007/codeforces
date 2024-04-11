#include <cstdio>
#include <algorithm>
using namespace std;
const int N=105;
int n,m;
int v[N][N];
int id[N][N],pid[N];
int p[N],delta[N],cur;
int ans;
bool cmp(int a,int b)
{
	return delta[a]<delta[b];
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			scanf("%d",&v[i][j]);
	for (int i=1;i<n;i++)
	{
		cur=0;
		for (int j=1;j<=m;j++)
		{
			p[j]=j;
			delta[j]=v[j][n]-v[j][i];
			cur+=delta[j];
		}
		sort(p+1,p+m+1,cmp);
		for (int j=m;j;j--)
		{
			if (cur<=0)
				break;
			cur-=delta[p[j]];
			id[i][++pid[i]]=p[j];
		}
	}
	ans=m;
	for (int i=1;i<n;i++)
		if (pid[i]<ans)
			ans=pid[i];
	printf("%d\n",ans);
	for (int i=1;i<n;i++)
		if (pid[i]==ans)
		{
			for (int j=1;j<=pid[i];j++)
				printf("%d%c",id[i][j]," \n"[j==pid[i]]);
			break;
		}
	return 0;
}