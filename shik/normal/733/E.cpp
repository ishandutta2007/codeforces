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
} while (0)

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
template<typename T, size_t N>
ostream& operator <<( ostream &s, const array<T,N> &c ) { return _out(s,ALL(c)); }
template<typename T>
ostream& operator <<( ostream &s, const set<T> &c ) { return _out(s,ALL(c)); }
template<typename A, typename B>
ostream& operator <<( ostream &s, const map<A,B> &c ) { return _out(s,ALL(c)); }
#else
#define dump(...)
#endif

template<typename T>
void _R( T &x ) { cin>>x; }
void _R( int &x ) { scanf("%d",&x); }
void _R( long long &x ) { scanf("%" PRId64,&x); }
void _R( double &x ) { scanf("%lf",&x); }
void _R( char &x ) { scanf(" %c",&x); }
void _R( char *x ) { scanf("%s",x); }

void R() {}
template<typename T, typename... U>
void R( T& head, U&... tail ) {
    _R(head);
    R(tail...);
}

template<typename T>
void _W( const T &x ) { cout<<x; }
void _W( const int &x ) { printf("%d",x); }
template<typename T>
void _W( const vector<T> &x ) {
    for ( auto i=x.cbegin(); i!=x.cend(); i++ ) {
        if ( i!=x.cbegin() ) putchar(' ');
        _W(*i);
    }
}

void W() {}
template<typename T, typename... U>
void W( const T& head, const U&... tail ) {
    _W(head);
    putchar(sizeof...(tail)?' ':'\n');
    W(tail...);
}

#ifdef SHIK
#define FILEIO(...)
#else
#define FILEIO(name) do {\
    freopen(name ".in","r",stdin); \
    freopen(name ".out","w",stdout); \
} while (0)
#endif

// }}}

const int N=1e6+10;

int n;
char s[N];

void print( char *d, int x ) {
    REP1(i,1,n) {
        if ( i==x ) printf("%s","\e[1;31m");
        putchar(d[i]);
        if ( i==x ) printf("%s","\e[0m");
    }
    puts("");
}

int sim( int x ) {
    dump(x);
    static char d[N];
    REP1(i,1,n) d[i]=(s[i]=='U'?'>':'<');
    int ans=0;
    while ( x>=1 && x<=n ) {
        print(d,x);
        char dd=d[x];
        d[x]=(d[x]=='>' ? '<' : '>');
        if ( dd=='<' ) x--;
        else x++;
    }
    return ans;
}

void slow() {
    REP1(i,1,n) sim(i);
}

void solve( LL ans[] ) {
    int nl=0,nr=0,x=1;
    LL sl=0,sr=0;
    deque<int> ql,qr;
    REP1(i,1,n) {
        if ( s[i]=='U' ) {
            nl++;
            sl+=i;
            ql.push_back(i);
        }
        
        if ( s[i]=='U' ) {
            while ( x<=n && nr<nl ) {
                while ( x<=n && s[x]!='D' ) x++;
                if ( x<=n ) {
                    nr++;
                    sr+=x;
                    qr.push_back(x);
                    x++;
                }
            }
            if ( nr>=nl ) {
                LL tl=0,tr=0;
                // REP(j,nl) tl+=2*ql[j];
                tl+=2*sl;
                tl-=ql.back();
                // REP(j,nl) tr+=2*qr[j];
                tr+=2*sr;
                ans[i]=tr-tl;
            } else {
                return;
            }
        } else {
            while ( x<=n && nr<nl+1 ) {
                while ( x<=n && s[x]!='D' ) x++;
                if ( x<=n ) {
                    nr++;
                    sr+=x;
                    qr.push_back(x);
                    x++;
                }
            }
            if ( nr>=nl+1 ) {
                LL tl=0,tr=0;
                // REP(j,nl) tl+=2*ql[j];
                tl+=2*sl;
                // REP(j,nl+1) tr+=2*qr[j];
                tr+=2*sr;
                tr-=qr.front();
                ans[i]=tr-tl;
            } else {
                return;
            }
        }

        if ( s[i]=='D' ) {
            nr--;
            sr-=qr.front();
            qr.pop_front();
        }
    }
}

LL ans1[N],ans2[N],ans[N];
int main() {
    R(n);
    scanf("%s",s+1);
    // slow();
    solve(ans1);
    reverse(s+1,s+n+1);
    REP1(i,1,n) s[i]=(s[i]=='U' ? 'D' : 'U');
    solve(ans2);
    REP1(i,1,n) {
        LL a1=ans1[i];
        LL a2=ans2[n-i+1];
        assert(!!a1 ^ !!a2);
        ans[i]=a1+a2;
    }
    REP1(i,1,n) printf("%lld%c",ans[i],i==n?'\n':' ');
    return 0;
}