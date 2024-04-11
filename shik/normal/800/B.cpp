// {{{ by shik
// #include <stdio.h>
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

#ifdef SHIK
#define FILEIO(...)
#else
#define FILEIO(name) do {\
    freopen(name ".in","r",stdin); \
    freopen(name ".out","w",stdout); \
} while (0)
#endif

// }}}

typedef double Double;
const Double pi = acos(Double(-1));
const Double eps = 1e-8;

int sgn(Double x, Double e = eps) { return (x > +e) - (x < -e); }
int cmp(Double x, Double y, Double e = eps) { return sgn(x - y, e); }

struct Point {
    Double x, y;
    Double len2() const { return x * x + y * y; }
    Double len() const { return sqrt(len2()); }
    bool operator<(const Point &rhs) { return tie(x, y) < tie(rhs.x, rhs.y); }
    bool operator==(const Point &rhs) { return x == rhs.x && y == rhs.y; }
    Point operator-() const { return {-x, -y}; }
    Point operator+(const Point &rhs) const { return {x + rhs.x, y + rhs.y}; }
    Point operator-(const Point &rhs) const { return {x - rhs.x, y - rhs.y}; }
    Point operator*(Double rhs) const { return {x * rhs, y * rhs}; }
    Point operator/(Double rhs) const { return {x / rhs, y / rhs}; }
    Point& operator+=(const Point &rhs) { return *this = *this + rhs; }
    Point& operator-=(const Point &rhs) { return *this = *this - rhs; }
    Point& operator*=(const Double &rhs) { return *this = *this * rhs; }
    Point& operator/=(const Double &rhs) { return *this = *this / rhs; }
    friend istream& operator>>(istream &is, Point &p) { return is >> p.x >> p.y; }
    friend ostream& operator<<(ostream &os, const Point &p) { return os << '(' << p.x << ',' << p.y << ')'; }
};

Point unit(const Point &p) { return p / p.len(); }
Point rotate_90(const Point &p) { return {-p.y, p.x}; }
Point rotate_180(const Point &p) { return {-p.x, -p.y}; }
Point rotate_270(const Point &p) { return {p.y, -p.x}; }
Point rotate(const Point &p, Double t) { return {p.x * cos(t) - p.y * sin(t), p.x * sin(t) + p.y * cos(t)}; }
Double dot(const Point &p, const Point &q) { return p.x * q.x + p.y * q.y; }
Double cross(const Point &p, const Point &q) { return p.x * q.y - q.x * p.y; }
Double cross(const Point &o, const Point &p, const Point &q) { return cross(p - o, q - o); }
Double dis(const Point &p, const Point &q) { return (p - q).len(); }
Double dis2(const Point &p, const Point &q) { return (p - q).len2(); }

int cmp(const Point &p, const Point &q, Double e = eps) {
    auto cx = cmp(p.x, q.x, e);
    return cx != 0 ? cx : cmp(p.y, q.y, e);
}

Double disPL(const Point &p, const Point &q1, const Point &q2) { return abs(cross(p, q1, q2)) / dis(p, q2); }
typedef Point P;

const int N=1234;
int n;
P p[N];
int main() {
    R(n);
    REP(i,n) R(p[i]);
    p[n]=p[0];
    p[n+1]=p[1];
    double ans=1e100;
    REP(i,n) REP(j,i) ans=min(ans,dis(p[i],p[j]));
    REP(i,n) ans=min(ans,disPL(p[i],p[i+1],p[i+2])/2);
    printf("%.14f\n",ans);
    return 0;
}