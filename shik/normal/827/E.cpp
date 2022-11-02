// {{{ by shik
// #include <stdio.h>
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x),end(x)
#define RALL(x) rbegin(x),rend(x)
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define FOR(it,c) for ( auto it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef int64_t LL;
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
void _R( int64_t &x ) { scanf("%" PRId64,&x); }
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

template<typename T> inline bool chkmax( T &a, const T &b ) { return b>a ? a=b,true : false; }
template<typename T> inline bool chkmin( T &a, const T &b ) { return b<a ? a=b,true : false; }
template<typename T, typename F>
inline void sort_uniq( vector<T> &v, F f ) {
    sort(ALL(v),f);
    v.resize(unqiue(ALL(v))-v.begin());
}

template<typename T> using MaxHeap = priority_queue<T>;
template<typename T> using MinHeap = priority_queue<T,vector<T>,greater<T>>;

#ifdef SHIK
#define FILEIO(...)
#else
#define FILEIO(name) do {\
    freopen(name ".in","r",stdin); \
    freopen(name ".out","w",stdout); \
} while (0)
#endif
// }}}

namespace Mul {
    const double pi=acos(-1.0);
    
    struct Complex {
        double re,im;
        Complex( double _re=0, double _im=0 ):re(_re),im(_im) {}
        Complex operator +( const Complex &x ) const { return {re+x.re,im+x.im}; }
        Complex operator -( const Complex &x ) const { return {re-x.re,im-x.im}; }
        Complex operator *( const Complex &x ) const { return {re*x.re-im*x.im,re*x.im+im*x.re}; }
        Complex operator ~() const { return {re,-im}; }
    };

    void fft( vector<Complex> &a, int dir ){
        int n=a.size();
		for ( int i=0,j=1; j<n-1; j++ ) {
			for ( int k=n>>1; k>(i^=k); k>>=1 );
			if ( i<j ) swap(a[i],a[j]);
		}
        for ( int m=1; m+m<=n; m<<=1 ) {
            Complex wm(cos(dir*pi/m),sin(dir*pi/m));
            for ( int k=0; k<n; k+=m+m ) {
                Complex w=1;
                for ( int j=k; j<k+m; j++ ) {
                    Complex u=a[j],v=a[j+m]*w;
                    a[j]=u+v;
                    a[j+m]=u-v;
                    w=w*wm;
                }
            }
        }
    }

    void mul( int na, const int *a, int nb, const int *b, int *c ) {
        static vector<Complex> x;
        assert(na>0 && nb>0);
        int n=1;
		while ( n<2*max(na,nb) ) n*=2;
        x.resize(n);
		for ( int i=0; i<na; i++ ) x[i]=Complex(a[i],b[i]);
        for ( int i=na; i<n; i++ ) x[i]=0;
        fft(x,+1);
        const auto t=Complex{0,0.25};
        for ( int i=0; i<=n/2; i++ ) {
            int j=(n-i)&(n-1);
            auto p1=x[i],q1=~x[j];
            auto p2=x[j],q2=~x[i];
            x[i]=t*(p1+q1)*(q1-p1);
            x[j]=t*(p2+q2)*(q2-p2);
        }
        fft(x,-1);
		for ( int i=0; i<na+nb-1; i++ ) c[i]=x[i].re/n+0.5;
    }

	vector<int> mul( const vector<int> &a, const vector<int> &b ) {
		int na=a.size(),nb=b.size();
        assert(na>0 && nb>0);
		vector<int> c(na+nb-1);
        mul(na,a.data(),nb,b.data(),c.data());
		return c;
	}
};

using Mul::mul;

const int N=1e6+10;
int n,a[N],b[N],c[N];
char s[N];
bool z[N];

void go( char c1, char c2 ) {
    REP(i,n) a[i]=(s[i]==c1);
    REP(i,n) b[i]=(s[n-i-1]==c2);
    mul(n,a,n,b,c);
    REP(i,2*n-1) if ( c[i] ) z[abs(i-n+1)]|=1;
}

int main() {
    int t;
    R(t);
    while ( t-- ) {
        R(n,s);
        REP1(i,1,n) z[i]=0;
        go('V','K');
        VI sol;
        REP1(i,1,n) {
            bool zz=0;
            for ( int j=i; j<n && !zz; j+=i ) zz|=z[j];
            if ( !zz ) sol.PB(i);
        }
        W(SZ(sol));
        W(sol);
    }
    return 0;
}