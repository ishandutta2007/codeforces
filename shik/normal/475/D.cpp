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

typedef vector<PII> VII;

#define N 100010
int n,a[N],dp[17][N];
VII vc;

int main() {
    RI(n);
    REP1(i,1,n) RI(a[i]);
    REP1(i,1,n) dp[0][i]=a[i];
    int lgn=__lg(n);
    REP(i,lgn) for ( int j=1; j+(1<<i)-1<=n; j++ ) dp[i+1][j]=__gcd(dp[i][j],dp[i][j+(1<<i)]);
    REP1(l,1,n) {
        int g=a[l],r=l;
        while ( 1 ) {
            int _r=r;
            for ( int j=lgn; j>=0; j-- ) if ( r+(1<<j)<=n && dp[j][r+1]%g==0 ) r+=(1<<j);
            //printf("%d, %d~%d: %d\n",l,_r,r,g);
            vc.PB(MP(g,r-_r+1));
            if ( r==n ) break;
            r++;
            g=__gcd(g,a[r]);
        }
    }
    sort(ALL(vc));
    map<int,LL> sol;
    int nvc=SZ(vc);
    for ( int i=0,j; i<nvc; i=j ) {
        LL s=0;
        for ( j=i; j<nvc && vc[i].first==vc[j].first; j++ ) s+=vc[j].second;
        sol[vc[i].first]=s;
    }
    int q;
    RI(q);
    while ( q-- ) {
        int x;
        RI(x);
        if ( !sol.count(x) ) puts("0");
        else cout<<sol[x]<<"\n";
    }
    return 0;
}