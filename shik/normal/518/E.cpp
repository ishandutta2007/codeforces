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

inline void chkmax( int &a, int b ) {
    if ( b>a ) a=b;
}

inline void chkmin( int &a, int b ) {
    if ( b<a ) a=b;
}

#define N 100010
const LL INF=1e16;
const int Q=2e9+514;

LL eval( VI &a, int l, int r ) {
    REP1(i,l+1,r) if ( a[i]<=a[i-1] ) return INF;
    LL s=0;
    REP1(i,l+1,r-1) s+=abs(a[i]);
    return s;
}

void solve( VI &a ) {
    int n=SZ(a);
    int l=0;
    REP1(i,1,n-1) if ( a[i]!=Q ) {
        int r=i;
        LL c1,c2,c3;
        for ( int j=r-1; j>l; j-- ) a[j]=a[j+1]-1;
        c1=eval(a,l,r);
        for ( int j=l+1; j<r; j++ ) a[j]=a[j-1]+1;
        c2=eval(a,l,r);
        int mid=(l+r)/2;
        for ( int j=l+1; j<r; j++ ) a[j]=j-mid;
        c3=eval(a,l,r);
        LL mc=min(c1,min(c2,c3));
        if ( c1==mc ) {
            for ( int j=r-1; j>l; j-- ) a[j]=a[j+1]-1;
        } else if ( c2==mc ) {
            for ( int j=l+1; j<r; j++ ) a[j]=a[j-1]+1;
        }
        l=r;
    }
}

int n,k,a[N];
int main() {
    RI(n,k);
    REP1(i,1,n) {
        char s[20];
        scanf("%s",s);
        if ( s[0]=='?' ) a[i]=Q;
        else a[i]=atoi(s);
    }
    REP1(i,1,k) {
        VI v;
        v.PB(-2e9);
        for ( int j=i; j<=n; j+=k ) v.PB(a[j]);
        v.PB(+2e9);
        solve(v);
        REP1(j,1,SZ(v)-2) a[i+(j-1)*k]=v[j];
    }
    bool good=1;
    REP1(i,k+1,n) if ( a[i]<=a[i-k] ) good=0;
    if ( !good ) puts("Incorrect sequence");
    else {
        REP1(i,1,n) printf("%d%c",a[i],i==n?'\n':' ');
    }
    return 0;
}