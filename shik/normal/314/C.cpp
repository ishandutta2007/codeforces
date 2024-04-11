// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
#define MOD 1000000007
#define N 1000010
struct BIT {
    LL dat[N];
    void ins( int x, int v ) {
        if ( v<0 ) v+=MOD;
        for ( int i=x; i<N; i+=i&-i ) dat[i]+=v;
    }
    LL ask( int x ) {
        LL r=0;
        for ( int i=x; i; i-=i&-i ) r+=dat[i];
        return r%MOD;
    }
} bit;
int n,a[N],pre[N];
int main()
{
    scanf("%d",&n);
    for ( int i=1; i<=n; i++ ) scanf("%d",a+i);
    LL ans=0;
    for ( int i=1; i<=n; i++ ) {
        int now=(bit.ask(a[i])*a[i]+a[i])%MOD;
        if ( pre[a[i]] ) {
            now-=pre[a[i]];
            if ( now<0 ) now+=MOD;
        }
        pre[a[i]]=(pre[a[i]]+now)%MOD;
        bit.ins(a[i],now);
        ans+=now;
    }
    ans%=MOD;
    printf("%d\n",(int)ans);
    return 0;
}