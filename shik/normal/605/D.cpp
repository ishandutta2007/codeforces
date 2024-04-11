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

// }}}

const int N=1e5+10;

struct BIT {
    vector<PII> dat[N];
    bool bye[N];
    void ins( int x, PII v ) {
        x++;
        for ( int i=x; i<N; i+=i&-i ) dat[i].PB(v);
    }
    void meow() {
        REP(i,N) sort(ALL(dat[i]),greater<PII>());
    }
    int ask( int x, int y ) {
        x++;
        for ( int i=x; i; i-=i&-i ) {
            while ( !dat[i].empty() && dat[i].back().first<=y ) {
                int id=dat[i].back().second;
                dat[i].pop_back();
                if ( bye[id] ) continue;
                bye[id]=1;
                return id;
            }
        }
        return 0;
    }
} bit;

LL my_rand() {
    LL r=0;
    REP(i,4) r=(r<<8)|(rand()%0xFF);
    return r;
}

struct P {
    int a,b,c,d;
    void read() {
        R(a,b,c,d);
    }
    void rnd() {
        a=my_rand()%1000000001;
        b=my_rand()%1000000001;
        c=my_rand()%1000000001;
        d=my_rand()%1000000001;
    }
} p[N];

int n;

void lshua() {
    static int lx[N],ly[N],nx,ny;
    lx[nx++]=0;
    ly[ny++]=0;
    REP1(i,1,n) {
        lx[nx++]=p[i].a;
        ly[ny++]=p[i].b;
    }
    sort(lx,lx+nx); nx=unique(lx,lx+nx)-lx;
    sort(ly,ly+ny); ny=unique(ly,ly+ny)-ly;
    REP1(i,1,n) {
        p[i].a=lower_bound(lx,lx+nx,p[i].a)-lx;
        p[i].b=lower_bound(ly,ly+ny,p[i].b)-ly;
        p[i].c=upper_bound(lx,lx+nx,p[i].c)-lx-1;
        p[i].d=upper_bound(ly,ly+ny,p[i].d)-ly-1;
    }
}

int dis[N],pre[N];
int main() {
    R(n);
    REP1(i,1,n) p[i].read();
    // n=100000;
    // REP1(i,1,n) p[i].rnd();
    // p[n/2].a=p[n/2].b=0;
    lshua();
    REP1(i,1,n) bit.ins(p[i].a,MP(p[i].b,i));
    bit.meow();
    queue<int> q;
    q.push(0);
    while ( !q.empty() ) {
        int u=q.front(); q.pop();
        int x=p[u].c;
        int y=p[u].d;
        while ( 1 ) {
            int id=bit.ask(x,y);
            if ( !id ) break;
            dis[id]=dis[u]+1;
            pre[id]=u;
            q.push(id);
        }
    }
    if ( !dis[n] ) {
        W(-1);
        return 0;
    }
    VI path;
    for ( int i=n; i; i=pre[i] ) path.PB(i);
    reverse(ALL(path));
    assert(dis[n]==SZ(path));
    W(dis[n]);
    W(path);
    return 0;
}