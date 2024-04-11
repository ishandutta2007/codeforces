// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 10
#define M 100
#define K 100
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n,m,k,a[N][M],b[N][M],c[N][M],v[10010],nv;
char name[N][100];
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for ( int i=0; i<n; i++ ) {
        scanf("%s",name[i]);
        for ( int j=0; j<m; j++ ) scanf("%d%d%d",a[i]+j,b[i]+j,c[i]+j);
    }
    int ans=0;
    for ( int i=0; i<n; i++ ) for ( int j=0; j<n; j++ ) if ( i!=j ) {
        nv=0;
        for ( int ii=0; ii<m; ii++ ) for ( int jj=0; jj<c[i][ii]; jj++ ) v[nv++]=b[j][ii]-a[i][ii];
        sort(v,v+nv);
        int now=0;
        for ( int x=nv-1; x>=nv-k&&v[x]>0; x-- ) now+=v[x];
        ans=max(ans,now);
    }
    printf("%d\n",ans);
    return 0;
}