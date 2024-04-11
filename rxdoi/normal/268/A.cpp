#include<cstdio>
using namespace std;

const int Maxn=30+19;
int A[Maxn],B[Maxn],n,Ans;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&A[i],&B[i]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (i!=j&&A[i]==B[j]) Ans++;
	printf("%d\n",Ans);
}