#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long LL;
LL L,R,k,n,m;

int main()
{
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	L=0;R=1LL*n*m;
	while (L<R)
	{
		LL Mid=(L+R)>>1,cnt=0;
		for (int i=1;i<=n;i++) cnt+=min(m,Mid/i);
		if (cnt<k) L=Mid+1;else R=Mid;
	}
	printf("%I64d\n",R);
}