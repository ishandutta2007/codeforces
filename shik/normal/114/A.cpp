// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	while ( m%n==0 ) {
		m/=n;
		ans++;
	}
	if ( m!=1 ) puts("NO");
	else printf("YES\n%d\n",ans-1);
	return 0;
}