// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x),end(x)
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define FOR(it,c) for ( auto it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

void RI() {}

template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}
// }}}

#define N 200010
const int MOD=1e9+7;
int inv[N],fac[N],ifac[N];
void predo() {
    inv[1]=1;
    REP1(i,2,N-1) inv[i]=1LL*inv[MOD%i]*(MOD-MOD/i)%MOD;
    fac[0]=fac[1]=ifac[0]=ifac[1]=1;
    REP1(i,2,N-1) fac[i]=1LL*fac[i-1]*i%MOD;
    REP1(i,2,N-1) ifac[i]=1LL*ifac[i-1]*inv[i]%MOD;
}

int C( int n, int m ) {
    return 1LL*fac[n]*ifac[m]%MOD*ifac[n-m]%MOD;
}

int dp[N];
int main() {
    predo();
    int q,n,f;
    RI(q);
    while ( q-- ) {
        RI(n,f);
        VI v;
        for ( int i=1; i*i<=n; i++ ) if ( n%i==0 ) {
            if ( i>=f ) v.PB(i);
            if ( i!=n/i && n/i>=f ) v.PB(n/i);
        }
        sort(ALL(v));
        int nv=SZ(v);
        memset(dp,0,nv*sizeof(int));
        REP(i,nv) {
            LL now=C(v[i]-1,f-1);
            REP(j,i) if ( v[i]%v[j]==0 ) now-=dp[j];
            dp[i]=now%MOD;
            if ( dp[i]<0 ) dp[i]+=MOD;
        }
        printf("%d\n",dp[nv-1]);
    }
    return 0;
}