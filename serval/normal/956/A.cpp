#include <cstdio>
using namespace std;
int n,m,i,j;
char mp[105][105];
long long r[105],chosen[105];
int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
		{
			scanf("%c",&mp[i][j]);
			while (mp[i][j]!='#'&&mp[i][j]!='.')
				scanf("%c",&mp[i][j]);
			r[i]=(r[i]<<1)|(mp[i][j]=='#');
		}
	for (i=1;i<=m;i++)
	{
		chosen[i]=0;
		for (j=1;j<=n;j++)
			if (r[j]&(1ll<<(i-1)))
				if (chosen[i]==0)
					chosen[i]=r[j];
				else
					if (r[j]!=chosen[i])
					{
						printf("No\n");
						return 0;
					}
	}
	printf("Yes\n");
	return 0;
}