#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,k,i,j,p,q,f[1005][1005][13][2];
char s[1005],t[1005];
int main()
{
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (i=1;i<=n;i++)
	{
		while (s[i]==0||s[i]==13||s[i]==10)
			scanf("%c",&s[i]);
	}
	for (i=1;i<=m;i++)
	{
		while (t[i]==0||t[i]==13||t[i]==10)
			scanf("%c",&t[i]);
	}
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			for (p=1;p<=k;p++)
			{
				if (s[i]==t[j])
					f[i][j][p][1]=max(f[i-1][j-1][p][1],f[i-1][j-1][p-1][0])+1;
				f[i][j][p][0]=max(max(f[i-1][j][p][0],f[i][j-1][p][0]),max(f[i-1][j-1][p][0],f[i][j][p][1]));
			}
	/*for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			for (p=0;p<=k;p++)
			{
				printf("i %d  j %d  p %d 0 : %d\n",i,j,p,f[i][j][p][0]);
				printf("i %d  j %d  p %d 1 : %d\n",i,j,p,f[i][j][p][1]);
			}*/
	printf("%d\n",f[n][m][k][0]);
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}