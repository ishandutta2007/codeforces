// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	char s[110];
	scanf("%d",&t);
	while ( t-- ) {
		scanf("%s",s);
		int L=strlen(s);
		if ( L<=10 ) puts(s);
		else printf("%c%d%c\n",s[0],L-2,s[L-1]);
	}
	return 0;
}