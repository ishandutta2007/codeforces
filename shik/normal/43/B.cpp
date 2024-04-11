// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 210
using namespace std;
int main()
{
	char s[N],t[N];
	int cnt[130]={};
	gets(s); gets(t);
	for ( int i=0; s[i]; i++ ) cnt[(int)s[i]]++;
	for ( int i=0; t[i]; i++ ) cnt[(int)t[i]]--;
	for ( int i=0; i<130; i++ )
		if ( i!=' ' && cnt[i]<0 ) {
			puts("NO");
			return 0;
		}
	puts("YES");
	return 0;
}