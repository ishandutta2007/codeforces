// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n,m,p=1;
	scanf("%d%d",&n,&m);
	while ( m>=p ) {
		m-=p;
		p++;
		if ( p==n+1 ) p=1;
	}
	printf("%d\n",m);
	return 0;
}