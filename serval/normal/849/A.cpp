#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 105
int a[maxn];
bool f[2][maxn][maxn];
int n,i,j,k;
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
	f[1][1][1]=1;
	for (i=1;i<=n;i++)
	{
		memset(f[i&1^1],0,sizeof(f[i&1^1]));
		for (j=1;j<=i;j++)
			for (k=1;k<=i;k++)
				if (f[i&1][j][k])
				{
					if (k&1)
						if (a[i]&1)
							if (a[i-k+1]&1)
								f[i&1^1][j+1][1]=1;
					f[i&1^1][j][k+1]=1;
				}
	}
	for (j=1;j<=n+1;j++)
		if (f[n&1^1][j][1]&&(j&1^1))
		{
			printf("Yes\n");
			return 0;
		}
	printf("No\n");
	return 0;
}