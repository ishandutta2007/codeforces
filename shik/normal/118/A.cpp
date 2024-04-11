// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	char s[110];
	gets(s);
	for ( int i=0; s[i]; i++ ) if ( !strchr("AOYEUIaoyeui",s[i]) ) printf(".%c",tolower(s[i]));
	return 0;
}