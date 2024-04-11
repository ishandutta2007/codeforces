#include<cstdio>
#include<algorithm>
using namespace std;

const int Maxn=2e5+19;
int A[Maxn],n,cnt_Min,cnt_Max;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	sort(A+1,A+n+1);
	printf("%d ",A[n]-A[1]);
	for (int i=1;i<=n;i++) cnt_Min+=(A[i]==A[1]);
	for (int i=1;i<=n;i++) cnt_Max+=(A[i]==A[n]);
	printf("%I64d\n",A[1]==A[n]?(1LL*cnt_Min*(cnt_Min-1)/2LL):1LL*cnt_Min*cnt_Max);
}