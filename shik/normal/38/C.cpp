// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n,l,a[110],ans=0;
	scanf("%d%d",&n,&l);
	for ( int i=0; i<n; i++ ) scanf("%d",a+i);
	for ( int i=l; i<=100; i++ ) {
		int cnt=0;
		for ( int j=0; j<n; j++ ) cnt+=a[j]/i;
		ans=max(ans,cnt*i);
	}
	printf("%d\n",ans);
	return 0;
}