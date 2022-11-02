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

const int N=3010;
const int INF=1e8;

int n,m,d[N][N];
VI e[N];

void bfs( int st, int dis[N] ) {
    REP1(i,1,n) dis[i]=INF;
    static int q[N];
    int ql=0,qr=0;
    q[qr++]=st;
    dis[st]=0;
    while ( ql!=qr ) {
        int p=q[ql++];
        int nd=dis[p]+1;
        for ( int i:e[p] ) if ( nd<dis[i] ) {
            dis[i]=nd;
            q[qr++]=i;
        }
    }
    dump(st,VI(dis+1,dis+n+1));
}

int main() {
    RI(n,m);
    REP(i,m) {
        int a,b;
        RI(a,b);
        e[a].PB(b);
        e[b].PB(a);
    }
    int s1,t1,l1,s2,t2,l2;
    RI(s1,t1,l1,s2,t2,l2);
    REP1(i,1,n) bfs(i,d[i]);
    int ans=INF;
    dump(d[s1][t1],d[s2][t2]);
    if ( d[s1][t1]<=l1 && d[s2][t2]<=l2 ) ans=d[s1][t1]+d[s2][t2];
    REP1(i,1,n) REP1(j,1,n) {
        int d1=min(d[s1][i]+d[j][t1],d[t1][i]+d[j][s1])+d[i][j];
        int d2=min(d[s2][i]+d[j][t2],d[t2][i]+d[j][s2])+d[i][j];
        if ( d1<=l1 && d2<=l2 ) ans=min(ans,d1+d2-d[i][j]);
    }
    if ( ans==INF ) puts("-1");
    else printf("%d\n",m-ans);
    return 0;
}