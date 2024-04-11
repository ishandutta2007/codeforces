// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 60
#define pw2(x) (1LL<<(x))
using namespace std;
typedef long long LL;
int n,sol[N];
LL cal( int x, int flg ) {
	LL r=0;
	for ( int i=1; 2*i<=x; i++ ) r+=pw2(i-1)*pw2(x-2*i);
	r+=pw2((x+flg)/2);
	return r;
}
bool chk_0( int p ) {
	for ( int i=0; i<=p; i++ )
		if ( n-i-1<=p && sol[i]!=sol[n-i-1] ) return sol[i]<sol[n-i-1];
	return 1;
}
bool chk_1( int p ) {
	for ( int i=0; i<=p; i++ )
		if ( n-i-1<=p && sol[i]==sol[n-i-1] ) return sol[i]==0;
	return 1;
}
void go( int p, LL m ) {
	if ( p==n ) {
		if ( m!=1 || !(sol[n-1]==0?chk_0(n-1):chk_1(n-1)) ) puts("-1");
		else {
			for ( int i=0; i<n; i++ ) printf("%d",sol[i]);
			puts("");
		}
		return;
	}
	if ( p==0 ) {
		sol[p]=0;
		go(p+1,m);
		return;
	}
	sol[p]=0;
	LL cnt=0;
	for ( int i=1; i<=p&&p<n-i-1; i++ ) {
		if ( sol[i]==1 ) continue;
		cnt+=2*pw2(n-(p+1)-(i+1));
	}
	if ( n-p-1<=p ) {
		if ( chk_0(p) ) cnt++;
		if ( p<n-1 && chk_1(p) ) cnt++;
	} else {
		cnt+=cal(n-2*(p+1),0);
		cnt+=cal(n-2*(p+1),1);
	}
	if ( cnt<m ) {
		sol[p]=1;
		m-=cnt;
	}
	go(p+1,m);
}
int main()
{
	LL k;
	scanf("%d%I64d",&n,&k);
	go(0,k+1);
	return 0;
}