#include<cstdio>
#include<algorithm>
using namespace std;

const int Maxn=100+19;
int A[Maxn],n;

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&A[i]);
	sort(A,A+n);
	int t=A[0];A[0]=A[n-1];A[n-1]=t;
	for (int i=0;i<n;i++) printf("%d ",A[i]);printf("\n");
	return 0;
}