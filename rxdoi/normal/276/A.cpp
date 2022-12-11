#include<cstdio>
#include<algorithm>
using namespace std;

int Max=-2147483647,f,t,n,k;

int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d%d",&f,&t),Max=max(Max,f-(t<=k?0:t-k));
	printf("%d\n",Max);
}