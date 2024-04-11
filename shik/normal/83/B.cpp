// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define N 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
PII a[N];
int bye[N];
queue<PII> q;
int main()
{
	int n; LL k,sum=0,cnt=0;
	scanf("%d%I64d",&n,&k);
	for ( int i=0; i<n; i++ ) {
		scanf("%d",&a[i].first);
		a[i].second=i+1;
		sum+=a[i].first;
	}
	if ( sum<k ) { puts("-1"); return 0; }
	sort(a,a+n);
	for ( int i=0; i<n; i++ ) {
		if ( k>=1LL*(a[i].first-cnt)*(n-i) ) {
			k-=1LL*(a[i].first-cnt)*(n-i);
			bye[a[i].second]=1;
			cnt=a[i].first;
		} else {
			cnt+=k/(n-i);
			k%=n-i;
			break;
		}
	}
	for ( int i=0; i<n; i++ ) swap(a[i].first,a[i].second);
	sort(a,a+n);
	for ( int i=0; i<n; i++ ) if ( !bye[a[i].first] ) q.push(MP(a[i].first,a[i].second-cnt));
	while ( k-- ) {
		PII p=q.front(); q.pop();
		if ( --p.second ) q.push(p);
	}
	int f=0;
	while ( !q.empty() ) {
		if ( f ) putchar(' ');
		else f=1;
		printf("%d",q.front().first);
		q.pop();
	}
	puts("");
	return 0;
}