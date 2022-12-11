#include<cstdio>
using namespace std;

const int Maxn=1000+19;
int n,k,l,r,sa,sk,ta,tk,Ma=1,Mi;
int A[Maxn];

int main()
{
	scanf("%d%d%d%d%d%d",&n,&k,&l,&r,&sa,&sk);sa-=sk;n-=k;
	for (int i=1;i<=k-sk%k;i++) printf("%d ",sk/k);
	for (int i=1;i<=sk%k;i++) printf("%d ",sk/k+1);
	if (n)
	{
		for (int i=1;i<=n-sa%n;i++) printf("%d ",sa/n);
		for (int i=1;i<=sa%n;i++) printf("%d ",sa/n+1);
	}
	puts("");
}