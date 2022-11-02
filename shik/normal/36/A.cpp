// by shik
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,i,d,pre,s[200];
	scanf("%d",&n);
	for ( i=0; i<n; i++ ) scanf("%1d",s+i);
	for ( i=0; s[i]==0; i++ );
	pre=i;
	for ( i++; s[i]==0; i++ );
	d=i-pre;
	pre=i;
	for ( i++; i<n; i++ )
		if ( s[i]==1 ) {
			if ( i-pre!=d ) { puts("NO"); return 0; }
			pre=i;
		}
	puts("YES");
	return 0;
}