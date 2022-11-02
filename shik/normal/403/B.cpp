// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
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

#define S 33000
bool notp[S];
int ps[S],pn;
void predo() {
    for ( int i=2; i<S; i++ ) if ( !notp[i] ) for ( int j=i+i; j<S; j+=i ) notp[j]=1;
    for ( int i=2; i<S; i++ ) if ( !notp[i] ) ps[pn++]=i;
}

#define N 5010
int n,m,a[N],b[N];

int f( int x ) {
    static map<int,int> cache;
    if ( cache.count(x) ) return cache[x];
    int x_bak=x;
    int s=0;
    REP1(i,1,m) while ( x%b[i]==0 ) {
        x/=b[i];
        s--;
    }
    for ( int i=0; i<pn && ps[i]*ps[i]<=x; i++ ) while ( x%ps[i]==0 ) {
        x/=ps[i];
        s++;
    }
    if ( x>1 ) s++;
    cache[x_bak]=s;
    return s;
}

int g[N],w[N],dp[N];
int main() {
    predo();
    RI(n,m);
    REP1(i,1,n) RI(a[i]);
    REP1(i,1,m) RI(b[i]);
    g[1]=a[1];
    REP1(i,2,n) g[i]=__gcd(g[i-1],a[i]);
    REP1(i,1,n) w[i]=-f(g[i]);
    dp[0]=0;
    REP1(i,1,n) {
        dp[i]=-1e9;
        REP1(j,0,i-1) dp[i]=max(dp[i],dp[j]+(i-j)*w[i]);
    }
    int big=0;
    REP1(i,1,n) big=max(big,dp[i]);
    int ans=0;
    REP1(i,1,n) ans+=f(a[i]);
    ans+=big;
    printf("%d\n",ans);
    return 0;
}