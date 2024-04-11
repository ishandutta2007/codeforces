// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long double LD;
#define N 200010
int a[N];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for ( int i=1; i<=n; i++ ) scanf("%d",a+i);
    int c=0;
    LD d=0;
    for ( int i=1; i<=n; i++ ) {
        LD now=d-(LD)c*(n-i)*a[i];
        if ( now<k ) {
            printf("%d\n",i);
            continue;
        }
        d+=(LD)a[i]*c++;
    }
    return 0;
}