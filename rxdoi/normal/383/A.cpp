#include<cstdio>
using namespace std;

const int Maxn=200000+19;
int A[Maxn],n;
long long Ans,Le;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]),Le+=(A[i]==0);
	for (int i=1;i<=n;i++)
	{
		if (A[i]==1) Ans+=Le;
		if (A[i]==0) Le--;
	}
	printf("%I64d\n",Ans);
}