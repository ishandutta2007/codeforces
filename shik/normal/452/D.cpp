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

#define N 10010
int n,m[5],t[5],c[5],x[N],y[N];
int main() {
    RI(n);
    REP1(i,1,3) RI(m[i]);
    REP1(i,1,3) RI(t[i]);
    m[0]=m[4]=c[0]=n;
    int ans=0;
    while ( 1 ) {
        int mi=1e9;
        REP(i,n) if ( x[i]<4 && c[x[i]+1]<m[x[i]+1] ) {
            int dt=max(0,t[x[i]]-y[i]);
            if ( dt<mi ) mi=dt;
        }
        if ( mi==1e9 ) break;
        ans+=mi;
        REP(i,n) if ( x[i]<4 ) {
            y[i]+=mi;
            if ( y[i]>=t[x[i]] && c[x[i]+1]<m[x[i]+1] ) {
                c[x[i]]--;
                x[i]++;
                c[x[i]]++;
                y[i]=0;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}