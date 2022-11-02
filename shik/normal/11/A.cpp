// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 2010
using namespace std;
int b[N];
int main()
{
	int n,d,i,ans=0;
	scanf("%d%d",&n,&d);
	for ( i=0; i<n; i++ ) scanf("%d",b+i);
	for ( i=1; i<n; i++ ) {
		if ( b[i]>b[i-1] ) continue;
		int r=(b[i-1]-b[i]+d)/d;
		ans+=r;
		b[i]+=r*d;
	}
	printf("%d\n",ans);
	return 0;
}