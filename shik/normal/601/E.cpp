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

const int Q=40010;
const int C=1010;

struct Query {
    int op,v,w;
} q[Q];

int c;
void update( int v, int w, int dp[] ) {
    for ( int i=c; i>=w; i-- ) dp[i]=max(dp[i],dp[i-w]+v);
}

vector<PII> seg[4*Q];
void ins( int id, int l, int r, int ql, int qr, const PII &qp ) {
    if ( id==1 ) dump(id,l,r,ql,qr,qp);
    if ( ql<=l && r<=qr ) {
        seg[id].PB(qp);
        return;
    }
    int m=(l+r)/2;
    if ( ql<=m ) ins(id*2,l,m,ql,qr,qp);
    if ( qr>m ) ins(id*2+1,m+1,r,ql,qr,qp);
}

int dp[18][C],ans[Q];
void go( int id, int l, int r, int lv ) {
    if ( lv>0 ) memcpy(dp[lv],dp[lv-1],(c+1)*sizeof(int));
    for ( auto &i:seg[id] ) update(i.first,i.second,dp[lv]);
    if ( l==r ) {
        LL h=0;
        for ( int i=c; i>0; i-- ) h=(h*10000019+dp[lv][i])%1000000007;
        ans[l]=h;
        dump(l,VI(dp[lv]+1,dp[lv]+c+1),h);
        return;
    }
    int m=(l+r)/2;
    go(id*2,l,m,lv+1);
    go(id*2+1,m+1,r,lv+1);
}

int main() {
    int n;
    R(n,c);
    int qn=0;
    REP(i,n) {
        int v,w;
        R(v,w);
        q[qn++]={1,v,w};
    }
    R(n);
    REP(i,n) {
        int op;
        R(op);
        if ( op==1 ) {
            int v,w;
            R(v,w);
            q[qn++]={op,v,w};
        } else if ( op==2 ) {
            int x;
            R(x);
            q[qn++]={op,x,-1};
        } else if ( op==3 ) {
            q[qn++]={op,-1,-1};
        } else assert(0);
    }
    static int p1[Q],c2[Q];
    int m1=0,m2=0;
    REP(i,qn) {
        if ( q[i].op==1 ) p1[++m1]=i;
        if ( q[i].op==1 || q[i].op==2 ) m2++;
        c2[i]=m2;
    }
    REP(i,qn) if ( q[i].op==2 ) {
        auto &pre=q[p1[q[i].v]];
        ins(1,1,m2,c2[p1[q[i].v]],c2[i]-1,{pre.v,pre.w});
        p1[q[i].v]=-1;
    }
    REP1(i,1,m1) if ( p1[i]!=-1 ) ins(1,1,m2,c2[p1[i]],m2,{q[p1[i]].v,q[p1[i]].w});
    go(1,1,m2,0);
    REP(i,qn) if ( q[i].op==3 ) W(ans[c2[i]]);
    return 0;
}