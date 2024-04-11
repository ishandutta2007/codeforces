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
const int MOD=1e9+7;

struct DJS {
    int fa[N];
    void init( int n ) {
        REP1(i,1,n) fa[i]=i;
    }
    int Find( int x ) {
        return x==fa[x]?x:fa[x]=Find(fa[x]);
    }
    void Union( int a, int b ) {
        fa[Find(a)]=Find(b);
    }
} djs;

int n,m,a[N],b[N],c[N],clr[N];
VI e[N];
void dfs( int p, int cc ) {
    clr[p]=cc;
    for ( int i:e[p] ) if ( !clr[i] ) dfs(i,3-cc);
}
int main() {
    RI(n,m);
    REP(i,m) RI(a[i],b[i],c[i]);
    djs.init(n);
    REP(i,m) if ( c[i]==1 ) djs.Union(a[i],b[i]);
    bool good=1;
    REP(i,m) if ( c[i]==0 && djs.Find(a[i])==djs.Find(b[i]) ) good=0;
    if ( !good ) return puts("0"),0;
    REP(i,m) if ( c[i]==0 ) {
        int x=djs.Find(a[i]);
        int y=djs.Find(b[i]);
        e[x].PB(y);
        e[y].PB(x);
    }
    REP1(i,1,n) if ( !clr[i] ) dfs(i,1);
    REP(i,m) if ( c[i]==0 && clr[djs.Find(a[i])]==clr[djs.Find(b[i])] ) good=0;
    if ( !good ) return puts("0"),0;
    REP(i,m) djs.Union(a[i],b[i]);
    int cnt=0;
    REP1(i,1,n) if ( djs.Find(i)==i ) cnt++;
    LL ans=1;
    REP(i,cnt-1) ans=ans*2%MOD;
    cout<<ans<<endl;
    return 0;
}