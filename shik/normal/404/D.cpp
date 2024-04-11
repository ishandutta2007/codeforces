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

const int MOD=1e9+7;

inline void add( int &a, int b ) { 
    a+=b;
    if ( a>=MOD ) a-=MOD;
}

#define N 1000010
char s[N];
int dp[N][4]; // 3 for bomb

int go( int p, int q ) {
    if ( !s[p] ) return q==0 || q==3;
    int &ret=dp[p][q];
    if ( ret!=-1 ) return ret;
    ret=0;
    char c=s[p];
    if ( q==0 ) {
        if ( c=='*' ) ret=0;
        else if ( isdigit(c) ) ret=go(p+1,c-'0');
        else {
            REP(i,3) add(ret,go(p+1,i));
        }
    } else if ( q==1 ) {
        if ( c=='*' ) ret=go(p+1,3);
        else if ( isdigit(c) ) ret=0;
        else ret=go(p+1,3);
    } else if ( q==2 ) {
        ret=0;
    } else {
        if ( c=='*' ) ret=go(p+1,3);
        else if ( c=='0' ) ret=0;
        else if ( c=='1' || c=='2' ) ret=go(p+1,c-'1');
        else {
            add(ret,go(p+1,3));
            add(ret,go(p+1,0));
            add(ret,go(p+1,1));
        }
    }
    return ret;
}

int main() {
    gets(s);
    memset(dp,-1,sizeof(dp));
    int ans=0;
    REP(i,3) add(ans,go(0,i));
    printf("%d\n",ans);
    return 0;
}