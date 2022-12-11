#include<cstdio>
using namespace std;

const int Maxn=1000+19;
int n,d,k;
int A[Maxn][Maxn];

int main()
{
	scanf("%d%d%d",&n,&k,&d);
	int Flag=0,tmp=1;
	for (int i=1;i<=d;i++) 
	{
		tmp*=k;
		if (tmp>=n) {Flag=1;break;}
	}
	if (!Flag) {printf("-1\n");return 0;}
	for (int i=1;i<=d;i++) A[i][1]=1;
	for (int i=2;i<=n;i++)
	{
		for (int j=1;j<=d;j++) A[j][i]=A[j][i-1];
		int j=d;
		while (A[j][i]==k) j--;
		A[j][i]++;
		for (int k=j+1;k<=n;k++) A[k][i]=1;
	}
	for (int i=1;i<=d;i++) 
	{
		for (int j=1;j<=n;j++) printf("%d ",A[i][j]);
		printf("\n");
	}
}