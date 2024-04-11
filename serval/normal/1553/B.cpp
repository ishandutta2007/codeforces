#include <cstdio>
using namespace std;
const int N=1005;
int T;
char s[N],t[N];
bool p[N][N],r[N][N];
bool solve()
{
	scanf("%s",s+1);
	scanf("%s",t+1);
	int n,m;
	for (n=1;s[n+1];n++);
	for (m=1;t[m+1];m++);
	for (int i=0;i<=n;i++)
		for (int j=0;j<=m;j++)
			p[i][j]=r[i][j]=0;
	for (int i=0;i<n;i++)
	{
		p[i][0]=1;
		for (int j=1;j<=m&&i+j<=n;j++)
			p[i+j][j]=(p[i+j-1][j-1]&&(s[i+j]==t[j]));
	}
	for (int i=0;i<n;i++)
	{
		r[i][0]=1;
		for (int j=1;j<=m&&i+j<=n;j++)
			r[i+j][j]=(r[i+j-1][j-1]&&(s[i+j]==t[m-j+1]));
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (p[i][j]&&r[i][m-j+1])
				return 1;
	return 0;
}
int main()
{
	scanf("%d",&T);
	while (T--)
		if (solve())
			printf("YES\n");
		else
			printf("NO\n");
	return 0;
}