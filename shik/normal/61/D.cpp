// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
vector<PII> e[N];
LL go( int p, int f ) {
	LL r=0;
	FOR(it,e[p]) if ( it->first != f ) r=max(r,go(it->first,p)+it->second);
	return r;
}
int main()
{
	LL ans=0;
	int n,a,b,c;
	scanf("%d",&n);
	for ( int i=1; i<n; i++ ) {
		scanf("%d%d%d",&a,&b,&c);
		ans+=2*c;
		e[a].push_back(make_pair(b,c));
		e[b].push_back(make_pair(a,c));
	}
	printf("%I64d\n",ans-go(1,0));
	return 0;
}