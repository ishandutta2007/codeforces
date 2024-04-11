// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n,k,a[55],sol[55];
set<int> v1[55],v2;
void go( int p, int s, int lv ) {
    if ( k==0 || v1[p].count(s) ) return;
    v1[p].insert(s);
    if ( s>0 && !v2.count(s) ) {
        k--;
        printf("%d",lv);
        for ( int i=0; i<lv; i++ ) printf(" %d",sol[i]);
        puts("");
        v2.insert(s);
    }
    if ( p==n ) return;
    sol[lv]=a[p];
    go(p+1,s+a[p],lv+1);
    go(p+1,s,lv);
}
int main()
{
    scanf("%d%d",&n,&k);
    for ( int i=0; i<n; i++ ) scanf("%d",a+i);
    go(0,0,0);
    return 0;
}