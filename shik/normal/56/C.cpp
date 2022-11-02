// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
vector<string> stk;
char s[1010];
int ans;
int go( int p ) {
	string my;
	while ( isupper(s[p]) ) my+=s[p++];
	FOR(it,stk) if ( *it==my ) ans++;
	stk.push_back(my);
	while ( s[p]!='.' ) p=go(p+1)+1;
	stk.pop_back();
	return p;
}
int main()
{
	gets(s);
	go(0);
	printf("%d\n",ans);
	return 0;
}