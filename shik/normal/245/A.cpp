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
    int n,c[2][2]={};
    scanf("%d",&n);
    while ( n-- ) {
        int t,x,y;
        scanf("%d%d%d",&t,&x,&y);
        c[t-1][0]+=x;
        c[t-1][1]+=y;
    }
    for ( int i=0; i<2; i++ ) puts(c[i][0]>=c[i][1]?"LIVE":"DEAD");
    return 0;
}