// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
char s[100010],t[100010];
int need[130],rem,cnt,ans;
int main()
{
	scanf("%s %s",s,t);
	int n=strlen(t);
	for ( int i=0; i<n; i++ ) need[(int)t[i]]++;
	rem=n;
	for ( int i=0; s[i]; i++ ) {
		if ( s[i]=='?' ) cnt++;
		else if ( need[(int)s[i]]-->0 ) rem--;
		if ( i>=n ) {
			if ( s[i-n]=='?' ) cnt--;
			else if ( ++need[(int)s[i-n]]>0 ) rem++;
		}
		if ( cnt>=rem ) ans++;
	}
	printf("%d\n",ans);
	return 0;
}