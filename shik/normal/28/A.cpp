// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 514
#define L 200010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
vector<int> v[L];
int cnt[L];
int main()
{
	int n,m,x[N],y[N],d[N],l;
	scanf("%d%d",&n,&m);
	for ( int i=0; i<n; i++ ) scanf("%d%d",x+i,y+i);
	x[n]=x[0]; y[n]=y[0]; x[n+1]=x[1]; y[n+1]=y[1];
	for ( int i=0; i<=n; i++ ) d[i]=abs(x[i]-x[i+1])+abs(y[i]-y[i+1]);
	for ( int i=0; i<m; i++ ) {
		scanf("%d",&l);
		v[l].push_back(i+1);
	}
	for ( int i=0; i<n; i+=2 ) cnt[d[i]+d[i+1]]++;
	int flg=1;
	for ( int i=0; i<L; i++ ) if ( cnt[i]>SZ(v[i]) ) flg=0;
	if ( flg ) {
		puts("YES");
		for ( int i=0; i<n; i+=2 ) {
			printf("-1 %d%c",v[d[i]+d[i+1]].back(),i==n-2?'\n':' ');
			v[d[i]+d[i+1]].pop_back();
		}
		return 0;
	}
	memset(cnt,0,sizeof(cnt));
	for ( int i=1; i<n; i+=2 ) cnt[d[i]+d[i+1]]++;
	flg=1;
	for ( int i=0; i<L; i++ ) if ( cnt[i]>SZ(v[i]) ) flg=0;
	if ( flg ) {
		puts("YES");
		printf("%d -1 ",v[d[n-1]+d[n]].back());
		v[d[n-1]+d[n]].pop_back();
		for ( int i=1; i<n-1; i+=2 ) {
			printf("%d -1%c",v[d[i]+d[i+1]].back(),i==n-3?'\n':' ');
			v[d[i]+d[i+1]].pop_back();
		}
		return 0;
	}
	puts("NO");
	return 0;
}