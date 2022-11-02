// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
map<string,int> tbl;
int main()
{
	char s[8][20],t[20];
	for ( int i=0; i<8; i++ ) scanf("%10s",s[i]);
	for ( int i=0; i<10; i++ ) {
		scanf("%s",t);
		tbl[t]=i;
	}
	for ( int i=0; i<8; i++ ) printf("%d",tbl[s[i]]);
	puts("");
	return 0;
}