// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 100010
int a[N],n;
int stk[N],top;
int solve() {
    int ret=0;
    top=0;
    for ( int i=0; i<n; i++ ) {
        while ( top>0 && a[i]>stk[top-1] ) {
            ret=max(ret,a[i]^stk[top-1]);
            top--;
        }
        stk[top++]=a[i];
    }
    return ret;
}
int main()
{
    scanf("%d",&n);
    for ( int i=0; i<n; i++ ) scanf("%d",a+i);
    int ans=0;
    ans=max(ans,solve());
    reverse(a,a+n);
    ans=max(ans,solve());
    printf("%d\n",ans);
    return 0;
}