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

const int N=1e5+10;
int n,m;
char a[N],b[N],c[N];

char f( char x, char y ) {
    REP1(i,'a','z') if ( x!=i && y!=i ) return i;
    assert(0);
}

int main() {
    RI(n,m);
    scanf("%s%s",a,b);
    int da=0,db=0;
    REP(i,n) {
        if ( a[i]==b[i] ) c[i]=a[i];
        else {
            if ( da<db ) c[i]=b[i],da++;
            else c[i]=a[i],db++;
        }
    }
    if ( da>m || db>m ) {
        puts("-1");
        return 0;
    }
    REP(i,n) if ( da<m && db<m && a[i]==b[i] ) {
        c[i]=f(a[i],b[i]);
        da++;
        db++;
    }
    REP(i,n) if ( da<m && c[i]==a[i] && c[i]!=b[i] ) {
        c[i]=f(a[i],b[i]);
        da++;
    }
    REP(i,n) if ( db<m && c[i]==b[i] && c[i]!=a[i] ) {
        c[i]=f(a[i],b[i]);
        db++;
    }
    if ( da==m && db==m ) puts(c);
    else puts("-1");
    return 0;
}