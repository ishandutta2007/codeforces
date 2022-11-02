// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct P {
	int id,vol;
	void read( int _id ) { id=_id; scanf("%d",&vol); }
} p[1010];
bool operator <( P a, P b ) { return a.vol<b.vol; }
int a[1010];
int main()
{
	int n,sum=0;
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) p[i].read(i+1);
	for ( int i=0; i<n; i++ ) sum+=p[i].vol;
	if ( sum%n!=0 ) { puts("Unrecoverable configuration."); return 0; }
	sum/=n;
	sort(p,p+n);
	for ( int i=0; i<n; i++ ) a[i]=p[i].vol;
	if ( a[0]==a[n-1] && a[0]==sum ) { puts("Exemplary pages."); return 0; }
	if ( n>2 && (a[1]!=sum || a[n-2]!=sum) ) { puts("Unrecoverable configuration."); return 0; }
	printf("%d ml. from cup #%d to cup #%d.\n",(a[n-1]-a[0])/2,p[0].id,p[n-1].id);
	return 0;
}