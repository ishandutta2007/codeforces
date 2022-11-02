// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n,m,L,R,x; char s[10];
	scanf("%d%d",&n,&m);
	L=1; R=n;
	while ( m-- ) {
		scanf(" To the %s of %d",s,&x);
		if ( s[0]=='l' ) {
			R=min(R,x-1);
		} else if ( s[0]=='r' ) {
			L=max(L,x+1);
		} else puts("QQ");
	}
	if ( L>R ) puts("-1");
	else printf("%d\n",R-L+1);
	return 0;
}