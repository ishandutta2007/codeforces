// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[100010];
int main()
{
	int n;
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) scanf("%d",a+i);
	sort(a,a+n);
	n=unique(a,a+n)-a;
	for ( int i=0; i<n-1; i++ )
		if ( a[i+1]<a[i]*2 ) { puts("YES"); return 0; }
	puts("NO");
	return 0;
}