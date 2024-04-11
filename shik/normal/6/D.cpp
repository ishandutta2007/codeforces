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

#define N 15
#define H 20
#define INF 514514514
int n,a,b,h[N],dp[N][H][H],fire[N][H][H];

int go( int p, int h1, int h2 ) {
    if ( p==n ) {
        if ( h1==0 && h2==0 ) return 0;
        else return INF;
    }
    int &ret=dp[p][h1][h2];
    if ( ret!=-1 ) return ret;
    ret=INF;
    REP1(i,0,16) {
        if ( i*b<h1 ) continue;
        int nh1=max(0,h2-i*a);
        int nh2=max(0,h[p+1]-i*b);
        int now=i+go(p+1,nh1,nh2);
        if ( now<ret ) {
            ret=now;
            fire[p][h1][h2]=i;
        }
    }
    return ret;
}

int main() {
    RI(n,a,b);
    REP1(i,1,n) RI(h[i]);
    REP1(i,1,n) h[i]++;
    memset(dp,-1,sizeof(dp));
    int ans=go(2,h[1],h[2]);
    printf("%d\n",ans);
    int h1=h[1],h2=h[2];
    VI sol;
    REP1(i,2,n-1) {
        int f=fire[i][h1][h2];
        h1=max(0,h2-f*a);
        h2=max(0,h[i+1]-f*b);
        while ( f-- ) sol.PB(i);
    }
    REP(i,SZ(sol)) printf("%d%c",sol[i],i+1==SZ(sol)?'\n':' ');
    return 0;
}