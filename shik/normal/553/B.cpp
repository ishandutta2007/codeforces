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

#define N 55

int n;
LL k;

bool chk( int p[] ) {
    bool vis[N]={};
    vector<VI> vv;
    REP1(i,1,n) if ( !vis[i] ) {
        VI v;
        for ( int j=i; !vis[j]; j=p[j] ) {
            vis[j]=1;
            v.PB(j);
        }
        sort(ALL(v));
        reverse(ALL(v));
        vv.PB(v);
    }
    sort(ALL(vv));
    int q[N],m=0;
    for ( auto v:vv ) for ( int x:v ) q[++m]=x;
    REP1(i,1,n) if ( q[i]!=p[i] ) return 0;
    return 1;
}

void lasai() {
    int p[50],cnt=0;
    REP1(i,1,n) p[i]=i;
    do {
        if ( chk(p) ) {
            dump(VI(p+1,p+n+1));
            cnt++;
            if ( cnt==k ) {
                REP1(i,1,n) printf("%d%c",p[i],i==n?'\n':' ');
                return;
            }
        }
    } while ( next_permutation(p+1,p+n+1) );
}
LL fib[N]={1,1};
int main() {
    cin>>n>>k;
    // lasai();
    REP1(i,2,n) fib[i]=fib[i-1]+fib[i-2];
    int p[N],x=1;
    while ( x<=n ) {
        if ( k<=fib[n-x] ) {
            p[x]=x;
            x++;
        } else {
            assert(x+1<=n);
            k-=fib[n-x];
            p[x]=x+1;
            p[x+1]=x;
            x+=2;
        }
    }
    REP1(i,1,n) printf("%d%c",p[i],i==n?'\n':' ');
    return 0;
}