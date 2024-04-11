#include<cstdio>
using namespace std;

const int Maxn=100+19;
int A[Maxn<<2],n,k;

int main()
{
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++) A[i]=1;
	A[n-1]=k-(n-1);
	for (int i=n;i<n+n;i++) A[i]=A[i-n];
	for (int i=0;i<n;i++)
	{
		for (int j=i;j<i+n;j++) printf("%d ",A[j]);
		printf("\n");
	}
}