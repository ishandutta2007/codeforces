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
    for ( int i=0; i<5; i++ ) for ( int j=0; j<5; j++ ) {
        int x;
        scanf("%d",&x);
        if ( x ) printf("%d\n",abs(i-2)+abs(j-2));
    }
    return 0;
}