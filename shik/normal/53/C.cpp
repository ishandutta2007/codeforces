// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n,x[2];
	scanf("%d",&n); x[0]=1; x[1]=n;
	for ( int i=0; i<n; i++ ) {
		printf("%d%c",x[i&1],i==n-1?'\n':' ');
		if ( i&1 ) x[i&1]--;
		else x[i&1]++;
	}
	return 0;
}