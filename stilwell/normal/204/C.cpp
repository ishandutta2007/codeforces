#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,i,j,k;
char A[200005],B[200005];
long long suml[1005],sumr[1005],tmp;
double ans;

int main()
{
	scanf("%d",&n);
	scanf("%s",A+1);
	scanf("%s",B+1);
	for(i=1;i<=n;++i)sumr[B[i]]+=n-i+1;
	for(i=1;i<=n;++i)tmp+=(long long)(n-i+1)*(n-i+1);
	for(i=1;i<=n;++i)
	{
		ans+=(suml[A[i]]*(n-i+1)+sumr[A[i]]*i)*1.0/tmp;
		sumr[B[i]]-=n-i+1;
		suml[B[i]]+=i;
	}
	printf("%.9lf\n",ans);
}