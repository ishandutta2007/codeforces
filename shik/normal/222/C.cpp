// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
#define S 10000010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int p[S];
void predo() {
	for ( int i=2; i*i<S; i++ ) if ( !p[i] ) for ( int j=i*i; j<S; j+=i ) p[j]=i;
	for ( int i=2; i<S; i++ ) if ( !p[i] ) p[i]=i;
}
void shik( int n, int s[], int t[] ) {
	for ( int i=0; i<n; i++ ) for ( int j=s[i]; j>1; j/=p[j] ) t[p[j]]++;
}
void meow( int n, int s[], int t[] ) {
	for ( int i=0; i<n; i++ ) {
		int x=1;
		for ( int j=s[i]; j>1; j/=p[j] ) {
			if ( t[p[j]]>0 ) t[p[j]]--;
			else x*=p[j];
		}
		printf("%d%c",x,i==n-1?'\n':' ');
	}
}
int n,m,a[N],b[N],x[S],y[S];
int main()
{
	predo();
	scanf("%d%d",&n,&m);
	for ( int i=0; i<n; i++ ) scanf("%d",a+i);
	for ( int i=0; i<m; i++ ) scanf("%d",b+i);
	printf("%d %d\n",n,m);
	shik(n,a,x); shik(m,b,y);
	meow(n,a,y); meow(m,b,x);
	return 0;
}