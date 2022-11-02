// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
char s[5010],*p=s;
vector<int> sol;
void get_table();
void get_td() {
	p+=4;
	if ( strncmp(p,"<table>",7)==0 ) get_table();
	p+=5;
}
int get_tr() {
	int cnt=0;
	p+=4;
	while ( strncmp(p,"<td>",4)==0 ) cnt++,get_td();
	p+=5;
	return cnt;
}
void get_table() {
	int cnt=0;
	p+=7;
	while ( strncmp(p,"<tr>",4)==0 ) cnt+=get_tr();
	p+=8;
	sol.push_back(cnt);
}
int main()
{
	while ( gets(s+strlen(s)) );
	get_table();
	sort(sol.begin(),sol.end());
	for ( int i=0; i<SZ(sol); i++ ) printf("%d%c",sol[i],i==SZ(sol)-1?'\n':' ');
	return 0;
}