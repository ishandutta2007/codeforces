// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int sml[110],val[110];
int main()
{
	int n,m,l,r,t,c;
	scanf("%d%d",&n,&m);
	for ( int i=1; i<=n; i++ ) sml[i]=514514;
	while ( m-- ) {
		scanf("%d%d%d%d",&l,&r,&t,&c);
		for ( int i=l; i<=r; i++ )
			if ( t<sml[i] ) {
				sml[i]=t;
				val[i]=c;
			}
	}
	int ans=0;
	for ( int i=1; i<=n; i++ ) ans+=val[i];
	printf("%d\n",ans);
	return 0;
}