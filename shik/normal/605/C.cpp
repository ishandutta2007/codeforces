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

const int N=1e5+10;
const double pi=acos(-1);

int sgn( double x ) { return (x>0)-(x<0); }
int dir( double x0, double y0, double x1, double y1, double x2, double y2 ) {
    double dx1=x1-x0;
    double dy1=y1-y0;
    double dx2=x2-x0;
    double dy2=y2-y0;
    double val=dx1*dy2-dx2*dy1;
    return sgn(val);
}

int n;
double gx,gy,tx,ty,x[2*N],y[2*N],ang[2*N];

int ord[2*N];
bool cmp( int a, int b ) {
    return ang[a]<ang[b];
}

bool is_jiao( double a, double b, double c, double d ) { return max(a,b)>=min(c,d) && max(c,d)>=min(a,b); }
bool is_jiao( double ax, double ay, double bx, double by, double cx, double cy, double dx, double dy ) {
	if ( !is_jiao(ax,bx,cx,dx) ) return 0;
	if ( !is_jiao(ay,by,cy,dy) ) return 0;
	if ( dir(ax,ay,bx,by,cx,cy)*dir(ax,ay,bx,by,dx,dy)>0 ) return 0;
	if ( dir(cx,cy,dx,dy,ax,ay)*dir(cx,cy,dx,dy,bx,by)>0 ) return 0;
	return 1;
}

bool ok( double m ) {
    double ox=gx/m;
    double oy=gy/m;
    if ( max(ox,oy)>1e7 ) return 0;
    REP(i,n) ang[i]=atan2(y[i]-oy,x[i]-ox);
    REP(i,n) ord[i]=i;
    sort(ord,ord+n,cmp);
    REP(i,n) {
        x[i+n]=x[i];
        y[i+n]=y[i];
        ang[i+n]=ang[i]+2*pi;
        ord[i+n]=ord[i]+n;
    }
    int jj=0;
    REP(ii,n) {
        int i=ord[ii];
        while ( jj+1<2*n && ang[ord[jj+1]]-ang[i]<=pi ) jj++;
        int j=ord[jj];
        if ( is_jiao(x[i],y[i],x[j],y[j],ox,oy,tx,ty) ) return 1;
    }
    return 0;
}

LL my_rand() {
    LL r=0;
    REP(i,4) r=(r<<8)|(rand()%0xFF);
    return r;
}

int main() {
    // n=100000;
    // gx=1000000;
    // gy=gx-1;
    // REP(i,n) x[i]=my_rand()%500000+1;
    // REP(i,n) y[i]=my_rand()%500000+1;
    R(n,gx,gy);
    REP(i,n) R(x[i],y[i]);
    double tr=1e8/max(gx,gy);
    tx=tr*gx;
    ty=tr*gy;
    double ans=1e100;
    REP(i,n) ans=min(ans,max(gx/x[i],gy/y[i]));
    double l=1e-9,r=gx+gy;
    REP(i,60) {
        double m=(l+r)/2;
        if ( ok(m) ) r=m;
        else l=m;
    }
    ans=min(ans,(l+r)/2);
    printf("%.12f\n",ans);
    return 0;
}