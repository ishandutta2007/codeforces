#include<cstdio>
#include<algorithm>
using namespace std;

const int Maxn=1e5+19;
typedef long long LL;
LL Ans,A[Maxn];
int n;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%I64d",&A[i]),Ans=max(Ans,A[i]);
	printf("%I64d\n",Ans);
}