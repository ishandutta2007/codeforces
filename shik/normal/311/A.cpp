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
    int n,k;
    scanf("%d%d",&n,&k);
    int m=n*(n-1)/2;
    if ( k>=m ) puts("no solution");
    else {
        for ( int i=0; i<n; i++ ) printf("0 %d\n",i);
    }
    return 0;
}