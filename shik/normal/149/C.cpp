// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef pair<int,int> PII;
int n;
PII a[N];
int main()
{
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) scanf("%d",&a[i].first),a[i].second=i;
	sort(a,a+n);
	int x=n/2,y=n-x,sx=0,sy=0,big=a[n-1].first;
	for ( int i=0; i<x; i++ ) sx+=a[i].first;
	for ( int i=x; i<n; i++ ) sy+=a[i].first;
	for ( int i=0; i<x&&abs(sx-sy)>big; i++ ) {
		sx+=a[x+i].first-a[i].first;
		sy+=a[i].first-a[x+i].first;
		swap(a[i],a[x+i]);
	}
	printf("%d\n",x);
	for ( int i=0; i<x; i++ ) printf("%d%c",a[i].second+1,i==x-1?'\n':' ');
	printf("%d\n",y);
	for ( int i=x; i<n; i++ ) printf("%d%c",a[i].second+1,i==n-1?'\n':' ');
	return 0;
}