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

struct StrHash {
    const static int P=100;
    const static int N=1e5+10;
    constexpr static int MOD[]={
        1000000123,
        1000001011,
        // 1000009999
    };
    const static int N_MOD=sizeof(MOD)/sizeof(MOD[0]);
    struct PowTable {
        int64_t dat[N][N_MOD];
        PowTable() {
            for ( int i=0; i<N_MOD; i++ ) dat[0][i]=1;
            for ( int i=1; i<N; i++ ) for ( int j=0; j<N_MOD; j++ ) dat[i][j]=dat[i-1][j]*P%MOD[j];
        }
        int64_t* operator[]( int i ) {
            return dat[i];
        }
    };
    static PowTable pw;
    int len;
    array<int64_t,N_MOD> val;
    StrHash( const char *s="" ) {
        len=0;
        val.fill(0);
        while ( *s ) (*this)+=*s;
    }
    StrHash( int x ) {
        len=1;
        for ( int i=0; i<N_MOD; i++ ) val[i]=x%MOD[i];
    }
    StrHash( const string &s ):StrHash(s.data()) {}
    bool operator ==( StrHash &o ) {
        return len==o.len && val==o.val;
    }
    int64_t& operator []( int i ) {
        return val[i];
    }
    int64_t operator []( int i ) const {
        return val[i];
    }
    StrHash operator +( const StrHash &o ) const {
        StrHash s;
        s.len=len+o.len;
        for ( int i=0; i<N_MOD; i++ ) s[i]=(val[i]*pw[o.len][i]+o[i])%MOD[i];
        return s;
    }
    void operator +=( const StrHash &o ) {
        len+=o.len;
        for ( int i=0; i<N_MOD; i++ ) val[i]=(val[i]*pw[o.len][i]+o[i])%MOD[i];
    }
    StrHash operator +( int x ) {
        StrHash s;
        s.len=len+1;
        for ( int i=0; i<N_MOD; i++ ) s[i]=(val[i]*P+x)%MOD[i];
        return s;
    }
    void operator +=( int x ) {
        len++;
        for ( int i=0; i<N_MOD; i++ ) val[i]=(val[i]*P+x)%MOD[i];
    }
};
StrHash::PowTable StrHash::pw;
constexpr int StrHash::MOD[];

typedef StrHash H;
const int N=1e5+10;
H tbl[10][N];

struct Seg {
    int cov[4*N];
    H h[4*N];
    H get_h( int id, int l, int r ) {
        if ( cov[id]==-1 ) return h[id];
        else return tbl[cov[id]][r-l+1];
    }
    void push( int id ) {
        int &c=cov[id];
        if ( c==-1 ) return;
        cov[id*2]=cov[id*2+1]=c;
        c=-1;
    }
    void pull( int id, int l, int m, int r ) {
        h[id]=get_h(id*2,l,m)+get_h(id*2+1,m+1,r);
    }
    void init( int id, int l, int r, int *a ) {
        cov[id]=-1;
        if ( l==r ) {
            h[id]=H(a[l]+1);
            return;
        }
        int m=(l+r)/2;
        init(id*2,l,m,a);
        init(id*2+1,m+1,r,a);
        pull(id,l,m,r);
    }
    H ask( int id, int l, int r, int ql, int qr ) {
        // dump(id,l,r,ql,qr);
        if ( ql<=l && r<=qr ) return get_h(id,l,r);
        int m=(l+r)/2;
        push(id);
        H ret;
        if ( ql<=m ) ret+=ask(id*2,l,m,ql,qr);
        if ( qr>m ) ret+=ask(id*2+1,m+1,r,ql,qr);
        pull(id,l,m,r);
        return ret;
    }
    void set( int id, int l, int r, int ql, int qr, int qc ) {
        if ( ql<=l && r<=qr ) {
            cov[id]=qc;
            return;
        }
        push(id);
        int m=(l+r)/2;
        if ( ql<=m ) set(id*2,l,m,ql,qr,qc);
        if ( qr>m ) set(id*2+1,m+1,r,ql,qr,qc);
        pull(id,l,m,r);
    }
} seg;

int n,q1,q2,a[N];
int main() {
    RI(n,q1,q2);
    REP1(i,1,n) scanf("%1d",a+i);
    REP(i,10) REP(j,n) tbl[i][j+1]=tbl[i][j]+(i+1);
    seg.init(1,1,n,a);
    REP(i,q1+q2) {
        int op,l,r,c;
        RI(op,l,r,c);
        if ( op==1 ) seg.set(1,1,n,l,r,c);
        else {
            if ( c==r-l+1 ) {
                puts("YES");
                continue;
            }
            auto h1=seg.ask(1,1,n,l,r-c);
            auto h2=seg.ask(1,1,n,l+c,r);
            puts(h1==h2?"YES":"NO");
        }
    }
    return 0;
}