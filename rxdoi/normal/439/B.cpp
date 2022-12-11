#include<cstdio>
#include<algorithm>
using namespace std;

const int Maxn=100000+19;
typedef long long LL;
LL A[Maxn],x,Ans;
int n;

int main()
{
	scanf("%d%I64d",&n,&x);
	for (int i=1;i<=n;i++) scanf("%I64d",&A[i]);
	sort(A+1,A+n+1);
	for (int i=1;i<=n;i++)
	{
		Ans+=1LL*x*A[i];
		x=max(x-1LL,1LL);
	}
	printf("%I64d\n",Ans);
}