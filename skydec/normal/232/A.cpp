#include<stdio.h>
using namespace std;
#define C2(x) ((x)*((x)-1)/2)
#define C3(x) ((x)*((x)-1)*((x)-2)/6)
int n,k;
bool f[105][105];
int main()
{
	scanf("%d",&k);
	int u=2;
	while(C3(u+1)<=k)u++;k-=C3(u);int limit=u;
	for(int i=1;i<=u;i++)
	for(int j=1;j<=u;j++)
	if(i!=j)
	f[i][j]=1;int p=u;
	if(k)
	for(p=u+1;p<=100;p++)
	{
		if(k==0)break;
		int w=1;
		while(C2(w+1)<=k&&w<u)w++;
		k-=C2(w);
		for(int s=1;s<=w;s++)
		f[s][p]=f[p][s]=1;
	}
	printf("%d\n",p);
	for(int i=1;i<=p;i++)
	{
		for(int j=1;j<=p;j++)printf("%d",f[i][j]);
		printf("\n");
	}
	return 0;
}