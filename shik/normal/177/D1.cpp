// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 100010
int a[N],b[N],s[N];
int main()
{
    int n,m,c;
    scanf("%d%d%d",&n,&m,&c);
    for ( int i=1; i<=n; i++ ) scanf("%d",a+i);
    for ( int i=1; i<=m; i++ ) scanf("%d",b+i);
    for ( int i=1; i<=m; i++ ) s[i]=(s[i-1]+b[i])%c;
    for ( int i=1; i<=n; i++ ) {
        int l=max(1,m-(n-i));
        int r=min(m,i);
        printf("%d%c",(int)((a[i]+1LL*(s[r]-s[l-1]+c))%c),i==n?'\n':' ');
    }
    return 0;
}