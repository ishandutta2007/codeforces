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
    unsigned ans=0;
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    for ( int i=1; i<=a; i++ ) for ( int j=1; j<=b; j++ ) for ( int k=1; k<=c; k++ ) {
        int x=i*j*k;
        int v=1;
        for ( int l=2; l*l<=x; l++ ) if ( x%l==0 ) {
            int f=1;
            while ( x%l==0 ) f++,x/=l;
            v*=f;
        }
        if ( x>1 ) v*=2;
        ans+=v;
    }
    printf("%u\n",ans%(1u<<30));
    return 0;
}