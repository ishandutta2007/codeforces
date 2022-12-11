#include<cstdio>
#include<algorithm>
using namespace std;

const int Maxn=1e5+19;
typedef long long LL;
int n,A[Maxn],Max;
LL L,R;

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&A[i]),Max=max(Max,A[i]);
	L=Max;R=2e9;
	while (L<R)
	{
		LL Mid=(L+R)>>1,tmp=0;
		for (int i=0;i<n;i++) tmp+=Mid-A[i];
		if (tmp<Mid) L=Mid+1;else R=Mid;
	}
	printf("%I64d\n",R);
}