// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n,l[5010],r[5010],c[5010]={},s[5010],m=0;
	scanf("%d",&n);
	for ( int i=1; i<=n; i++ ) {
		scanf("%d%d",l+i,r+i);
		r[i]--;
	}
	int cnt=0;
	for ( int i=1; i<=n; i++ ) for ( int j=i+1; j<=n; j++ ) if ( !(r[i]<l[j]||l[i]>r[j]) ) cnt++,c[i]++,c[j]++;
	for ( int i=1; i<=n; i++ ) if ( c[i]==cnt ) s[m++]=i;
	printf("%d\n",m);
	for ( int i=0; i<m; i++ ) printf("%d%c",s[i],i==m-1?'\n':' ');
	return 0;
}