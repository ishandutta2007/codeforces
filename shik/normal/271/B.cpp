// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 514
#define S 1000000
int p[S];
int a[N][N],b[N][N],x[N],y[N];
int main()
{
    p[1]=1;
    for ( int i=2; i*i<S; i++ ) if ( !p[i] )
        for ( int j=i*i; j<S; j+=i ) p[j]=1;
    int n,m;
    scanf("%d%d",&n,&m);
    for ( int i=0; i<n; i++ ) for ( int j=0; j<m; j++ ) scanf("%d",a[i]+j);
    for ( int i=0; i<n; i++ ) for ( int j=0; j<m; j++ ) while ( p[a[i][j]+b[i][j]] ) b[i][j]++;
    for ( int i=0; i<n; i++ ) for ( int j=0; j<m; j++ ) {
        x[i]+=b[i][j];
        y[j]+=b[i][j];
    }
    int ans=min(*min_element(x,x+n),*min_element(y,y+m));
    printf("%d\n",ans);
    return 0;
}