// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
int main()
{
    int s[3][3]={};
    for ( int i=0; i<3; i++ ) for ( int j=0; j<3; j++ ) {
        int t;
        scanf("%d",&t);
        s[i][j]^=(t&1);
        for ( int k=0; k<4; k++ ) {
            int x=i+dx[k],y=j+dy[k];
            if ( x>=0 && x<3 && y>=0 && y<3 ) s[x][y]^=(t&1);
        }
    }
    for ( int i=0; i<3; i++,puts("") ) for ( int j=0; j<3; j++ ) printf("%d",s[i][j]^1);
    return 0;
}