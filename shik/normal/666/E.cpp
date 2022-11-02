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

struct SA{
    static const int MXN = 600010;
    bool _t[MXN*2];
    int _s[MXN*2], _sa[MXN*2], _c[MXN*2], x[MXN], _p[MXN], _q[MXN*2], hei[MXN], r[MXN];
    int operator [] (int i){ return _sa[i]; }
    void build(int *s, int n, int m){
        memcpy(_s, s, sizeof(int) * n);
        sais(_s, _sa, _p, _q, _t, _c, n, m);
        mkhei(n);
    }
    void mkhei(int n){
        REP(i,n) r[_sa[i]] = i;
        hei[0] = 0;
        REP(i,n) if(r[i]) {
            int ans = i>0 ? max(hei[r[i-1]] - 1, 0) : 0;
            while(_s[i+ans] == _s[_sa[r[i]-1]+ans]) ans++;
            hei[r[i]] = ans;
        }
    }
    void sais(int *s, int *sa, int *p, int *q, bool *t, int *c, int n, int z){
        bool uniq = t[n-1] = true, neq;
        int nn = 0, nmxz = -1, *nsa = sa + n, *ns = s + n, lst = -1;
#define MS0(a,n) memset(a,0,n*sizeof(*a))
#define MAGIC(XD) MS0(sa, n); \
        memcpy(x, c, sizeof(int) * z); \
        XD; \
        memcpy(x + 1, c, sizeof(int) * (z - 1)); \
        REP(i,n) if(sa[i] && !t[sa[i]-1]) sa[x[s[sa[i]-1]]++] = sa[i]-1; \
        memcpy(x, c, sizeof(int) * z); \
        for(int i = n - 1; i >= 0; i--) if(sa[i] && t[sa[i]-1]) sa[--x[s[sa[i]-1]]] = sa[i]-1;
        MS0(c, z);
        REP(i,n) uniq &= ++c[s[i]] < 2;
        REP(i,z-1) c[i+1] += c[i];
        if (uniq) { REP(i,n) sa[--c[s[i]]] = i; return; }
        for(int i = n - 2; i >= 0; i--) t[i] = (s[i]==s[i+1] ? t[i+1] : s[i]<s[i+1]);
        MAGIC(REP1(i,1,n-1) if(t[i] && !t[i-1]) sa[--x[s[i]]]=p[q[i]=nn++]=i);
        REP(i, n) if (sa[i] && t[sa[i]] && !t[sa[i]-1]) {
            neq=lst<0||memcmp(s+sa[i],s+lst,(p[q[sa[i]]+1]-sa[i])*sizeof(int));
            ns[q[lst=sa[i]]]=nmxz+=neq;
        }
        sais(ns, nsa, p + nn, q + n, t + n, c + z, nn, nmxz + 1);
        MAGIC(for(int i = nn - 1; i >= 0; i--) sa[--x[s[p[nsa[i]]]]] = p[nsa[i]]);
    }
} sa;

const int N=5e5;
const int M=5e4+10;
const int Z=N+M+M;

struct Seg {
    PII *dat;
    void pull( int id ) {
        dat[id]=max(dat[id*2],dat[id*2+1]);
    }
    void init( int id, int l, int r ) {
        if ( l==r ) {
            dat[id]=MP(0,-l);
            return;
        }
        int m=(l+r)/2;
        init(id*2,l,m);
        init(id*2+1,m+1,r);
        pull(id);
    }
    void add( int id, int l, int r, int qx, int qv ) {
        if ( l==r ) {
            dat[id].first+=qv;
            return;
        }
        int m=(l+r)/2;
        if ( qx<=m ) add(id*2,l,m,qx,qv);
        else add(id*2+1,m+1,r,qx,qv);
        pull(id);
    }
    PII ask( int id, int l, int r, int ql, int qr ) {
        if ( ql<=l && r<=qr ) return dat[id];
        PII ans=MP(-1,-1);
        int m=(l+r)/2;
        if ( ql<=m ) ans=max(ans,ask(id*2,l,m,ql,qr));
        if ( qr>m ) ans=max(ans,ask(id*2+1,m+1,r,ql,qr));
        return ans;
    }
} seg;

