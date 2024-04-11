// shik {{{
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

int lrec(const int *init, const int *tran, int n, int mod, LL x){
    auto mul = [&](VI& a, VI& b){
        VI r(n*2-1);
        REP(i, n) REP(j, n) r[i+j] = (r[i+j] + (LL)a[i] * b[j]) % mod;
        REP(i, n-1) REP(j, n) r[i+j+1] = (r[i+j+1] + (LL)r[i] * tran[j]) % mod;
        return VI(r.begin() + n - 1, r.end());
    };
    VI sol(n), coef(tran, tran + n);
    sol[n-1-x%n] = 1;
    for(LL u = x / n; u; u >>= 1){
        if(u & 1) sol = mul(sol, coef);
        coef = mul(coef, coef);
    }
    LL ans = 0;
    REP(i, n) ans += (LL)sol[i] * init[n-i-1] % mod;
    return ans % mod;
}

const int MOD=1e9+7;

int main() {
    int x,y,n;
    RI(x,y,n);
    int init[2]={x,y};
    int tran[2]={+1,-1};
    int ans=lrec(init,tran,2,1000000007,n-1);
    if ( ans<0 ) ans+=MOD;
    printf("%d\n",ans);
    return 0;
}