#include<cstdio>
#include<algorithm>
using namespace std;

const int Maxn=1000+19;
int A[Maxn],n,L,Max;

int main()
{
	scanf("%d%d",&n,&L);
	for (int i=0;i<n;i++) scanf("%d",&A[i]);
	sort(A,A+n);
	for (int i=1;i<n;i++) Max=max(Max,A[i]-A[i-1]);
	Max=max(Max,max(A[0],L-A[n-1])*2);
	printf("%.10lf\n",Max/2.);
}