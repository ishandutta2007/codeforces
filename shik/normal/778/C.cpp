// {{{ by shik
// #include <stdio.h>
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
void _W( const long long &x ) { printf("%" PRId64,x); }
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

template<typename T> inline bool chkmax( T &a, const T &b ) { return b>a ? a=b,true : false; }
template<typename T> inline bool chkmin( T &a, const T &b ) { return b<a ? a=b,true : false; }
template<typename T, typename F>
inline void sort_uniq( vector<T> &v, F f ) {
    sort(ALL(v),f);
    v.resize(unqiue(ALL(v))-v.begin());
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

template<typename T>
struct SaveLoad {
    vector<pair<T*, T>> h;
    void zet(T& k, const T &v) {
        h.emplace_back(&k, k);
        k = v;
    }
    size_t save() { return h.size(); }
    void load(size_t sp) {
        while (h.size() != sp) {
            *h.back().first = h.back().second;
            h.pop_back();
        }
    }
};

struct GeneralSaveLoad {
    vector<pair<void*, string>> h;
    template<typename T>
    void zet(T& k, const T &v) {
        h.emplace_back(&k, string((char*)&k, (char*)&k + sizeof(T)));
        k = v;
    }
    size_t save() { return h.size(); }
    void load(size_t sp) {
        while (h.size() != sp) {
            memcpy(h.back().first, h.back().second.data(), h.back().second.size());
            h.pop_back();
        }
    }
} gsl;

// SaveLoad<int> h1;

// struct Trie;
// SaveLoad<Trie*> h2;

// size_t save() {
//     h1.save();
//     return h2.save();
// }

// void load(size_t sp) {
//     h1.load(sp);
//     h2.load(sp);
// }

struct Trie {
    int sz;
    Trie *ch[26];
    Trie():sz(1) { memset(ch,0,sizeof(ch)); }
};

struct E { int to,ch; };

const int N=3e5+10;

int n;
vector<E> e[N];

Trie *tr[N];
int sz[N],dep[N];
void dfs( int p, int lv ) {
    tr[p]=new Trie();
    sz[p]=1;
    dep[p]=lv;
    for ( auto i:e[p] ) {
        dfs(i.to,lv+1);
        tr[p]->sz+=tr[i.to]->sz;
        tr[p]->ch[i.ch]=tr[i.to];
        sz[p]+=sz[i.to];
    }
}

void add( Trie *t, int p ) {
    for ( auto i:e[p] ) {
        int z=t->sz;
        auto &c=t->ch[i.ch];
        if ( !c ) {
            gsl.zet(c,new Trie());
        } else {
            z-=c->sz;
        }
        add(c,i.to);
        gsl.zet(t->sz,z+c->sz);
    }
}

int del[N];
void go( int p ) {
    if ( e[p].empty() ) return;
    for ( auto i:e[p] ) go(i.to);
    auto t=tr[e[p].back().to];
    auto sp=gsl.save();
    REP(i,SZ(e[p])-1) add(t,e[p][i].to);
    del[dep[p]]+=sz[p]-t->sz;
    gsl.load(sp);
}

int main() {
    R(n);
    REP(i,n-1) {
        int a,b;
        char c;
        R(a,b,c);
        e[a].PB({b,c-'a'});
    }
    dfs(1,1);
    REP1(i,1,n) sort(ALL(e[i]),[&]( auto a, auto b ){ return sz[a.to]<sz[b.to]; });
    go(1);
    int mxd=*max_element(dep+1,dep+n+1);
    int w=max_element(del+1,del+mxd+1)-del;
    W(n-del[w]);
    W(w);
    return 0;
}