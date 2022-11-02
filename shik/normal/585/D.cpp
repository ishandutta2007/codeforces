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
template<typename T, size_t U>
ostream& operator <<( ostream &s, const array<T,U> &c ) { return _out(s,ALL(c)); }
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

const int N=30;
const int M=1600000;
const LL INF=1e15;

typedef pair<LL,LL> PLL;
typedef array<LL,3> P;
typedef pair<P,int> Q;

void build( int u, int v, P sp, int n, P p[N], int &m, Q q[M] ) {
    if ( u==n ) {
        q[m++]={sp,v};
        return;
    }
    REP(i,3) {
        REP(j,3) if ( i!=j ) sp[j]+=p[u][j];
        build(u+1,(v<<2)|i,sp,n,p,m,q);
        REP(j,3) if ( i!=j ) sp[j]-=p[u][j];
    }
}

vector<string> decode( int n, int x ) {
    vector<string> v;
    REP(i,n) {
        string s;
        int y=x&3;
        if ( y==0 ) s="MW";
        else if ( y==1 ) s="LW";
        else if ( y==2 ) s="LM";
        else assert(0);
        v.push_back(s);
        x>>=2;
    }
    reverse(ALL(v));
    return v;
}

P p[N],zero;
Q q1[M],q2[M];

int n;
int main() {
    RI(n);
    REP(i,n) REP(j,3) cin>>p[i][j];
    int n1=n/2,n2=n-n/2,m1=0,m2=0;
    zero.fill(0);
    build(0,0,zero,n1,p,m1,q1);
    build(0,0,zero,n2,p+n1,m2,q2);
    sort(q1,q1+m1);
    sort(q2,q2+m2);
    // dump(vector<Q>(q1,q1+m1));
    // dump(vector<Q>(q2,q2+m2));
    vector<pair<PLL,pair<LL,int>>> vmp;
    vmp.reserve(m2);
    REP(i,m2) {
        auto &q=q2[i].first;
        auto k=MP(q[0]-q[1],q[0]-q[2]);
        auto v=MP(q[0],q2[i].second);
        vmp.emplace_back(k,v);
    }
    sort(ALL(vmp));
    auto _vmp=vmp;
    vmp.clear();
    REP(i,m2) if ( i+1==m2 || _vmp[i].first!=_vmp[i+1].first ) vmp.push_back(vmp[i]);
    LL mx=-INF;
    PII sol;
    REP(i,m1) {
        auto &q=q1[i].first;
        auto k=MP(q[1]-q[0],q[2]-q[0]);
        auto it=lower_bound(ALL(vmp),MP(k,MP(-INF,0)));
        if ( it->first!=k ) continue;
        auto v=it->second;
        LL now=q[0]+v.first;
        if ( now>mx ) {
            // dump(now,q,v.first,v.second);
            mx=now;
            sol=MP(q1[i].second,v.second);
        }
    }
    if ( mx==-INF ) {
        puts("Impossible");
        return 0;
    }
    auto v1=decode(n1,sol.first);
    auto v2=decode(n2,sol.second);
    for ( auto s:v1 ) cout<<s<<endl;
    for ( auto s:v2 ) cout<<s<<endl;
    return 0;
}