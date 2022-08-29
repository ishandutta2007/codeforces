#include<stdio.h>
using namespace std;
int a,b,x,y;
int ans=0;
int main()
{
	scanf("%d%d%d%d",&x,&y,&a,&b);
	for(int i=a;i<=x;i++)
	for(int j=b;j<i&&j<=y;j++)
	ans++;
	printf("%d\n",ans);
	for(int i=a;i<=x;i++)
	for(int j=b;j<i&&j<=y;j++)
	printf("%d %d\n",i,j);
	return 0;
}