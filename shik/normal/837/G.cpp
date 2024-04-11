// {{{ by shik
#if !defined(YCM) && 1
#define _FORTIFY_SOURCE 0
#pragma GCC optimize("O3,no-stack-protector")
#pragma GCC target("tune=native")
#include <stdio.h>
#endif
#include <bits/stdc++.h>
#include <unistd.h>
#pragma GCC diagnostic ignored "-Wunused-result"
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x),end(x)
#define RALL(x) rbegin(x),rend(x)
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef int64_t LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

template<class T> void _R( T &x ) { cin>>x; }
void _R( int &x ) { scanf("%d",&x); }
void _R( int64_t &x ) { scanf("%" PRId64,&x); }
void _R( double &x ) { scanf("%lf",&x); }
void _R( char &x ) { scanf(" %c",&x); }
void _R( char *x ) { scanf("%s",x); }
void R() {}
template<class T, class... U> void R( T& head, U&... tail ) { _R(head); R(tail...); }

template<class T> void _W( const T &x ) { cout<<x; }
void _W( const int &x ) { printf("%d",x); }
void _W( const int64_t &x ) { printf("%" PRId64,x); }
void _W( const double &x ) { printf("%.16f\n",x); }
void _W( const char &x ) { putchar(x); }
void _W( const char *x ) { printf("%s",x); }
template<class T> void _W( const vector<T> &x ) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W( const T& head, const U&... tail ) { _W(head); putchar(sizeof...(tail)?' ':'\n'); W(tail...); }

template<class T> inline bool chkmax( T &a, const T &b ) { return b>a ? a=b,true : false; }
template<class T> inline bool chkmin( T &a, const T &b ) { return b<a ? a=b,true : false; }
template<class T, class F=less<T>> void sort_uniq( vector<T> &v, F f=F() ) {
    sort(begin(v),end(v),f);
    v.resize(unique(begin(v),end(v))-begin(v));
}

template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;

#ifdef SHIK
template<class T> void _dump(const char *s, T &&head) { cerr << s << "=" << head << endl; }
template<class T, class... Args> void _dump(const char *s, T &&head, Args &&... tail) {
    for (int c = 0; *s != ',' || c != 0; cerr << *s++) {
        if (*s == '(' || *s == '[' || *s == '{') c++;
        if (*s == ')' || *s == ']' || *s == '}') c--;
    }
    cerr << "=" << head << ", ";
    _dump(s + 1, tail...);
}
#define dump(...) do { fprintf(stderr, "%s:%d - ", __PRETTY_FUNCTION__, __LINE__); _dump(#__VA_ARGS__, __VA_ARGS__); } while (0)

template<class Iter> ostream &_out(ostream &s, Iter b, Iter e) {
    s << "[";
    for (auto it = b; it != e; it++) s << (it == b ? "" : " ") << *it;
    return s << "]";
}

template<class A, class B> ostream &operator<<(ostream &s, const pair<A, B> &p) { return s << "(" << p.first << "," << p.second << ")"; }
template<class T> ostream &operator<<(ostream &s, const vector<T> &c) { return _out(s, ALL(c)); }
template<class T, size_t N> ostream &operator<<(ostream &s, const array<T, N> &c) { return _out(s, ALL(c)); }
template<class T> ostream &operator<<(ostream &s, const set<T> &c) { return _out(s, ALL(c)); }
template<class A, class B> ostream &operator<<(ostream &s, const map<A, B> &c) { return _out(s, ALL(c)); }
#else
#define dump(...)
#endif
// }}}

const int N=75010;
const int L=2e5+10;
const int B=256;

const LL MOD=1e9;

struct F {
    int x1,x2,y1,a,b,y2;
    void read() {
        R(x1,x2,y1,a,b,y2);
    }
    LL operator()( int x ) {
        if ( x<=x1 ) return y1;
        else if ( x<=x2 ) return 1LL*a*x+b;
        else return y2;
    }
} f[N];

void build( int st, int ed, LL out[] ) {
    static LL s0[L],s1[L];
    auto add=[]( LL s[], int l, int r, LL v ) {
        s[l]+=v;
        s[r+1]-=v;
    };
    memset(s0,0,sizeof(s0));
    memset(s1,0,sizeof(s1));
    REP1(i,st,ed) {
        add(s0,0,f[i].x1,f[i].y1);
        add(s0,f[i].x1+1,f[i].x2,f[i].b);
        add(s0,f[i].x2+1,L-5,f[i].y2);
        add(s1,f[i].x1+1,f[i].x2,f[i].a);
    }
    REP(i,L-5) {
        s0[i+1]+=s0[i];
        s1[i+1]+=s1[i];
    }
    REP(i,L) out[i]=s0[i]+s1[i]*i;
}

LL sf[N/B+1][L];
int n,m;
int main() {
    R(n);
    REP(i,n) f[i].read();
    for ( int i=0; i*B<n; i++ ) {
        int st=i*B,ed=min(st+B,n)-1;
        build(st,ed,sf[i]);
    }
    LL last=0;
    R(m);
    REP(im,m) {
        int l,r,x;
        R(l,r,x);
        l--; // [l, r)
        x=(x+last)%MOD;
        chkmin(x,L-8);
        LL ans=0;
        while ( l<r && l%B!=0 ) {
            ans+=f[l](x);
            l++;
        }
        while ( r>l && r%B!=0 ) {
            r--;
            ans+=f[r](x);
        }
        if ( l<r ) {
            int bl=l/B,br=r/B-1;
            dump(bl,br);
            REP1(i,bl,br) ans+=sf[i][x]; 
        }
        W(ans);
        last=ans;
    }
    return 0;
}