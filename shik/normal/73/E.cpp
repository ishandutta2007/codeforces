// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
#define S 2000010
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int a[N],p[S],ps[S]={2},pk=1;
void predo() {
	for ( int i=3; i*i<S; i+=2 ) if ( !p[i] ) for ( int j=i*i; j<S; j+=i+i ) p[j]=1;
	for ( int i=3; i<S; i+=2 ) if ( !p[i] ) ps[pk++]=i;
}
int main()
{
	predo();
	int n,x,t=0,ans=0;
	scanf("%d%d",&n,&x);
	for ( int i=0; i<n; i++ ) scanf("%d",a+i);
	if ( x==2 ) {
		puts("0");
		return 0;
	}
	sort(a,a+n);
	if ( a[0]==1 ) {
		puts("1");
		return 0;
	}
	for ( int i=0; i<n&&ps[t]<x; i++ )
		if ( a[i]==ps[t] ) {
			t++;
			ans++;
		}
	if ( ps[t]<x ) puts("-1");
	else printf("%d\n",ans);
	return 0;
}