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

const int N=1e5+10;

LL extgcd( LL a, LL b, LL &x, LL &y ) {
    if ( b==0 ) {
        x=1;
        y=0;
        return a;
    }
    LL g=extgcd(b,a%b,y,x);
    y-=a/b*x;
    return g;
}

LL inv( LL x, LL m ) {
    LL a,b;
    extgcd(x,m,a,b);
    return (a%m+m)%m;
}

struct E {
    int to,d;
};

int n;
LL m,inv10,pw[N],ipw[N];
vector<E> e[N];

int sz[N];
void make_tree( int p, int f ) {
    if ( p!=0 ) {
        auto it=find_if(ALL(e[p]),[&f](const E &x) { return x.to==f; });
        assert(it!=e[p].end());
        e[p].erase(it);
    }
    sz[p]=1;
    for ( auto &i:e[p] ) {
        make_tree(i.to,p);
        sz[p]+=sz[i.to];
    }
    sort(ALL(e[p]),[](const E &x, const E &y) { return sz[x.to]>sz[y.to]; });
}

inline int pw10( int x ) {
    return x>=0?pw[x]:ipw[-x];
}

struct P {
    int a;
    LL b;
    map<int,int> mp;
    P():a(0),b(0) {
    }
    void append( LL x ) {
        a++;
        b=(b*10+x)%m;
    }
    void prepend( LL x ) {
        x%=m;
        a--;
        b=(b-x+m)*inv10%m;
    }
    LL unfix( LL x ) const {
        x-=b;
        if ( x<0 ) x+=m;
        x=x*pw10(-a)%m;
        return x;
    }
    void ins( LL x ) {
        mp[unfix(x)]++;
    }
    int ask( LL x ) const {
        auto it=mp.find(unfix(x));
        return it==mp.end() ? 0 : it->second;
    }
    LL fix( LL x ) const {
        return (x*pw10(a)+b)%m;
    }
    void merge( const P &p ) {
        for ( auto &i:p.mp ) {
            mp[unfix(p.fix(i.first))]+=i.second;
        }
    }
    void show() const {
        dump(a,b);
        for ( auto i:mp ) {
            dump(i.first,fix(i.first),i.second);
        }
    }
};

struct Q {
    P l,r;
    Q() {
    }
    void merge( const Q &q ) {
        l.merge(q.l);
        r.merge(q.r);
    }
    void ins( LL x ) {
        l.ins(x);
        r.ins(x);
    }
    int ask( LL x ) {
        return l.ask(x) + r.ask(x);
    }
    void show() const {
        l.show();
        r.show();
    }
};

LL calc_lr( const P &l, const P &r ) {
    if ( SZ(l.mp)>SZ(r.mp) ) return calc_lr(r,l);
    LL ans=0;
    for ( auto &i:l.mp ) {
        LL x=l.fix(i.first);
        ans+=1LL*i.second*r.ask(x);
    }
    return ans;
}

LL calc( const Q &a, const Q &b ) {
    LL ans=0;
    ans+=calc_lr(a.l,b.r);
    ans+=calc_lr(b.l,a.r);
    return ans;
}

LL ans;
Q* q[N];
void go( int p ) {
    for ( auto &i:e[p] ) {
        go(i.to);
        q[i.to]->l.append(i.d);
        q[i.to]->r.prepend(i.d);
        ans+=q[i.to]->ask(0);
        // dump(p,i.to,ans);
        // q[i.to]->show();
        if ( !q[p] ) q[p]=q[i.to];
        else {
            ans+=calc(*q[p],*q[i.to]);
            q[p]->merge(*q[i.to]);
            // dump(p);
            // q[p]->show();
        }
    }
    if ( !q[p] ) q[p]=new Q();
    q[p]->ins(0);
    // dump(p,ans);
    // q[p]->show();
}

int main() {
    R(n,m);
    if ( m==1 ) {
        ans=1LL*n*(n-1);
        W(ans);
        return 0;
    }
    REP(i,n-1) {
        int a,b,c;
        R(a,b,c);
        e[a].PB(E{b,c});
        e[b].PB(E{a,c});
    }
    inv10=inv(10%m,m);
    dump(inv10);
    assert(inv10 * 10 % m == 1);
    pw[0]=ipw[0]=1;
    REP(i,N-1) pw[i+1]=pw[i]*10%m;
    REP(i,N-1) ipw[i+1]=ipw[i]*inv10%m;
    make_tree(0,-1);
    go(0);
    W(ans);
    return 0;
}