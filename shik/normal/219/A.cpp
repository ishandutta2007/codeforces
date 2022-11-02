// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	char s[1010];
	int k,c[26]={};
	scanf("%d%s",&k,s);
	for ( int i=0; s[i]; i++ ) c[s[i]-'a']++;
	for ( int i=0; i<26; i++ ) if ( c[i]%k!=0 ) return puts("-1"),0;
	for ( int i=0; i<26; i++ ) c[i]/=k;
	for ( int i=0; i<k; i++ ) for ( int j=0; j<26; j++ ) for ( int t=0; t<c[j]; t++ ) putchar(j+'a');
	puts("");
	return 0;
}