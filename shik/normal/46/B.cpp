// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int r[5];
bool valid( int x ) { return x>=0&&x<5&&r[x]>0; }
int main()
{
	char tbl[5][10]={"S","M","L","XL","XXL"};
	for ( int i=0; i<5; i++ ) scanf("%d",r+i);
	int n,x;
	char s[10];
	scanf("%d",&n);
	while ( n-- ) {
		scanf("%s",s);
		x=-1;
		for ( int i=0; i<5; i++ )
			if ( strcmp(s,tbl[i])==0 ) x=i;
		if ( x==-1 ) puts("QQ");
		for ( int i=0; i<5; i++ ) {
			if ( valid(x+i) ) {
				r[x+i]--;
				puts(tbl[x+i]);
				break;
			} else if ( valid(x-i) ) {
				r[x-i]--;
				puts(tbl[x-i]);
				break;
			}
		}
	}
	return 0;
}