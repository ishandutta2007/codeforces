// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int sx,sy,ex,ey;
	char ch;
	scanf(" %c%d",&ch,&sy); sx=ch-'a'+1;
	scanf(" %c%d",&ch,&ey); ex=ch-'a'+1;
	printf("%d\n",max(abs(sx-ex),abs(sy-ey)));
	while ( sx!=ex || sy!=ey ) {
		if ( sx<ex ) {
			putchar('R');
			sx++;
		} else if ( sx>ex ) {
			putchar('L');
			sx--;
		}
		if ( sy<ey ) {
			putchar('U');
			sy++;
		} else if ( sy>ey ) {
			putchar('D');
			sy--;
		}
		puts("");
	}
	return 0;
}