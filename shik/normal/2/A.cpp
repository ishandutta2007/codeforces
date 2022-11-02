// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>
#define N 1010
using namespace std;
char name[N][40];
int sc[N];
map<string,int> tbl,tmt;
int main()
{
	int n,i,big=0;
	scanf("%d",&n);
	for ( i=0; i<n; i++ ) scanf("%s%d",name[i],sc+i);
	for ( i=0; i<n; i++ ) tbl[name[i]]+=sc[i];
	for ( map<string,int>::iterator it=tbl.begin(); it!=tbl.end(); it++ ) big=max(big,it->second);
	for ( i=0; i<n; i++ ) {
		tmt[name[i]]+=sc[i];
		if ( tbl[name[i]]==big && tmt[name[i]]>=big ) {
			puts(name[i]);
			break;
		}
	}
	return 0;
}