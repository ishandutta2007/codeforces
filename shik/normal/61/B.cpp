// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cctype>
#include <iostream>
#include <set>
using namespace std;
string pure( string s ) {
	string r;
	for ( int i=0; i<(int)s.size(); i++ )
		if ( isalpha(s[i]) ) r+=tolower(s[i]);
	return r;
}
set<string> sol;
int main()
{
	string a,b,c,s;
	cin>>a>>b>>c;
	a=pure(a);
	b=pure(b);
	c=pure(c);
	sol.insert(a+b+c);
	sol.insert(a+c+b);
	sol.insert(b+a+c);
	sol.insert(b+c+a);
	sol.insert(c+a+b);
	sol.insert(c+b+a);
	int n;
	cin>>n;
	while ( n-- ) {
		cin>>s;
		s=pure(s);
		if ( sol.find(s)!=sol.end() ) puts("ACC");
		else puts("WA");
	}
	return 0;
}