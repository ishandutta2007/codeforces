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

template<typename T> inline bool chkmax(T &a, const T &b) { return b > a ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, true : false; }

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

int n,m,q;
VI e[N];

int cid[N],nc,dis[N];
void dfs( int p, int f, int d, int &mx, int &wh ) {
    cid[p]=nc;
    if ( d>mx ) mx=d,wh=p;
    chkmax(dis[p],d);
    for ( int i:e[p] ) if ( i!=f ) dfs(i,p,d+1,mx,wh);
}

VI cd[N],sd[N];
vector<double> ed[N];
void build( int p ) {
    dump(p);
    nc++;
    int mx1=-1,wh1=-1;
    dfs(p,0,0,mx1,wh1);
    int mx2=-1,wh2=-1;
    dfs(wh1,0,0,mx2,wh2);
    int mx3=-1,wh3=-1;
    dfs(wh2,0,0,mx3,wh3);
    assert(mx2==mx3);
    cd[nc].resize(mx2+1);
    sd[nc].resize(mx2+1);
    ed[nc].resize(mx2+1);
}

int main() {
    R(n,m,q);
    REP(i,m) {
        int a,b;
        R(a,b);
        e[a].PB(b);
        e[b].PB(a);
    }
    REP1(i,1,n) if ( !cid[i] ) build(i);
    REP1(i,1,n) cd[cid[i]][dis[i]]++;
    REP1(i,1,nc) {
        sd[i][0]=cd[i][0];
        REP1(j,1,SZ(sd[i])-1) sd[i][j]=cd[i][j]+sd[i][j-1];
        double s=0;
        for ( int j=SZ(ed[i])-1; j>=0; j-- ) {
            s+=1.0*j*cd[i][j];
            ed[i][j]=s;
        }
    }
    map<PII,double> memo;
    while ( q-- ) {
        int a,b;
        R(a,b);
        a=cid[a];
        b=cid[b];
        if ( a==b ) {
            W(-1);
            continue;
        }
        if ( MP(SZ(cd[a]),a)>MP(SZ(cd[b]),b) ) swap(a,b);
        auto k=MP(a,b);
        if ( memo.count(k) ) {
            printf("%.14f\n",memo[k]);
            continue;
        }
        int da=SZ(cd[a])-1;
        int db=SZ(cd[b])-1;
        int base=max(da,db);
        double ans=0;
        double tot=1.0*sd[a].back()*sd[b].back();
        REP1(i,0,da) {
            if ( i+1<=base ) {
                ans+=1.0*cd[a][i]*sd[b][min(base-(i+1),db)]*base;
            }
            int lo=max(base-i,0);
            if ( lo>db ) continue;
            // REP1(j,lo,db) {
                // int now=i+j+1;
                // ans+=1.0*cd[a][i]*cd[b][j]*now;
            // }
            double now=0;
            now+=(i+1.0)*(sd[b].back()-(lo==0 ? 0 : sd[b][lo-1]));
            now+=ed[b][lo];
            now*=cd[a][i];
            ans+=now;
        }
        ans/=tot;
        memo[k]=ans;
        printf("%.14f\n",ans);
    }
    return 0;
}