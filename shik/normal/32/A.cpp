// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n,d,h[1010],ans=0;
	scanf("%d%d",&n,&d);
	for ( int i=0; i<n; i++ ) scanf("%d",h+i);
	sort(h,h+n);
	for ( int i=0,j=0; i<n; i++ ) {
		while ( j<n && h[j]-h[i]<=d ) j++;
		ans+=j-i-1;
	}
	printf("%d\n",2*ans);
	return 0;
}