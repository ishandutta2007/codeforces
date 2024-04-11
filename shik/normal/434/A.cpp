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
int n,m,a[N];
VI app[N];
int main() {
    RI(n,m);
    REP1(i,1,m) RI(a[i]);
    REP1(i,1,m) app[a[i]].PB(i);
    LL w=0;
    REP1(i,1,m-1) w+=abs(a[i+1]-a[i]);
    LL ans=w;
    REP1(i,1,n) {
        LL x=0;
        VI v;
        for ( auto j : app[i] ) {
            if ( j>1 && a[j-1]!=i ) {
                x+=abs(a[j]-a[j-1]);
                v.PB(a[j-1]);
            }
            if ( j<m && a[j+1]!=i ) {
                x+=abs(a[j]-a[j+1]);
                v.PB(a[j+1]);
            }
        }
        sort(ALL(v));
        int mid=v[SZ(v)/2];
        LL y=0;
        FOR(it,v) y+=abs(*it-mid);
        ans=min(ans,w-x+y);
    }
    cout<<ans<<endl;
    return 0;
}