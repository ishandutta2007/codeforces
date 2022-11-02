// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 110
using namespace std;
int num[N];
int main()
{
	int n,i;
	scanf("%d",&n);
	for ( i=0; i<n; i++ ) scanf("%d",num+i);
	sort(num,num+n);
	n=unique(num,num+n)-num;
	if ( n<2 ) puts("NO");
	else printf("%d\n",num[1]);
	return 0;
}