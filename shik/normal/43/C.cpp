// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 10010
using namespace std;
int main()
{
	int n,x,c[3]={};
	scanf("%d",&n);
	while ( n-- ) {
		scanf("%d",&x);
		c[x%3]++;
	}
	printf("%d\n",c[0]/2+min(c[1],c[2]));
	return 0;
}