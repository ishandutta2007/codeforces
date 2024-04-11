// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 110
char s[N][N];
int cx[N],cy[N];
int main()
{
    int n;
    scanf("%d",&n);
    for ( int i=0; i<n; i++ ) scanf("%s",s[i]);
    for ( int i=0; i<n; i++ ) for ( int j=0; j<n; j++ ) if ( s[i][j]=='E' ) cx[i]++,cy[j]++;
    if ( count(cx,cx+n,n)==0 ) {
        for ( int i=0; i<n; i++ ) for ( int j=0; j<n; j++ ) if ( s[i][j]=='.' ) {
            printf("%d %d\n",i+1,j+1);
            break;
        }
    } else if ( count(cy,cy+n,n)==0 ) {
        for ( int j=0; j<n; j++ ) for ( int i=0; i<n; i++ ) if ( s[i][j]=='.' ) {
            printf("%d %d\n",i+1,j+1);
            break;
        }
    } else {
        puts("-1");
    }
    return 0;
}