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

void RI() {}

template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}

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

#define dump(...) _dump(#__VA_ARGS__, __VA_ARGS__);

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

// }}}

const int N=2e5+10;
const int M=5e5+10;
int pc[M],mu[M],ps[M],pn;
VI fac[M];
void predo() {
    for ( int i=2; i<M; i++ ) if ( !pc[i] )
        for ( int j=i; j<M; j+=i ) pc[j]++;
    for ( int i=1; i<M; i++ ) mu[i]=(pc[i]%2==0?1:-1);
    for ( int i=2; i*i<M; i++ ) if ( pc[i]==1 )
        for ( int j=i*i; j<M; j+=i*i ) mu[j]=0;
    for ( int i=1; i<M; i++ ) if ( mu[i] ) ps[pn++]=i;
}

int n,q,a[N],c[M];
bool in[N],has[M];

LL ans;
void add( int x ) {
    for ( int i:fac[x] ) ans+=mu[i]*c[i]++;
}

void del( int x ) {
    for ( int i:fac[x] ) ans-=mu[i]*--c[i];
}

int main() {
    predo();
    RI(n,q);
    REP1(i,1,n) RI(a[i]);
    REP1(i,1,n) has[a[i]]=1;
    REP(i,pn) for ( int j=ps[i]; j<M; j+=ps[i] ) if ( has[j] ) fac[j].PB(ps[i]);
    while ( q-- ) {
        int xi;
        RI(xi);
        int x=a[xi];
        if ( in[xi] ) {
            del(x);
            in[xi]=0;
        } else {
            add(x);
            in[xi]=1;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}