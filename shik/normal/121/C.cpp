// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
vector<LL> lk;
void go( LL n ) {
	if ( n ) lk.push_back(n);
	if ( n>=100000000 ) return;
	go(n*10+4);
	go(n*10+7);
}
bool chk( int x ) { return count(lk.begin(),lk.end(),x); }
LL fac[15]={1};
int per[15],vis[15];
int main()
{
	go(0);
	sort(lk.begin(),lk.end());
	for ( int i=1; i<15; i++ ) fac[i]=fac[i-1]*i;
	int n,k,ans=0;
	scanf("%d%d",&n,&k);
	if ( n<15 && fac[n]<k ) { puts("-1"); return 0; }
	for ( int i=0; i<15; i++ ) {
		for ( int j=0; j<15; j++ ) if ( !vis[j] ) {
			if ( k>fac[14-i] ) k-=fac[14-i];
			else {
				per[i]=j;
				vis[j]=1;
				break;
			}
		}
	}
	ans+=upper_bound(lk.begin(),lk.end(),n-15)-lk.begin();
	for ( int i=0; i<15; i++ ) if ( chk(n-14+i) && chk(n-14+per[i]) ) ans++;
	printf("%d\n",ans);
	return 0;
}