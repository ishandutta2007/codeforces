#include<cstdio>
#include<algorithm>
using namespace std;

int now,x,Ans,n;
int A[100+19];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]),A[i]+=A[i-1];
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++)
			Ans=max(Ans,A[n]-A[j]+A[i-1]+(j-i+1)-(A[j]-A[i-1]));
	printf("%d\n",Ans);
}