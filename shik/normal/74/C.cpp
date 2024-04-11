// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n,m,i;
	scanf("%d%d",&n,&m);
	for ( i=min(n,m); (n-i)%(i-1)!=0 || (m-i)%(i-1)!=0; i-- );
	printf("%d\n",i);
	return 0;
}