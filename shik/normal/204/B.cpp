// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef pair<int,int> PII;
map<int,PII> mp;
int main()
{
	int n,m,a,b;
	scanf("%d",&n); m=(n+1)/2;
	for ( int i=0; i<n; i++ ) {
		scanf("%d%d",&a,&b);
		mp[a].first++;
		if ( a!=b ) mp[b].second++;
	}
	int ans=n+1;
	FOR(it,mp) {
		int c1=(it->second).first;
		int c2=(it->second).second;
		if ( c1+c2<m ) continue;
		ans=min(ans,max(m-c1,0));
	}
	printf("%d\n",ans<=n?ans:-1);
	return 0;
}