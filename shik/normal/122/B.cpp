// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	char s[100];
	gets(s);
	int cnt[10]={};
	for ( int i=0; s[i]; i++ ) cnt[s[i]-'0']++;
	if ( cnt[4]==0 && cnt[7]==0 ) puts("-1");
	else if ( cnt[4]>=cnt[7] ) puts("4");
	else puts("7");
	return 0;
}