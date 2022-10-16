#include <cstdio>
using namespace std;
const int N=505;
int n,m;
int a[N][N],b[N][N];
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			scanf("%d",&b[i][j]);
	for (int i=1;i<=n;i++)
	{
		int cnt=0;
		for (int j=1;j<=m;j++)
			if (a[i][j]!=b[i][j])
				cnt++;
		if (cnt&1)
		{
			printf("No\n");
			return 0;
		}
	}
	for (int j=1;j<=m;j++)
	{
		int cnt=0;
		for (int i=1;i<=n;i++)
			if (a[i][j]!=b[i][j])
				cnt++;
		if (cnt&1)
		{
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}