// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
    int a,b,n;
    scanf("%d%d%d",&a,&b,&n);
    for ( int i=0; i<10; i++ ) if ( (a*10+i)%b==0 ) {
        if ( n==1 ) return printf("%d\n",a*10+i),0;
        for ( int j=0; j<10; j++ ) if ( j%b==0 ) {
            printf("%d",a*10+i);
            for ( int k=1; k<n; k++ ) printf("%d",j);
            puts("");
            return 0;
        }
    }
    puts("-1");
    return 0;
}