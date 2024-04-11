// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
    int n,m,x[2]={},y[2]={},v[110][110]={};
    scanf("%d%d",&n,&m);
    for ( int i=1; i<=n; i++ ) for ( int j=1; j<=m; j++ ) {
        char c;
        scanf(" %c",&c);
        if ( c=='.' ) continue;
        v[i][j]=1;
        if ( !x[0] ) x[0]=i;
        else if ( i!=x[0] ) x[1]=i;
        if ( !y[0] ) y[0]=j;
        else if ( j!=y[0] ) y[1]=j;
    }
    for ( int i=0; i<2; i++ ) for ( int j=0; j<2; j++ ) if ( !v[x[i]][y[j]] ) printf("%d %d\n",x[i],y[j]);
    return 0;
}