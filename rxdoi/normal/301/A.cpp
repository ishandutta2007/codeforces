#include<cstdio>
#include<algorithm>
using namespace std;

const int Maxn=100+19;
int A[Maxn*2],n,_n,sum;

int main()
{
	scanf("%d",&_n);
	n=_n*2-1;
	for (int i=0;i<n;i++) scanf("%d",&A[i]);
	sort(A,A+n);
	if (_n%2==0)
	{
		int x=0;
		while (x+1<n)
		{
			if (-A[x]-A[x+1]>0) sum+=-A[x]-A[x+1];
				else sum+=A[x]+A[x+1];
			x+=2;
		}
		sum+=A[n-1];
	} else
		for (int i=0;i<n;i++) sum+=abs(A[i]);
	printf("%d\n",sum);
}