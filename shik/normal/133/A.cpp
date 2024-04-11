// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	char s[110];
	gets(s);
	puts(strchr(s,'H')||strchr(s,'Q')||strchr(s,'9')?"YES":"NO");
	return 0;
}