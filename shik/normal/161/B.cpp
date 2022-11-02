// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 1010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
struct P {
	int id,c,t;
	void read( int _id ) { id=_id; scanf("%d%d",&c,&t); }
} p[N];
bool cp( P a, P b ) { return a.c>b.c; }
vector<P> sol[N];
int main()
{
	int n,k;
	LL ans=0;
	scanf("%d%d",&n,&k);
	for ( int i=0; i<n; i++ ) p[i].read(i+1);
	sort(p,p+n,cp);
	int cnt=0;
	for ( int i=0; i<n; i++ ) if ( p[i].t==1 ) {
		sol[min(cnt,k-1)].push_back(p[i]);
		cnt++;
	}
	for ( int i=0; i<n; i++ ) if ( p[i].t==2 ) {
		sol[min(cnt,k-1)].push_back(p[i]);
		cnt++;
	}
	for ( int i=0; i<k; i++ ) {
#define INF 1234567890
		int sml=INF,flg=0;
		FOR(it,sol[i]) {
			ans+=(2*it->c);
			sml=min(sml,it->c);
			if ( it->t==1 ) flg=1;
		}
		if ( flg ) ans-=sml;
	}
	printf("%I64d.%d\n",ans/2,ans%2==0?0:5);
	for ( int i=0; i<k; i++ ) {
		printf("%d",SZ(sol[i]));
		FOR(it,sol[i]) printf(" %d",it->id);
		puts("");
	}
	return 0;
}