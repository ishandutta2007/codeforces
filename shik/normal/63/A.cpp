// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#define N 110
using namespace std;
struct P {
	int id; string name,type;
	void read( int _id ) { id=_id; cin>>name>>type; }
} p[N];
int tmt( string s ) {
	if ( s=="rat" ) return 1;
	if ( s=="woman" || s=="child" ) return 2;
	if ( s=="man" ) return 3;
	if ( s=="captain" ) return 4;
	puts("QQ");
	return -1;
}
bool cp( P a, P b ) {
	if ( tmt(a.type)!=tmt(b.type) ) return tmt(a.type)<tmt(b.type);
	return a.id<b.id;
}
int main()
{
	int n,i;
	cin>>n;
	for ( i=0; i<n; i++ ) p[i].read(i);
	sort(p,p+n,cp);
	for ( i=0; i<n; i++ ) cout<<p[i].name<<endl;
	return 0;
}