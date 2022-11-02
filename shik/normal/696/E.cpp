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
const int SN=4*N;
const LL INF=1e15;

VI e[N];

int sz[N];
int get_sz( int p, int f ) {
    sz[p]=1;
    FOR(it,e[p]) if ( *it!=f ) sz[p]+=get_sz(*it,p);
    return sz[p];
}

int st[N],ed[N],pid,fa[N],dep[N],root[N];
void dfs( int p, int f, int lv ) {
    st[p]=++pid;
    fa[p]=f;
    dep[p]=lv;
    int w=0;
    FOR(it,e[p]) if ( *it!=f && (!w || sz[*it]>sz[w]) ) w=*it;
    if ( w ) {
        root[w]=root[p];
        dfs(w,p,lv+1);
        FOR(it,e[p]) if ( *it!=f && *it!=w ) {
            root[*it]=*it;
            dfs(*it,p,lv+1);
        }
    }
    ed[p]=pid;
}

vector<PII> get_path( int a, int b ) {
   vector<PII> v;
   while ( root[a]!=root[b] ) {
       if ( dep[root[a]]>dep[root[b]] ) swap(a,b);
       v.PB(MP(st[root[b]],st[b]));
       b=fa[root[b]];
   }
   if ( dep[a]>dep[b] ) swap(a,b);
   v.PB(MP(st[a],st[b]));
   return v;
}

struct Seg {
    LL add[SN];
    pair<LL,int> mi[SN];
    void init( int id, int l, int r ) {
        add[id]=0;
        mi[id]=MP(INF,-1);
        if ( l==r ) return;
        int m=(l+r)/2;
        init(id*2,l,m);
        init(id*2+1,m+1,r);
    }
    void push( int id ) {
        add[id*2]+=add[id];
        add[id*2+1]+=add[id];
        add[id]=0;
    }
    pair<LL,int> get_mi( int id ) {
        auto x=mi[id];
        x.first+=add[id];
        return x;
    }
    void pull( int id ) {
        mi[id]=min(get_mi(id*2),get_mi(id*2+1));
    }
    void ins( int id, int l, int r, int ql, int qr, int qv ) {
        if ( ql<=l && r<=qr ) {
            add[id]+=qv;
            return;
        }
        push(id);
        int m=(l+r)/2;
        if ( ql<=m ) ins(id*2,l,m,ql,qr,qv);
        if ( qr>m ) ins(id*2+1,m+1,r,ql,qr,qv);
        pull(id);
    }
    void zet( int id, int l, int r, int qx, pair<LL,int> qv ) {
        if ( l==r ) {
            add[id]=0;
            mi[id]=qv;
            return;
        }
        push(id);
        int m=(l+r)/2;
        if ( qx<=m ) zet(id*2,l,m,qx,qv);
        else zet(id*2+1,m+1,r,qx,qv);
        pull(id);
        dump(id,l,r,qx,qv,add[id],mi[id]);
    }
    pair<LL,int> ask( int id, int l, int r, int ql, int qr ) {
        if ( ql<=l && r<=qr ) return get_mi(id);
        push(id);
        int m=(l+r)/2;
        pair<LL,int> ret=MP(INF,-2);
        if ( ql<=m ) ret=min(ret,ask(id*2,l,m,ql,qr));
        if ( qr>m ) ret=min(ret,ask(id*2+1,m+1,r,ql,qr));
        pull(id);
        return ret;
    }
} seg;

int n,m,q,c[N];
VI vg[N];
int main() {
    R(n,m,q);
    REP(i,n-1) {
        int a,b;
        R(a,b);
        e[a].PB(b);
        e[b].PB(a);
    }
    REP1(i,1,m) R(c[i]);
    REP1(i,1,m) vg[c[i]].PB(i);
    REP1(i,1,n) reverse(ALL(vg[i]));
    get_sz(1,0);
    root[1]=1;
    dfs(1,0,1);
    seg.init(1,1,n);
    REP1(i,1,n) if ( !vg[i].empty() ) {
        dump(i,st[i],vg[i]);
        seg.zet(1,1,n,st[i],MP((LL)vg[i].back(),i));
    }
    while ( q-- ) {
        int op;
        R(op);
        dump(op);
        if ( op==1 ) {
            int a,b,k;
            R(a,b,k);
            auto p=get_path(a,b);
            VI sol;
            while ( k-- ) {
                bool found=0;
                pair<LL,int> mi=MP(INF,-3);
                for ( auto i:p ) {
                    int l=i.first;
                    int r=i.second;
                    auto x=seg.ask(1,1,n,l,r);
                    if ( x.second<0 ) continue;
                    found=1;
                    mi=min(mi,x);
                }
                if ( !found ) break;
                int cc=mi.second;
                sol.PB(vg[cc].back());
                vg[cc].pop_back();
                dump(mi,cc,vg[cc],st[cc]);

                if ( vg[cc].empty() ) {
                    seg.zet(1,1,n,st[cc],MP(INF,-4));
                } else {
                    seg.zet(1,1,n,st[cc],MP(vg[cc].back()+mi.first-sol.back(),cc));
                }
            }
            W(SZ(sol),sol);
        } else if ( op==2 ) {
            int v,k;
            R(v,k);
            seg.ins(1,1,n,st[v],ed[v],k);
        } else assert(0);
    }
    return 0;
}