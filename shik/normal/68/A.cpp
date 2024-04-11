// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int p[4],a,b,i,cnt[32000]={},ans=0;
	scanf("%d%d%d%d%d%d",p,p+1,p+2,p+3,&a,&b);
	sort(p,p+4);
	do {
		for ( i=a; i<=b; i++ )
			if ( i%p[0]%p[1]%p[2]%p[3]==i ) cnt[i]++;
	} while ( next_permutation(p,p+4) );
	for ( i=a; i<=b; i++ )
		if ( cnt[i]>=7 ) ans++;
	printf("%d\n",ans);
	return 0;
}