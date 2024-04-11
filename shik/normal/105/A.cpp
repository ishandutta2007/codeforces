// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
map<string,int> tbl;
int main()
{
	int n,m; double k;
	scanf("%d%d%lf",&n,&m,&k);
	char s[100]; int lv;
	while ( n-- ) {
		scanf("%s %d",s,&lv);
		lv=(int)(k*lv+1e-9);
		if ( lv>=100 ) tbl[s]=lv;
	}
	while ( m-- ) {
		scanf("%s",s);
		if ( tbl.find(s)==tbl.end() ) tbl[s]=0;
	}
	printf("%d\n",(int)tbl.size());
	FOR(it,tbl) printf("%s %d\n",(it->first).c_str(),it->second);
	return 0;
}