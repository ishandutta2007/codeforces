// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
inline void chkmin( int &a, int b ) { if ( b<a ) a=b; }
#define N 514
#define INF 514514514
int w[N][N],x[N];
LL ans[N];
bool alive[N];
int main()
{
    int n;
    scanf("%d",&n);
    for ( int i=1; i<=n; i++ ) for ( int j=1; j<=n; j++ ) scanf("%d",w[i]+j);
    for ( int i=1; i<=n; i++ ) scanf("%d",x+i);
    for ( int t=n; t>=1; t-- ) {
        int k=x[t];
        for ( int i=1; i<=n; i++ ) for ( int j=1; j<=n; j++ ) chkmin(w[i][j],w[i][k]+w[k][j]);
        LL s=0;
        alive[k]=1;
        for ( int i=1; i<=n; i++ ) if ( alive[i] )
            for ( int j=1; j<=n; j++ ) if ( alive[j] ) s+=w[i][j];
        ans[t]=s;
    }
    for ( int i=1; i<=n; i++ ) cout<<ans[i]<<(i==n?'\n':' ');
    return 0;
}