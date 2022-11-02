// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#define N 100010
#define INF (1LL<<60)
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
struct P {
	int id,c;
	LL s;
	void read( int _id ) { id=_id; scanf("%d%I64d",&c,&s); }
} p[N];
bool cp( P a, P b ) { return a.s>b.s; }
bool cq( const vector<P> &a, const vector<P> &b ) { return a.size()>b.size(); }
map<int,vector<P> > lst;
vector<vector<P> > v;
LL big[N];
int who[N];
int main()
{
	int n;
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) p[i].read(i+1);
	sort(p,p+n,cp);
	for ( int i=0; i<n; i++ ) lst[p[i].c].push_back(p[i]);
	FOR(it,lst) v.push_back(it->second);
	sort(v.begin(),v.end(),cq);
	for ( int i=0; i<SZ(v); i++ ) for ( int j=1; j<SZ(v[i]); j++ ) v[i][j].s+=v[i][j-1].s;
	LL ans=0; int w1=-1,w2=-1;
	fill(big,big+N,-INF);
	memset(who,-1,sizeof(who));
	for ( int i=0; i<SZ(v); i++ ) {
		for ( int j=0; j<SZ(v[i]); j++ )
			for ( int k=max(j-1,0); k<=j+1; k++ ) if ( v[i][j].s+big[k]>ans ) {
				ans=v[i][j].s+big[k];
				w1=i;
				w2=who[k];
			}
		for ( int j=0; j<SZ(v[i]); j++ ) if ( v[i][j].s>big[j] ) big[j]=v[i][j].s,who[j]=i;
	}
	printf("%I64d\n",ans);
	vector<int> sol;
	if ( SZ(v[w1])<SZ(v[w2]) ) swap(w1,w2);
	for ( int i=0; i<SZ(v[w1]) && i<SZ(v[w2]); i++ ) {
		sol.push_back(v[w1][i].id);
		sol.push_back(v[w2][i].id);
	}
	if ( SZ(v[w1])>SZ(v[w2]) ) sol.push_back(v[w1][SZ(v[w2])].id);
	printf("%d\n",SZ(sol));
	for ( int i=0; i<SZ(sol); i++ ) printf("%d%c",sol[i],i==SZ(sol)-1?'\n':' ');
	return 0;
}