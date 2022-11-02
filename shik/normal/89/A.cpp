// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 10010
using namespace std;
int s[N];
int main()
{
	int n,m,k,i,ans=0,t,tmt;
	scanf("%d%d%d",&n,&m,&k);
	swap(m,k);
	for ( i=1; i<=n; i++ ) scanf("%d",s+i);
	if ( n%2==0 || k<(n-1)/2+1 ) {
		puts("0");
		return 0;
	}
	tmt=s[1];
	for ( i=1; i<=n; i+=2 ) tmt=min(tmt,s[i]);
	while ( m-- && tmt>0 ) {
		t=k;
		while ( t>=(n-1)/2+1 && tmt>0 ) {
			t-=(n-1)/2+1;
			tmt--;
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}