// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define M 100010
#define MOD 1000000007
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
using namespace std;
typedef pair<int,int> PII;
typedef long long LL;
struct P {
	int s,t;
	void read() { scanf("%d%d",&s,&t); }
} p[M];
bool cpt( P a, P b ) { return a.t>b.t; }
priority_queue<PII> q;
LL now=1;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for ( int i=0; i<m; i++ ) p[i].read();
	sort(p,p+m,cpt);
	q.push(MP(n,1));
	for ( int i=0,j; i<m; i=j ) {
		while ( !q.empty() && q.top().first>p[i].t ) {
			now-=q.top().second;
			q.pop();
		}
		for ( j=i; j<m&&p[i].t==p[j].t; j++ ) q.push(MP(p[j].s,now%MOD));
		now+=(j-i)*now;
		now%=MOD;
	}
	while ( !q.empty() && q.top().first>0 ) {
		now-=q.top().second;
		q.pop();
	}
	printf("%I64d\n",(now%MOD+MOD)%MOD);
	return 0;
}