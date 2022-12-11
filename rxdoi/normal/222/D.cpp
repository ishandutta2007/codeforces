#include<cstdio>
#include<algorithm>
#include<functional>
using namespace std;

const int Maxn=1e5+19;
int A[Maxn],B[Maxn];
int n,x,a,t=1;

int main()
{
	scanf("%d%d",&n,&x);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	for (int i=1;i<=n;i++) scanf("%d",&B[i]);
	sort(A+1,A+n+1);
	sort(B+1,B+n+1,greater<int>());
	for (int i=1;i<=n;i++)
		if (A[i]+B[t]>=x) t++;
	printf("1 %d\n",t-1);
}