// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
#define N 110
using namespace std;
int main()
{
	int k,n;
	char s[110];
	scanf("%d %s",&k,s);
	n=strlen(s);
	for ( int i=0; i<n; i++ ) {
		if ( s[i]==s[n-i-1] ) continue;
		if ( s[i]=='?' ) s[i]=s[n-i-1];
		else if ( s[n-i-1]=='?' ) s[n-i-1]=s[i];
		else {
			puts("IMPOSSIBLE");
			return 0;
		}
	}
	int app[30]={},ptr=k-1;
	for ( int i=0; i<n; i++ ) if ( s[i]!='?' ) app[s[i]-'a']=1;
	for ( int i=(n-1)/2; i>=0; i-- ) {
		if ( s[i]!='?' ) continue;
		while ( ptr>=0 && app[ptr] ) ptr--;
		if ( ptr<0 ) s[i]=s[n-i-1]='a';
		else {
			s[i]=s[n-i-1]='a'+ptr;
			app[ptr]=1;
			ptr--;
		}
	}
		while ( ptr>=0 && app[ptr] ) ptr--;
	if ( ptr>=0 ) puts("IMPOSSIBLE");
	else puts(s);
	return 0;
}