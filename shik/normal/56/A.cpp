// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <string>
using namespace std;
char lst[11][100]={"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};
set<string> tbl;
int main()
{
	for ( int i=0; i<11; i++ ) tbl.insert(lst[i]);
	int n,ans=0,x;
	char s[100];
	scanf("%d",&n);
	while ( n-- ) {
		scanf("%s",s);
		if ( s[0]>='0' && s[0]<='9' ) {
			sscanf(s,"%d",&x);
			if ( x<18 ) ans++;
		} else if ( tbl.find(s)!=tbl.end() ) ans++;
	}
	printf("%d\n",ans);
	return 0;
}