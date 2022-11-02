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

int main() {
    int n,l,r,x,c[15];
    RI(n,l,r,x);
    REP(i,n) RI(c[i]);
    int ans=0;
    REP(i,1<<n) {
        VI v;
        REP(j,n) if ( (i>>j)&1 ) v.PB(c[j]);
        sort(ALL(v));
        int s=0;
        for ( int j:v ) s+=j;
        if ( SZ(v)>=2 && s>=l && s<=r && v.back()-v[0]>=x ) ans++;
    }
    printf("%d\n",ans);
    return 0;
}