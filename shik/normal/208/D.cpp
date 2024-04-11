// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
int main()
{
	int n,p[55],q[5];
	LL c[5]={},now=0;
	cin>>n;
	for ( int i=0; i<n; i++ ) cin>>p[i];
	for ( int i=0; i<5; i++ ) cin>>q[i];
	for ( int i=0; i<n; i++ ) {
		now+=p[i];
		for ( int j=4; j>=0; j-- ) {
			c[j]+=now/q[j];
			now%=q[j];
		}
	}
	for ( int i=0; i<5; i++ ) cout<<c[i]<<(i==4?'\n':' ');
	cout<<now<<endl;
	return 0;
}