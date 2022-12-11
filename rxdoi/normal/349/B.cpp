#include<cstdio>
using namespace std;

const int M=1e6+19,N=10;
int w[N],F[M],Dis[M],num[M],v,Flag=1;

int main()
{
	scanf("%d",&v);
	for (int i=1;i<N;i++) 
	{
		scanf("%d",&w[i]);
		if (w[i]<=v) Flag=0;
	}
	if (Flag) {printf("-1\n");return 0;}
	for (int i=1;i<N;i++)
		for (int j=w[i];j<=v;j++)
			if (F[j]<=F[j-w[i]]+1)
			{
				F[j]=F[j-w[i]]+1;
				Dis[j]=j-w[i];num[j]=i;
			}
	for (int i=v;num[i];i=Dis[i]) 
		printf("%d",num[i]);
}