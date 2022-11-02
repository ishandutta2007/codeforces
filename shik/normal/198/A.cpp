// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	long long k,b,n,t,d=0,x=1;
	cin>>k>>b>>n>>t;
	if ( k==1 ) {
		long long z=1+n*b;
		if ( t>=z ) puts("0");
		else cout<<(z-t+b-1)/b<<endl;
		return 0;
	}
	while ( d<n && (k-1+b)*(x*=k)<=(k-1)*t+b ) d++;
	cout<<n-d<<endl;
	return 0;
}