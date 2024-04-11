// {{{ by shik
#pragma GCC optimize("Ofast")
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
const int M=1e5+10;

struct Q {
    int id,l,r;
} q[M];

template<int K>
inline PII mo( const Q &a ) {
    int x=a.l/K;
    return MP(x,(x%2?+1:-1)*a.r);
}

template<int K>
bool cmp_mo( const Q &a, const Q &b ) {
    return mo<K>(a)<mo<K>(b);
}

int n,a[N],m;

int c[N],cc[N];
set<int> st;
void chg( int x, int v ) {
    if ( --cc[c[x]]==0 ) st.erase(c[x]);
    c[x]+=v;
    if ( cc[c[x]]++==0 ) st.insert(c[x]);
}

void ins( int x ) {
    chg(a[x],+1);
}

void del( int x ) {
    chg(a[x],-1);
}

int calc() {
    static PII v1[N],v2[N];
    int n1=0,n2=0,i1=0,i2=0;
    for ( int i:st ) v1[n1++]=MP(i,cc[i]);
    int s=0;
    while ( n1-i1>=2 || n2-i2>=2 || (i1==n1?0:v1[i1].second)+(i2==n2?0:v2[i2].second)>1 ) {
        if ( i1!=n1 && (i2==n2 || v1[i1]<v2[i2]) ) {
            int x=v1[i1].first;
            int y=v1[i1].second;
            i1++;
            if ( y>=2 ) {
                s+=2*x*(y/2);
                v2[n2++]=MP(2*x,y/2);
                y%=2;
            }
            if ( y==1 ) {
                if ( i1!=n1 && (i2==n2 || v1[i1]<v2[i2]) ) {
                    s+=x+v1[i1].first;
                    v2[n2++]=MP(x+v1[i1].first,1);
                    if ( --v1[i1].second==0 ) i1++;
                } else {
                    s+=x+v2[i2].first;
                    v2[n2++]=MP(x+v2[i2].first,1);
                    if ( --v2[i2].second==0 ) i2++;
                }
            }
        } else {
            int x=v2[i2].first;
            int y=v2[i2].second;
            i2++;
            if ( y>=2 ) {
                s+=2*x*(y/2);
                v2[n2++]=MP(2*x,y/2);
                y%=2;
            }
            if ( y==1 ) {
                if ( i1!=n1 && (i2==n2 || v1[i1]<v2[i2]) ) {
                    s+=x+v1[i1].first;
                    v2[n2++]=MP(x+v1[i1].first,1);
                    if ( --v1[i1].second==0 ) i1++;
                } else {
                    s+=x+v2[i2].first;
                    v2[n2++]=MP(x+v2[i2].first,1);
                    if ( --v2[i2].second==0 ) i2++;
                }
            }
        }
    }
    return s;
}

int sol[M];
int main() {
    R(n);
    REP1(i,1,n) R(a[i]);
    R(m);
    REP(i,m) {
        q[i].id=i;
        R(q[i].l,q[i].r);
    }
    sort(q,q+m,cmp_mo<300>);
    int l=1,r=0;
    REP(i,m) {
        int ql=q[i].l,qr=q[i].r;
        while ( l>ql ) ins(--l);
        while ( r<qr ) ins(++r);
        while ( l<ql ) del(l++);
        while ( r>qr ) del(r--);
        sol[q[i].id]=calc();
    }
    REP(i,m) W(sol[i]);
    return 0;
}