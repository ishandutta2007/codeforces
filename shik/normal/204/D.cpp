// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1000010
#define MOD 1000000007
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int get( int s[N], int st, int ed ) { return st<=ed ? s[ed]-s[st-1] : 0; }
char s[N];
int pw[N],sx[N],sb[N],sw[N],l[N],sl[N],r[N],sr[N];
inline void adj( int &x ) {
	x%=MOD;
	x+=MOD;
	x%=MOD;
}
int main()
{
	int n,k;
	scanf("%d%d%s",&n,&k,s+1);
	pw[0]=1;
	for ( int i=1; i<=n; i++ ) pw[i]=pw[i-1]*2%MOD;
	for ( int i=1; i<=n; i++ ) sx[i]=sx[i-1]+(s[i]=='X');
	for ( int i=1; i<=n; i++ ) sb[i]=sb[i-1]+(s[i]=='B');
	for ( int i=1; i<=n; i++ ) sw[i]=sw[i-1]+(s[i]=='W');
	for ( int i=k; i<=n; i++ ) {
		if ( s[i-k]=='B' || get(sw,i-k+1,i)!=0 ) l[i]=0;
		else {
			int x=get(sx,1,i-k-1);
			l[i]=pw[x]-(i==k?0:sl[i-k-1]); adj(l[i]);
		}
		sl[i]=sl[i-1]+l[i]; adj(sl[i]);
		if ( s[i]=='X' ) sl[i]+=sl[i-1];
		adj(sl[i]);
	}
	for ( int i=n-k+1; i>=1; i-- ) {
		if ( s[i+k]=='W' || get(sb,i,i+k-1)!=0 ) r[i]=0;
		else {
			int x=get(sx,i+k+1,n);
			r[i]=pw[x]-sr[i+k+1]; adj(r[i]);
		}
		sr[i]=sr[i+1]+r[i]; adj(sr[i]);
		if ( s[i]=='X' ) sr[i]+=sr[i+1];
		adj(sr[i]);
	}
	//for ( int i=1; i<=n; i++ ) printf("%d: l=%d, sl=%d, r=%d, sr=%d\n",i,l[i],sl[i],r[i],sr[i]);
	int ans=0;
	for ( int i=1; i<=n; i++ ) {
		ans+=1LL*l[i]*sr[i+1]%MOD;
		adj(ans);
	}
	printf("%d\n",ans);
	return 0;
}