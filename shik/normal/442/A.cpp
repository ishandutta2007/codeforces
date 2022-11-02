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

inline int bit( int x, int i ) { return (x>>i)&1; }

bool good( int ma, int mb, int a, int b, int c[5][5] ) {
    if ( bit(ma,a) && bit(mb,b) ) return 1;
    if ( bit(ma,a) ) {
        int cnt=0;
        REP(i,5) cnt+=!!c[a][i];
        if ( cnt==1 ) return 1;
    }
    if ( bit(mb,b) ) {
        int cnt=0;
        REP(i,5) cnt+=!!c[i][b];
        if ( cnt==1 ) return 1;
    }
    int cnt=0;
    REP(i,5) REP(j,5) cnt+=!!c[i][j];
    return cnt==1;
}

#define N 110
int n,a[N],b[N],c[5][5];


int main() {
    RI(n);
    REP(i,n) {
        char ch;
        scanf(" %c%d",&ch,b+i);
        const char *s="RGBYW";
        a[i]=strchr(s,ch)-s;
        b[i]--;
    }
    REP(i,n) c[a[i]][b[i]]++;
    int ans=10;
    REP(ma,1<<5) REP(mb,1<<5) {
        int now=__builtin_popcount(ma)+__builtin_popcount(mb);
        if ( now>=ans ) continue;
        int rem=n,cc[5][5];
        bool vis[N]={};
        memcpy(cc,c,sizeof(c));
        while ( rem>0 ) {
            bool found=0;
            REP(i,n) if ( !vis[i] && good(ma,mb,a[i],b[i],cc) ) {
                found=1;
                vis[i]=1;
                rem--;
                cc[a[i]][b[i]]--;
            }
            if ( !found ) break;
        }
        if ( rem==0 ) ans=now;
    }
    printf("%d\n",ans);
    return 0;
}