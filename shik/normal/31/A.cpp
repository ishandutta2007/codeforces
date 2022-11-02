// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n,a[110];
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) scanf("%d",a+i);
	for ( int i=0; i<n; i++ )
		for ( int j=0; j<n; j++ )
			for ( int k=0; k<n; k++ )
				if ( i!=j && i!=k && j!=k && a[i]==a[j]+a[k] ) {
					printf("%d %d %d\n",i+1,j+1,k+1);
					return 0;
				}
	puts("-1");
	return 0;
}