// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char tbl[]="6789TJQKA";
int get() {
	char c;
	scanf(" %c",&c);
	for ( int i=0; i<9; i++ )
		if ( c==tbl[i] ) return i;
	puts("QQ");
	return 0;
}
int main()
{
	char king;
	char c1,c2;
	int n1,n2;
	scanf(" %c",&king);
	n1=get(); scanf(" %c",&c1);
	n2=get(); scanf(" %c",&c2);
	if ( c1==c2 && n1>n2 ) puts("YES");
	else if ( c1==king && c2!=king ) puts("YES");
	else puts("NO");
	return 0;
}