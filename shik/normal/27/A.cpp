// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n,x,app[3010]={};
	scanf("%d",&n);
	while ( n-- ) {
		scanf("%d",&x);
		app[x]=1;
	}
	for ( int i=1; i<3010; i++ )
		if ( !app[i] ) {
			printf("%d\n",i);
			return 0;
		}
	return 0;
}