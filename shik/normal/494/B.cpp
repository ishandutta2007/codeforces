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

#define N 100010
const int MOD=1e9+7;

bool isprime( int x ) {
    for ( int i=x; i*i<=x; i++ ) if ( x%i==0 ) return 0;
    return 1;
}

int get_p() {
    srand(time(0)^getpid());
    int p=1e9+rand()%10000;
    while ( !isprime(p) ) p++;
    return p;
}

char s[N],t[N];
bool good[N];
int l[N];
LL dp[N],sdp[N];
int main() {
    int p=get_p();
    int n=strlen(gets(s));
    int m=strlen(gets(t));
    LL ht=0;
    REP(i,m) ht=(ht*131+t[i])%p;
    LL pw=1;
    REP(i,m) pw=pw*131%p;
    LL hs=0;
    REP(i,n) {
        hs=(hs*131+s[i])%p;
        if ( i>=m ) hs-=s[i-m]*pw%p;
        if ( hs<0 ) hs+=p;
        if ( i>=m-1 && hs==ht ) good[i-m+1]=1;
    }
    //REP(i,n) if ( good[i] ) printf("%d ",i); puts("");
    REP(i,n) {
        l[i]=(i>=1?l[i-1]:-1);
        if ( i>=m-1 && good[i-m+1] ) l[i]=i-m+1;
    }
    //REP(i,n) printf("%d ",l[i]); puts("");
    REP(i,n) {
        dp[i]=0;
        if ( i>=1 ) dp[i]+=dp[i-1];
        else dp[i]++;
        if ( l[i]!=-1 ) {
            if ( l[i]>=1 ) dp[i]+=sdp[l[i]-1];
            dp[i]++;
        }
        dp[i]%=MOD;
        if ( i>=1 ) sdp[i]+=sdp[i-1];
        sdp[i]+=dp[i];
        sdp[i]%=MOD;
        //printf("%d: %lld,%lld\n",i,dp[i],sdp[i]);
    }
    int ans=dp[n-1]-1;
    if ( ans<0 ) ans+=MOD;
    printf("%d\n",ans);
    return 0;
}