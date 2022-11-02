// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#define N 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int d;
multiset<int> s;
void ins( int x ) {
	x-=d;
	s.insert(x);
}
void del( int x ) {
	x-=d;
	s.erase(s.find(x));
}
int get() {
	int v=-d;
	multiset<int>::iterator it=s.lower_bound(v);
	multiset<int>::iterator jt=it; jt--;
	int ans=N;
	if ( it==s.begin() ) ans=abs(*it+d);
	else if ( it==s.end() ) ans=abs(*jt+d);
	else ans=min(abs(*it+d),abs(*jt+d));
	return ans;
}
int a[N],b[N],pos[N];
int main()
{
	int n;
	scanf("%d",&n);
	for ( int i=1; i<=n; i++ ) scanf("%d",a+i);
	for ( int i=1; i<=n; i++ ) scanf("%d",b+i);
	for ( int i=1; i<=n; i++ ) pos[a[i]]=i;
	for ( int i=1; i<=n; i++ ) ins(i-pos[b[i]]);
	for ( int i=1; i<=n; i++ ) {
		printf("%d\n",get());
		del(1-pos[b[i]]);
		d--;
		ins(n-pos[b[i]]);
	}
	return 0;
}