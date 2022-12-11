#include<cstdio>
#include<algorithm>
using namespace std;

const int Maxn=3e5+19;
typedef long long LL;
LL A[Maxn],Ans;
int n;

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%I64d",&A[i]);
	sort(A,A+n);
	for (int i=0;i<n-1;i++) Ans+=(A[i]*(i+2));
	Ans+=(A[n-1]*n);
	printf("%I64d\n",Ans);
}