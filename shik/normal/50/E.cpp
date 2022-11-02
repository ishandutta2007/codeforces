// by shik
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
long long m;
long long cal( long long b ) {
	long long L=0,R=b,M;
	while ( L!=R ) {
		M=(L+R)/2;
		if ( b*b-M*M<=m ) R=M;
		else L=M+1;	
	}
	//printf("%lld: %lld, %lld\n",b,L,max(0LL,b-2-L));
	if ( L>b-3 ) return 0;
	else return b-2-L;
}
int main()
{
	long long n,i,ans=1;
	cin>>n>>m;
	for ( i=2; i<=n; i++ ) {
		ans+=2*min(i*i,m);
		if ( 2*i-1<=min(i*i,m) ) ans--;
		if ( 4*i-4<=min(i*i,m) ) ans--;
		if ( i>=3 ) ans-=2*cal(i);
	}
	cout<<ans<<endl;
	return 0;
}