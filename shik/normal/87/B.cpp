// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
map<string,int> tbl;
int cal( char *s ) {
	int ret=0,i;
	for ( i=0; s[i]; i++ )
		if ( s[i]=='&' ) ret--;
		else if ( s[i]=='*' ) ret++;
	return ret;
}
string parse( char *s ) {
	string ret;
	for ( int i=0; s[i]; i++ )
		if ( s[i]!='&' && s[i]!='*' ) ret+=s[i];
	return ret;
}
void output( int x ) {
	if ( x==-1 ) puts("errtype");
	else {
		printf("void");
		while ( x-- ) putchar('*');
		puts("");
	}
}
int get_val( char *s ) {
	string t=parse(s);
	if ( tbl.find(t)==tbl.end() || tbl[t]==-1 || tbl[t]+cal(s)<0 ) return -1;
	return tbl[t]+cal(s);
}
int main()
{
	tbl["void"]=0;
	tbl["errtype"]=-1;
	int n;
	char op[200],a[200],b[200];
	scanf("%d",&n);
	while ( n-- ) {
		scanf("%s %s",op,a);
		int tmt=get_val(a);
		if ( strcmp(op,"typedef")==0 ) {
			scanf("%s",b);
			tbl[b]=tmt;
		} else if ( strcmp(op,"typeof")==0 ) {
			output(tmt);
		} else while(1);
	}
	return 0;
}