// by shik
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int t,n;
	scanf("%d",&t);
	while ( t-- ) {
		scanf("%d",&n);
		printf("%d\n",max(n-2,0));	
	}
	return 0;
}