int ttn,seq[M];
void add( int x ) {
    x=seq[x];
    seg.add(1,1,ttn,x,+1);
    dump(x,seg.ask(1,1,ttn,x,x));
}
void del( int x ) {
    x=seq[x];
    seg.add(1,1,ttn,x,-1);
    dump(x,seg.ask(1,1,ttn,x,x));
}

struct Q {
    int id,l,r,pl,pr;
} q[N];

inline bool operator <( const Q &a, const Q &b ) {
    return MP(a.pl/256,a.pr)<MP(b.pl/256,b.pr);
}

int n,m,l[N],qn;
char s[N],*t[M],_t[M+M];
int is[Z],who[Z],off[Z],rmq[20][Z],idx[Z],ans[M][2];

void show( int i ) {
    int w=who[sa[i]],o=off[sa[i]];
    if ( w==-2 ) dump(i,w,o,"$");
    else if ( w==-1 ) dump(i,w,o,s+off[sa[i]]);
    else dump(i,w,o,t[w]+off[sa[i]]);
}

int main() {
    R(s);
    n=strlen(s);
    R(m);
    t[0]=_t;
    REP(i,m) {
        R(t[i]);
        l[i]=strlen(t[i]);
        t[i+1]=t[i]+l[i]+1;
    }
    R(qn);
    REP(i,qn) {
        q[i].id=i;
        R(q[i].l,q[i].r,q[i].pl,q[i].pr);
    }
    int zz=128,zl=0;
    REP(i,n) {
        who[zl]=-1;
        off[zl]=i;
        is[zl++]=s[i];
    }
    who[zl]=-2;
    is[zl++]=zz++;
    REP(i,m) {
        REP(j,l[i]) {
            who[zl]=i;
            off[zl]=j;
            is[zl++]=t[i][j];
        }
        who[zl]=-2;
        is[zl++]=zz++;
    }
    who[zl]=-2;
    is[zl++]=0;
    sa.build(is,zl,zz);
    dump(VI(sa._sa,sa._sa+zl));
    dump(VI(sa.r,sa.r+zl));
    dump(VI(sa.hei,sa.hei+zl));
    // REP(i,zl) show(i);
	REP1(i,1,zl) rmq[0][i]=sa.hei[i];
    int lgn=__lg(zl);
    REP(i,lgn) {
        int li=1<<i;
        int ub=zl-li-li+1;
        REP1(j,1,ub) rmq[i+1][j]=min(rmq[i][j],rmq[i][j+li]);
    }
    int tn=0;
    REP(i,zl) {
        if ( who[sa[i]]>=0 ) {
            tn++;
            seq[tn]=who[sa[i]]+1;
        }
        idx[i]=tn;
    }
    dump(VI(seq+1,seq+tn+1));
    seg.dat=new PII[4*M];
    seg.init(1,1,m);
    ttn=m;
    // hei[i] = lcp(sa[i-1],sa[i])
    REP(qi,qn) {
        int pos=sa.r[q[qi].pl-1];
        int len=q[qi].pr-q[qi].pl+1;
        int lb=pos,rb=pos;
        for ( int i=lgn; i>=0; i-- ) if ( lb>=(1<<i) && rmq[i][lb-(1<<i)+1]>=len ) lb-=1<<i;
        for ( int i=lgn; i>=0; i-- ) if ( rb+1<zl && rmq[i][rb+1]>=len ) rb+=1<<i;
        dump(qi,lb,rb);
        show(lb); show(rb);
        q[qi].pl=(who[sa[lb]]>=0 ? idx[lb] : idx[lb] + 1);
        q[qi].pr=idx[rb];
        dump(qi,q[qi].pl,q[qi].pr);
    }
    sort(q,q+qn);
    int ql=1,qr=0;
    REP(i,qn) {
        while ( qr<q[i].pr ) add(++qr);
        while ( ql>q[i].pl ) add(--ql);
        while ( qr>q[i].pr ) del(qr--);
        while ( ql<q[i].pl ) del(ql++);
        auto p=seg.ask(1,1,m,q[i].l,q[i].r);
        dump(p);
        ans[q[i].id][0]=-p.second;
        ans[q[i].id][1]=p.first;
    }
    REP(i,qn) W(ans[i][0],ans[i][1]);
    return 0;
}