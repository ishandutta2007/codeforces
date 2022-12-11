#include<cstdio>
using namespace std;

const int Maxn=1e6+19;
int A[Maxn],x,n,Q,y;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		for (int j=y+1;j<=y+x;j++) A[j]=i;
		y+=x;
	}
	scanf("%d",&Q);
	while (Q--)
	{
		scanf("%d",&x);
		printf("%d\n",A[x]);
	}
}