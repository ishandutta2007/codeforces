// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m,a[100];
	scanf("%d%d",&n,&m);
	for ( int i=0; i<n; i++ ) scanf("%d",a+i);
	for ( int i=0; i<n; i++ ) a[i]*=n-i;
	sort(a,a+n);
	for ( int i=1; i<n; i++ ) a[i]+=a[i-1];
	for ( int i=0; i<n; i++ ) if ( a[i]>m ) return printf("%d\n",i),0;
	printf("%d\n",n);
	return 0;
}