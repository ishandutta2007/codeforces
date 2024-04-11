#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
int n,m,x,y;
int main()
{
	scanf("%d%d%d%d",&x,&y,&n,&m);
	if(x==n||y==m)
	{
		printf("%d\n",(abs(x-n)+abs(y-m)+2)*2+2);
		return 0;
	}
	int dis=0;
	for(int i=n-1;i<=n+1;i++)
		for(int j=m-1;j<=m+1;j++)
		{
			if(abs(x-i)+abs(y-j)>dis)
			{
				dis=abs(x-i)+abs(y-j);
			}
		}
	printf("%d\n",dis*2);
	return 0;
}