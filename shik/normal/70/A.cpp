// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n,x=1;
	scanf("%d",&n);
	for ( int i=1; i<n; i++ ) x=x*3%1000003;
	printf("%d\n",x);
	return 0;
}