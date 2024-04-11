// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n,a;
	long long ans=0;
	scanf("%d",&n);
	for ( int i=1; i<=n; i++ ) {
		scanf("%d",&a);
		ans+=1LL*i*(a-1)+1;
	}
	printf("%I64d\n",ans);
	return 0;
}