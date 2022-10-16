#include <cstdio>
#include <cstring>
using namespace std;
int n,m,i,j,k;
int ux[1005],uy[1005];
bool map[1005][1005];
char op;
int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
		{
			op=0;
			while (op!='*'&&op!='.')
				scanf("%c",&op);
			if (op=='*')
			{
				ux[i]++;
				uy[j]++;
				map[i][j]=1;
				k++;
			}
		}
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			if (ux[i]+uy[j]-map[i][j]==k)
			{
				printf("YES\n%d %d\n",i,j);
				return 0;
			}
	if (k==0)
	{
		printf("YES\n1 1\n");
		return 0;
	}
	printf("NO\n");
	return 0;
}