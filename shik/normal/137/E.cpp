// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#define N 200010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
bool vow( char c ) { return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'; }
char s[N];
int a[N],lst[N],nl;
int main()
{
	int n=strlen(gets(s+1)),ans=0,cnt=0;
	for ( int i=1; i<=n; i++ ) a[i]=a[i-1]+(vow(tolower(s[i]))?-1:2);
	lst[nl++]=0;
	for ( int i=1; i<=n; i++ ) {
		if ( a[i]<a[lst[nl-1]] ) lst[nl++]=i;
		else {
			int l=0,r=nl-1;
			while ( l<r ) {
				int m=(l+r)/2;
				if ( a[lst[m]]<=a[i] ) r=m;
				else l=m+1;
			}
			if ( i-lst[l]==ans ) cnt++;
			else if ( i-lst[l]>ans ) {
				ans=i-lst[l];
				cnt=1;
			}
		}
	}
	if ( ans==0 ) puts("No solution");
	else printf("%d %d\n",ans,cnt);
	return 0;
}