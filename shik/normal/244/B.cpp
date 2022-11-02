// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n;
set<int> ans;
void go( long long t, int x, int y ) {
    if ( t>n ) return;
    ans.insert(t);
    go(t*10+x,x,y);
    go(t*10+y,x,y);
}
int main()
{
    scanf("%d",&n);
    for ( int i=0; i<=9; i++ ) for ( int j=i+1; j<=9; j++ ) {
        if ( i ) go(i,i,j);
        go(j,i,j);
    }
    printf("%d\n",SZ(ans));
    return 0;
}