// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
inline int bit( int x, int i ) { return (x>>i)&1; }
#define N 1000010
int n,m,a[N],b[N];
LL c[30];
bool chk( int mid ) {
    LL ca[30],cb[30]={};
    memcpy(ca,c,sizeof(c));
    for ( int i=1; i<=mid; i++ ) cb[b[i]]++;
    for ( int i=29; i>=0; i-- ) {
        if ( cb[i]>ca[i] ) return 0;
        ca[i]-=cb[i];
        if ( i>0 ) ca[i-1]+=ca[i]*2;
    }
    return 1;
}
int main()
{
    scanf("%d%d",&n,&m);
    for ( int i=1; i<=n; i++ ) scanf("%d",a+i);
    for ( int i=1; i<=m; i++ ) scanf("%d",b+i);
    sort(b+1,b+m+1);
    for ( int i=1; i<=n; i++ ) for ( int j=0; j<30; j++ ) if ( bit(a[i],j) ) c[j]++;
    int l=0,r=m;
    while ( l!=r ) {
        int mid=(l+r+1)/2;
        if ( chk(mid) ) l=mid;
        else r=mid-1;
    }
    printf("%d\n",l);
    return 0;
}