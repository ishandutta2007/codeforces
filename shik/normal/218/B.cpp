// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n1,n2,m,a[1010],b[1010];
	scanf("%d%d",&n1,&m); n2=n1;
	for ( int i=0; i<m; i++ ) scanf("%d",a+i);
	for ( int i=0; i<m; i++ ) b[i]=a[i];
	int s1=0,s2=0;
	while ( n1-- ) {
		sort(a,a+m);
		s1+=a[m-1];
		a[m-1]--;
	}
	while ( n2-- ) {
		sort(b,b+m);
		for ( int i=0; i<m; i++ ) if ( b[i]>0 ) {
			s2+=b[i];
			b[i]--;
			break;
		}
	}
	printf("%d %d\n",s1,s2);
	return 0;
}