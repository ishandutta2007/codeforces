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
int n,a[N],b[N],m,c[N],d[N],k[N];
int s1[N],s2[N];

struct Cmp {
    bool operator()( int x, int y ) {
        return d[x]<d[y];
    }
};

int sol[N];
multiset<int,Cmp> s;

int main() {
    RI(n);
    REP1(i,1,n) RI(a[i],b[i]);
    RI(m);
    REP1(i,1,m) RI(c[i],d[i],k[i]);
    REP(i,n) s1[i]=i+1;
    sort(s1,s1+n,[](int x,int y){return a[x]<a[y];});
    REP(i,m) s2[i]=i+1;
    sort(s2,s2+m,[](int x,int y){return c[x]<c[y];});
    for ( int ii=0,jj=0; ii<n; ii++ ) {
        int i=s1[ii];
        while ( jj<m ) {
            int j=s2[jj];
            if ( c[j]>a[i] ) break;
            s.insert(j);
            jj++;
        }
        d[0]=b[i];
        auto it=s.lower_bound(0);
        if ( it==s.end() ) return puts("NO"),0;
        sol[i]=*it;
        if ( --k[*it]==0 ) s.erase(it);
    }
    puts("YES");
    REP1(i,1,n) printf("%d%c",sol[i],i==n?'\n':' ');
    return 0;
}