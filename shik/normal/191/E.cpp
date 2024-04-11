// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define N 100010
#define INF 1234567890123456LL
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
LL s[N],x[N],y[N];
LL get( int l, int r, LL g ) {
	if ( l==r ) {
		x[l]=s[l];
		return 0;
	}
	int m=(l+r)/2;
	LL ret=get(l,m,g)+get(m+1,r,g);
	for ( int i=l,j=m+1; i<=m; i++ ) {
		while ( j<=r && x[j]-x[i]<=g ) j++;
		ret+=r-j+1;
	}
	memcpy(y+l,x+l,(r-l+1)*sizeof(LL));
	merge(y+l,y+m+1,y+m+1,y+r+1,x+l);
	return ret;
}
int main()
{
	int n;
	LL k;
	cin>>n>>k;
	for ( int i=1; i<=n; i++ ) cin>>s[i];
	for ( int i=1; i<=n; i++ ) s[i]+=s[i-1];
	LL L=-INF,R=INF;
	while ( L!=R ) {
		LL M=L+(R-L)/2;
		if ( get(0,n,M)>=k ) L=M+1;
		else R=M;
	}
	cout<<L<<endl;
	return 0;
}