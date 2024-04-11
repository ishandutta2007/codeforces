// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 110
using namespace std;
int n,e[N][N],eg[N][N],el[N][N],con[N],ans[N];
vector<int> cal( int x ) {
	vector<int> r;
	for ( int i=1; i*i<=x; i++ )
		if ( x%i==0 && __gcd(i,x/i)==1 ) {
			r.push_back(i);
			if ( i!=x/i ) r.push_back(x/i);	
		}
	sort(r.begin(),r.end());
	return r;
}
long long lcm( long long a, long long b ) { return a*b/__gcd(a,b); }
int tmt[N];
bool chk( int p, int x ) {
	if ( tmt[p] ) return tmt[p]==x;
	tmt[p]=x;
	for ( int i=1; i<=n; i++ )
		if ( e[p][i] ) {
			long long y=(long long)(eg[p][i])*el[p][i]/x;
			if ( y<1 || y>1000000 ) return 0;
			if ( __gcd((long long)x,y)!=eg[p][i] ) return 0;
			if ( lcm(x,y)!=el[p][i] ) return 0;
			if ( !chk(i,y) ) return 0;
		}
	return 1;
}
void sel( int p, int x ) {
	if ( ans[p] ) return;
	ans[p]=x;
	for ( int i=1; i<=n; i++ )
		if ( e[p][i] ) {
			long long y=(long long)(eg[p][i])*el[p][i]/x;
			sel(i,y);
		}	
}
int main()
{
	int m,a,b,gg,ll,i,d;
	scanf("%d%d",&n,&m);
	while ( m-- ) {
		scanf("%d%d%d%d",&a,&b,&gg,&ll);
		if ( ll%gg!=0 ) break;
		con[a]=b; con[b]=a;
		e[a][b]=e[b][a]=1;
		eg[a][b]=eg[b][a]=gg;
		el[a][b]=el[b][a]=ll;
	}
	if ( m>=0 ) {
		puts("NO");
		return 0;	
	}
	for ( i=1; i<=n; i++ ) {
		if ( ans[i] ) continue;
		if ( !con[i] ) {
			ans[i]=1;
			continue;
		}
		a=i; b=con[i];
		gg=eg[a][b];
		ll=el[a][b];
		d=ll/gg;
		vector<int> fac=cal(d);
		for ( vector<int>::iterator it=fac.begin(); it!=fac.end(); it++ ) {
			int now=*it;
			a=now*gg;
			b=d/now*gg;
			memset(tmt,0,sizeof(tmt));
			if ( chk(i,a) ) sel(i,a);
		}
		if ( !ans[i] ) break;
	}
	if ( i<=n ) puts("NO");
	else {
		puts("YES");
		for ( i=1; i<=n; i++ ) printf("%d%c",ans[i],i==n?'\n':' ');	
	}
	return 0;
}