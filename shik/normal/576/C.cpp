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

#ifdef SHIK
template<typename T>
void _dump( const char* s, T&& head ) { cerr<<s<<"="<<head<<endl; }

template<typename T, typename... Args>
void _dump( const char* s, T&& head, Args&&... tail ) {
    int c=0;
    while ( *s!=',' || c!=0 ) {
        if ( *s=='(' || *s=='[' || *s=='{' ) c++;
        if ( *s==')' || *s==']' || *s=='}' ) c--;
        cerr<<*s++;
    }
    cerr<<"="<<head<<", ";
    _dump(s+1,tail...);
}

#define dump(...) do { \
    fprintf(stderr, "%s:%d - ", __PRETTY_FUNCTION__, __LINE__); \
    _dump(#__VA_ARGS__, __VA_ARGS__); \
} while (0);

template<typename Iter>
ostream& _out( ostream &s, Iter b, Iter e ) {
    s<<"[";
    for ( auto it=b; it!=e; it++ ) s<<(it==b?"":" ")<<*it;
    s<<"]";
    return s;
}

template<typename A, typename B>
ostream& operator <<( ostream &s, const pair<A,B> &p ) { return s<<"("<<p.first<<","<<p.second<<")"; }
template<typename T>
ostream& operator <<( ostream &s, const vector<T> &c ) { return _out(s,ALL(c)); }
template<typename T>
ostream& operator <<( ostream &s, const set<T> &c ) { return _out(s,ALL(c)); }
template<typename A, typename B>
ostream& operator <<( ostream &s, const map<A,B> &c ) { return _out(s,ALL(c)); }
#else
#define dump(...)
#endif

void RI() {}

template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}
// }}}

const int N=1e6+10;
int n,x[N],y[N];
VI vx[N];

bool cmp_y( int a, int b ) {
    return y[a]<y[b];
}

int main() {
    RI(n);
    REP1(i,1,n) RI(x[i],y[i]);
    REP1(i,1,n) vx[x[i]].PB(i);
    VI sol;
    int lx=0;
    REP1(i,1,1000) {
        VI v;
        while ( lx<=i*1000 ) {
            for ( int j:vx[lx] ) v.PB(j);
            lx++;
        }
        sort(ALL(v),cmp_y);
        if ( i%2==0 ) reverse(ALL(v));
        for ( int j:v ) sol.PB(j);
    }
    assert(SZ(sol)==n);
    LL sd=0;
    REP(i,n-1) {
        sd+=abs(x[sol[i]]-x[sol[i+1]]);
        sd+=abs(y[sol[i]]-y[sol[i+1]]);
        assert(sd<=2500000000LL);
    }
    REP(i,n) printf("%d%c",sol[i],i+1==n?'\n':' ');
    return 0;
}