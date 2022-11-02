// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 100010
int n,a[N],b[N],p[N];
int main()
{
    scanf("%d",&n);
    for ( int i=1; i<=n; i++ ) scanf("%d",a+i);
    for ( int i=1; i<=n; i++ ) scanf("%d",b+i);
    for ( int i=1; i<=n; i++ ) p[a[i]]=b[i];
    for ( int i=1; i<=n; i++ ) printf("%d%c",p[i],i==n?'\n':' ');
    return 0;
}