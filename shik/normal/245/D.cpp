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
    int n;
    scanf("%d",&n);
    for ( int i=0; i<n; i++ ) {
        int s=0,x;
        for ( int j=0; j<n; j++ ) {
            scanf("%d",&x);
            if ( i!=j ) s|=x;
        }
        printf("%d%c",s,i==n-1?'\n':' ');
    }
    return 0;
}