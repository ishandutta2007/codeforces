// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 110
using namespace std;
int r[N];
int main()
{
	int n,k,i,j,ans=0;
	scanf("%d%d",&n,&k);
	for ( i=0; i<n; i++ ) scanf("%d",r+i);
	while ( r[0]<k ) {
		ans++;
		for ( j=0; j<n; j++ ) {
			if ( r[j]<k && r[j]!=r[j+1] ) {
				r[j]++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}