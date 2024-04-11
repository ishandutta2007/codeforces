#include<cstdio>
#include<algorithm>
using namespace std;

const int Maxn=1000+19;
int Map[Maxn][Maxn],A[Maxn],del,n,U,D,x,y,tmp;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) 
	{
		scanf("%d",&A[i]);
		(i&1)?x+=A[i]:x-=A[i];
		U=max(U,x);D=min(D,x);
	}
	del=U-D;x=del-U+1;
	for (int i=1;i<=n;i++)
	{
		if (i&1)
			for (int j=1;j<=A[i];j++)
			{
				Map[del-(x++)+1][++y]=1;
			}
		else
			for (int j=1;j<=A[i];j++)
			{
				Map[del-(--x)+1][++y]=2;
			}
	}
	for (int i=1;i<=del;i++,puts(""))
		for (int j=1;j<=y;j++) printf("%c",Map[i][j]==2?'\\':(Map[i][j]==1?'/':' '));
}