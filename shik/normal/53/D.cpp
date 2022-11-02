// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int sol[1000000],sn;
int main()
{
	int n,a[310],b[310];
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) scanf("%d",a+i);
	for ( int i=0; i<n; i++ ) scanf("%d",b+i);
	for ( int i=0; i<n; i++ ) {
		int p=find(b+i,b+n,a[i])-b;
		while ( p!=i ) {
			sol[sn++]=--p;
			swap(b[p],b[p+1]);
		}
	}
	printf("%d\n",sn);
	for ( int i=0; i<sn; i++ ) printf("%d %d\n",sol[i]+1,sol[i]+2);
	return 0;
}