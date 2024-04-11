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

inline int bit( int x, int i ) {
    return (x>>i)&1;
}

#define N 100010
int n,m,a[N],l[N],r[N],q[N];

bool solve( int bi ) {
    static int ci[N],co[N],s[N];
    REP1(i,1,n) ci[i]=co[i]=0;
    REP1(i,1,m) if ( bit(q[i],bi)==1 ) {
        ci[l[i]]++;
        co[r[i]]++;
    }
    int c=0;
    REP1(i,1,n) {
        c+=ci[i];
        s[i]=!!c;
        if ( s[i] ) a[i]|=1<<bi;
        c-=co[i];
    }
    REP1(i,1,n) s[i]+=s[i-1];
    REP1(i,1,m) if ( bit(q[i],bi)==0 && s[r[i]]-s[l[i]-1]==r[i]-l[i]+1 ) return 0;
    return 1;
}

int main() {
    RI(n,m);
    REP1(i,1,m) RI(l[i],r[i],q[i]);
    REP(i,30) if ( !solve(i) ) {
        puts("NO");
        return 0;
    }
    puts("YES");
    REP1(i,1,n) printf("%d%c",a[i],i==n?'\n':' ');
    return 0;
}