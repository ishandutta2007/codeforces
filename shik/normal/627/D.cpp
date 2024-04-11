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

const int N=2e5+10;
typedef pair<bool,int> T;

int n,k,a[N];
VI e[N];

void make_tree( int p, int f ) {
    if ( f ) e[p].erase(find(ALL(e[p]),f));
    for ( int i:e[p] ) make_tree(i,p);
}

bool good[N];
T dp[N];
T dfs1( int p ) {
    bool fi=1;
    int se=0,mx=0;
    for ( int i:e[p] ) {
        T t=dfs1(i);
        fi&=t.first;
        if ( t.first ) se+=t.second;
        else mx=max(mx,t.second);
    }
    se+=mx;
    if ( good[p] ) se++;
    else {
        fi=0;
        se=0;
    }
    return dp[p]=MP(fi,se);
}

int dfs2( int p, T ft ) {
    if ( !good[p] ) {
        int ans=0;
        for ( int i:e[p] ) {
            int now=dfs2(i,T(0,0));
            ans=max(ans,now);
        }
        return ans;
    }
    int me=dp[p].second;
    if ( ft.first ) {
        me+=ft.second;
    } else {
        int mx=0;
        for ( int i:e[p] ) if ( !dp[i].first && dp[i].second>mx ) mx=dp[i].second;
        if ( ft.second>mx ) me+=ft.second-mx;
    }
    int ans=me;
    int mx1=0,mx2=0;
    for ( int i:e[p] ) {
        if ( dp[i].first ) continue;
        if ( dp[i].second>=mx1 ) {
            mx2=mx1;
            mx1=dp[i].second;
        } else if ( dp[i].second>=mx2 ) {
            mx2=dp[i].second;
        }
    }
    if ( !ft.first ) {
        if ( ft.second>=mx1 ) {
            mx2=mx1;
            mx1=ft.second;
        } else if ( ft.second>=mx2 ) {
            mx2=ft.second;
        }
    }
    int zf=0;
    zf+=!ft.first;
    for ( int i:e[p] ) zf+=!dp[i].first;
    // dump(p,ft,me,mx1,mx2,zf);
    for ( int i:e[p] ) {
        T nft;
        nft.first=(zf-!dp[i].first==0);
        if ( dp[i].first ) {
            nft.second=me-dp[i].second;
        } else {
            if ( dp[i].second==mx1 ) {
                nft.second=me-mx1+mx2;
            } else {
                nft.second=me;
            }
        }
        int now=dfs2(i,nft);
        ans=max(ans,now);
    }
    return ans;
}

bool chk( int m ) {
    // dump(m);
    REP1(i,1,n) good[i]=(a[i]>=m);
    dfs1(1);
    // dump(m,vector<T>(dp+1,dp+n+1));
    int now=dfs2(1,T(1,0));
    // dump(m,now);
    return now>=k;
}

int main() {
    R(n,k);
    REP1(i,1,n) R(a[i]);
    REP(i,n-1) {
        int u,v;
        R(u,v);
        e[u].PB(v);
        e[v].PB(u);
    }
    make_tree(1,0);
    int l=1,r=1000000;
    while ( l!=r ) {
        int m=(l+r+1)/2;
        if ( chk(m) ) l=m;
        else r=m-1;
    }
    W(l);
    return 0;
}