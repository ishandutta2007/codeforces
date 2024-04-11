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

#define N 1000010
int n,m,x[N];
int main() {
    RI(n,m);
    REP1(i,1,n) RI(x[i]);
    LL now=0;
    int ri=0,rn=0;
    for ( int i=n; i>=1; i-=m ) {
        now+=x[i]-x[1];
        ri=i;
        rn++;
    }
    int li=1,ln=1;
    LL ans=now;
    REP1(i,1,n-1) {
        if ( i==ri ) {
            ri+=m;
            rn--;
        }
        if ( i-li==m ) {
            li=i;
            ln++;
        }
        now-=1LL*rn*(x[i+1]-x[i]);
        now+=1LL*ln*(x[i+1]-x[i]);
        ans=min(ans,now);
    }
    cout<<2*ans<<endl;
    return 0;
}