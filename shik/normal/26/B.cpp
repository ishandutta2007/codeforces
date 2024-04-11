// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1000010
using namespace std;
char s[N];
int main()
{
	gets(s);
	int cnt=0,ans=0;
	for ( int i=0; s[i]; i++ ) {
		char c=s[i];
		if ( c=='(' ) cnt++;
		else if ( c==')' && cnt>0 ) cnt--,ans+=2;
	}
	printf("%d\n",ans);
	return 0;
}