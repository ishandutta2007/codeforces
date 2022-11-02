#include<cstdio>

using namespace std;

int n,m,k,b[601][601],xx,yy,s,bo,now;
char a[601][601];

char getnext()
{
	char ch=getchar();
	while(ch!='#'&&ch!='.')ch=getchar();
	return ch;
}

void ss(int x,int y)
{
	if(b[x][y])return;
	b[x][y]=1;
	if(bo&&a[x][y]=='.')a[x][y]='X';
	if(a[x][y]=='.')now++;
	if(now==s-k)bo=1;
	if(a[x+1][y]=='.')ss(x+1,y);
	if(a[x-1][y]=='.')ss(x-1,y);
	if(a[x][y+1]=='.')ss(x,y+1);
	if(a[x][y-1]=='.')ss(x,y-1);
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			a[i][j]=getnext();
			if(a[i][j]=='.')s++;
		}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			if(a[i][j]=='.')
			{
				xx=i,yy=j;
				break;
			}
		if(xx!=0)break;
	}
	ss(xx,yy);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			putchar(a[i][j]);
		putchar('\n');
	}
}