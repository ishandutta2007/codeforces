#include<cstdio>
using namespace std;

const int Maxn=300+19;
int n,m,k,x,y,s;

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	x=y=1;
	for (int i=1;i<k;i++) 
	{
		printf("2 ");
		for (int j=1;j<=2;j++)
		{
			printf("%d %d ",x,y);
			if (x&1) if (y<m) y++;else x++;
			else if (y>1) y--;else x++;
		}
		puts("");
	}
	printf("%d ",n*m-2*(k-1));
	for (int j=1;j<=n*m-2*(k-1);j++)
	{
		printf("%d %d ",x,y);
		if (x&1) if (y<m) y++;else x++;
		else if (y>1) y--;else x++;
	}
	puts("");
}