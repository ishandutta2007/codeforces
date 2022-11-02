// {{{ by shik
// #include <stdio.h>
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x),end(x)
#define RALL(x) rbegin(x),rend(x)
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define FOR(it,c) for ( auto it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef int64_t LL;
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
void _R( int64_t &x ) { scanf("%" PRId64,&x); }
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
    v.resize(unique(ALL(v))-v.begin());
}

template<typename T> using MaxHeap = priority_queue<T>;
template<typename T> using MinHeap = priority_queue<T,vector<T>,greater<T>>;

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
int n,m,deg[N];
VI e[N];

int cc,grp[N],vis[N],fa[N],dep[N],sol[N];
void cyc( int p, int q ) {
    for ( int i=p; i!=q; i=fa[i] ) sol[i]=1;
    sol[q]=1;
}

bool dfs( int p, int f, int lv ) {
    grp[p]=cc;
    fa[p]=f;
    dep[p]=lv;
    vis[p]=1;
    for ( int i:e[p] ) if ( i!=f ) {
        if ( vis[i]==0 ) {
            if ( dfs(i,p,lv+1) ) return 1;
        } else if ( vis[i]==1 ) {
            cyc(p,i);
            return 1;
        }
    }
    vis[p]=2;
    return 0;
}

void path( int a, int b ) {
    while ( a!=b ) {
        sol[a]=sol[b]=2;
        if ( dep[a]>dep[b] ) a=fa[a];
        else b=fa[b];
    }
    sol[a]=2;
}

bool cmp_deg( int a, int b ) {
    return deg[a]>deg[b];
}

bool cmp_sz( const VI &a, const VI &b ) {
    return SZ(a)>SZ(b);
}

VI cd[N];
bool solve() {
    REP1(i,1,n) deg[i]=SZ(e[i]);
    REP1(i,1,n) sort(ALL(e[i]),cmp_deg);
    REP1(i,1,n) vis[i]=sol[i]=0;
    cc=0;
    REP1(i,1,n) if ( !vis[i] ) {
        cc++;
        if ( dfs(i,0,1) ) return 1;
    }
    REP1(i,1,n) if ( deg[i]>=4 ) {
        sol[i]=2;
        REP(j,4) sol[e[i][j]]=1;
        return 1;
    }
    REP1(i,1,cc) cd[i].clear();
    REP1(i,1,n) cd[grp[i]].PB(i);
    REP1(i,1,cc) {
        auto &v=cd[i];
        sort(ALL(v),cmp_deg);
        if ( SZ(v)<2 || deg[v[1]]<3 ) continue;
        for ( int j:e[v[0]] ) sol[j]=1;
        for ( int j:e[v[1]] ) sol[j]=1;
        path(v[0],v[1]);
        return 1;
    }
    REP1(i,1,n) if ( deg[i]>=3 ) {
        vector<VI> chs;
        for ( int j:e[i] ) {
            VI ch;
            int pre=i,pos=j;
            while ( deg[pos]==2 ) {
                ch.PB(pos);
                int npos=pre^e[pos][0]^e[pos][1];
                pre=pos;
                pos=npos;
            }
            ch.PB(pos);
            chs.PB(ch);
        }
        sort(ALL(chs),cmp_sz);
        dump(chs);
        if ( SZ(chs[0])>=5 && SZ(chs[1])>=2 ) {
            sol[i]=6;
            REP(j,5) sol[chs[0][j]]=5-j;
            REP(j,2) sol[chs[1][j]]=4-2*j;
            sol[chs[2][0]]=3;
            return 1;
        }
        if ( SZ(chs[0])>=3 && SZ(chs[1])>=3 ) {
            sol[i]=4;
            REP(j,3) sol[chs[0][j]]=sol[chs[1][j]]=3-j;
            sol[chs[2][0]]=2;
            return 1;
        }
        if ( SZ(chs[2])>=2 ) {
            sol[i]=3;
            REP(j,3) REP(k,2) sol[chs[j][k]]=2-k;
            return 1;
        }
    }
    return 0;
}

int main() {
    int t;
    R(t);
    while ( t-- ) {
        R(n,m);
        REP1(i,1,n) e[i].clear();
        REP(i,m) {
            int a,b;
            R(a,b);
            e[a].PB(b);
            e[b].PB(a);
        }
        if ( solve() ) {
            int s=0;
            REP1(i,1,n) s+=sol[i];
            assert(s!=0);
            W("YES");
            W(VI(sol+1,sol+n+1));
        } else {
            W("NO");
        }
    }
    return 0;
}