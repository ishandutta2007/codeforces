// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n,a[110],i,c[2]={},x[2]={};
	scanf("%d",&n);
	for ( i=1; i<=n; i++ ) scanf("%d",a+i);
	for ( i=1; i<=n; i++ ) {
		c[a[i]%2]++;
		x[a[i]%2]=i;
	}
	printf("%d\n",x[c[1]==1]);
	return 0;
}