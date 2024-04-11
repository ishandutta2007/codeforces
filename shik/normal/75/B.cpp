// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
map<string,int> tbl;
vector<pair<int,string> > sol;
int val( char *s ) {
	if ( !strcmp(s,"posted") ) return 15;
	if ( !strcmp(s,"commented") ) return 10;
	if ( !strcmp(s,"likes") ) return 5;
	return 0;
}
int main()
{
	char me[100],x[100],op[100],y[100];
	int n;
	scanf("%s %d",me,&n);
	while ( getchar()!='\n' );
	while ( n-- ) {
		scanf("%s %s",x,op);
		if ( strcmp(op,"likes") ) scanf("%*s");
		scanf(" %[^']%*[^\n]",y);
		tbl[x]+=0;
		tbl[y]+=0;
		if ( strcmp(x,me)==0 ) tbl[y]+=val(op);
		if ( strcmp(y,me)==0 ) tbl[x]+=val(op);
	}
	FOR(it,tbl) if ( strcmp((it->first).c_str(),me) ) sol.push_back(make_pair(-it->second,it->first));
	sort(sol.begin(),sol.end());
	FOR(it,sol) puts((it->second).c_str());
	return 0;
}