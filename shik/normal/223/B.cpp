// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 200010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
char s[N],t[N];
int lp[N],rp[N],sc[26][N];
int main()
{
	int n=strlen(gets(s+1));
	int m=strlen(gets(t+1));
	lp[0]=0;
	for ( int i=1; i<=n; i++ ) {
		lp[i]=lp[i-1];
		if ( lp[i]<m && s[i]==t[lp[i]+1] ) lp[i]++;
	}
	rp[n+1]=m+1;
	for ( int i=n; i>=1; i-- ) {
		rp[i]=rp[i+1];
		if ( rp[i]>1 && s[i]==t[rp[i]-1] ) rp[i]--;
	}
	for ( int i=0; i<26; i++ ) for ( int j=1; j<=m; j++ ) sc[i][j]=sc[i][j-1]+(t[j]-'a'==i);
	for ( int i=1; i<=n; i++ ) {
		int c=s[i]-'a',l=rp[i+1]-1,r=lp[i-1]+1;
		if ( l<1 ) l=1;
		if ( r>m ) r=m;
		if ( l>r || sc[c][r]-sc[c][l-1]<=0 ) return puts("NO"),0;
	}
	puts("YES");
	return 0;
}