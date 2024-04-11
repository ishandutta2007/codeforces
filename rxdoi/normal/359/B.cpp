#include<cstdio>
#include<algorithm>
using namespace std;

int n,k;
int A[50000*2+19];

int main()
{
	scanf("%d%d",&n,&k);n*=2;
	for (int i=1;i<=n;i++) A[i]=i;
	for (int i=1;i<=n;i+=2) if (k) k--,swap(A[i],A[i+1]);
	for (int i=1;i<=n;i++) printf("%d ",A[i]);printf("\n");
}