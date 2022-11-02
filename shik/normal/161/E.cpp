// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define S 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int p[S]={1,1},pw[5]={1},tmt[S][5];
void predo() {
	for ( int i=1; i<5; i++ ) pw[i]=pw[i-1]*10;
	for ( int i=2; i*i<S; i++ ) if ( !p[i] ) for ( int j=i*i; j<S; j+=i ) p[j]=1;
	for ( int i=0; i<=99999; i++ ) for ( int j=0; j<5; j++ )
		if ( i/pw[j]%10==0 ) for ( int k=0; k<10; k++ ) if ( !p[i+k*pw[j]] ) tmt[i][j]++;
}
int n,mat[5][5],val[5],up[5],ans;
void go( int x, int y ) {
	if ( x==n-1 ) {
		int tmp=1;
		for ( int i=1; i<n&&tmp; i++ ) tmp*=tmt[val[i]][n-i-1];
		ans+=tmp;
		return;
	}
	if ( y==n ) {
		go(x+1,x+2);
		return;
	}
	for ( int i=0; i<10; i++ ) {
		val[x]+=i*pw[n-y-1];
		val[y]+=i*pw[n-x-1];
		go(x,y+1);
		val[x]-=i*pw[n-y-1];
		val[y]-=i*pw[n-x-1];
	}
}
void solve() {
	memset(mat,0,sizeof(mat));
	memset(val,0,sizeof(val));
	char s[10];
	scanf("%s",s);
	n=strlen(s);
	for ( int i=0; i<n; i++ ) mat[0][i]=mat[i][0]=s[i]-'0';
	for ( int i=0; i<n; i++ ) for ( int j=0; j<n; j++ ) val[i]+=mat[i][j]*pw[n-j-1];
	if ( p[val[0]] ) { puts("0"); return; }
	ans=0;
	go(1,2);
	printf("%d\n",ans);
}
int main()
{
	predo();
	int t;
	scanf("%d",&t);
	while ( t-- ) solve();
	return 0;
}