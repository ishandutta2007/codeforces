#include<cstdio>
using namespace std;

const int Maxn=2e5+19;
int A[Maxn],n,k,tmp;

int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	for (int i=1;i<=n;i++) A[i+n]=A[i+k-1];
	for (int i=n+1;i<=2*n;i++)
		if (!tmp) tmp=A[i];
			else if (A[i]!=tmp) {puts("-1");return 0;}
	for (int i=n;i>=0;i--)
		if (A[i]==tmp) ;else {printf("%d\n",i);return 0;}
}