// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 1010
bool c[N][N];
int main()
{
    int n,m,x,y;
    scanf("%d%d",&n,&m);
    for ( int t=1; t<=m; t++ ) {
        scanf("%d%d",&x,&y);
        c[x][y]=1;
        bool ok=0;
        for ( int i=max(1,x-2); i<=min(n-2,x); i++ ) for ( int j=max(1,y-2); j<=min(n-2,y); j++ ) {
            bool flg=1;
            for ( int k=0; k<3; k++ ) for ( int l=0; l<3; l++ ) flg&=c[i+k][j+l];
            ok|=flg;
        }
        if ( ok ) return printf("%d\n",t),0;
    }
    puts("-1");
    return 0;
}