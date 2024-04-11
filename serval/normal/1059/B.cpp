#include <cstdio>
using namespace std;
const int N=1050;
int n,m,i,j,x,y;
bool c[N][N];
char s[N][N];
bool f;
int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for (i=1;i<=n-2;i++)
		for (j=1;j<=m-2;j++)
		{
			f=1;
			for (x=0;x<3;x++)
				for (y=0;y<3;y++)
					if (x!=1||y!=1)
						if (s[i+x][j+y]=='.')
							f=0;
			if (f==0)
				continue;
			for (x=0;x<3;x++)
				for (y=0;y<3;y++)
					if (x!=1||y!=1)
						c[i+x][j+y]=1;
		}
	f=1;
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			if (s[i][j]=='#'&&c[i][j]==0)
				f=0;
	if (f)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}