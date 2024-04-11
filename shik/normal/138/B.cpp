// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
char s[N];
int cnt[10],c1[10],c2[10],a[N],b[N],x[N],y[N],ans=-1;
int main()
{
	int n=strlen(gets(s));
	for ( int i=0; i<n; i++ ) cnt[s[i]-'0']++;
	for ( int i=1; i<=5; i++ ) if ( cnt[i] && cnt[10-i] ) {
		memcpy(c1,cnt,sizeof(cnt));
		memcpy(c2,cnt,sizeof(cnt));
		c1[i]--; c2[10-i]--;
		int p=0;
		while ( c1[0]>c2[9] && c2[0]>c1[9] ) {
			c1[0]--; c2[0]--;
			a[p]=b[p]=0; p++;
		}
		a[p]=i; b[p]=10-i; p++;
		for ( int j=0; j<=9; j++ ) while ( c1[j] && c2[9-j] ) {
			c1[j]--; c2[9-j]--;
			a[p]=j; b[p]=9-j; p++;
		}
		for ( int j=0,k=p; j<10; j++ ) while ( c1[j] ) c1[a[k++]=j]--;
		for ( int j=0,k=p; j<10; j++ ) while ( c2[j] ) c2[b[k++]=j]--;
		if ( p>ans ) {
			ans=p;
			memcpy(x,a,sizeof(a));
			memcpy(y,b,sizeof(b));
		}
	}
	if ( ans==-1 ) {
		sort(s,s+n);
		reverse(s,s+n);
		puts(s); puts(s);
		return 0;
	}
	for ( int i=n-1; i>=0; i-- ) printf("%d",x[i]); puts("");
	for ( int i=n-1; i>=0; i-- ) printf("%d",y[i]); puts("");
	return 0;
}