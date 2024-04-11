// {{{ by shik
#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-function"
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define REP(i, n) for (int i = 0; i < int(n); i++)
#define REP1(i, a, b) for (int i = (a); i <= int(b); i++)
#define MP make_pair
#define PB push_back
using namespace std;
typedef int64_t LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

namespace { namespace shik {

template<class T> void _R(T &x) { cin >> x; }
void _R(int &x) { scanf("%d", &x); }
void _R(int64_t &x) { scanf("%" SCNd64, &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }

template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const int64_t &x) { printf("%" PRId64, x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }

#ifdef SHIK
#include "dump.hpp"
#else
#define dump(...)
#endif

template<class T, class F = less<T>> void sort_uniq(vector<T> &v, F f = F()) { sort(begin(v), end(v), f); v.resize(unique(begin(v), end(v)) - begin(v)); }
template<class T> inline T bit(T x, int i) { return (x >> i) & 1; }
template<class T> inline bool chkmax(T &a, const T &b) { return b > a ? a = b, true : false; }
template<class T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, true : false; }
template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;

// }}}

typedef LL Double;

struct Point {
    Double x, y;
    Double len2() const { return x * x + y * y; }
    bool operator<(const Point &rhs) const { return tie(x, y) < tie(rhs.x, rhs.y); }
    bool operator==(const Point &rhs) const { return x == rhs.x && y == rhs.y; }
    Point operator-() const { return {-x, -y}; }
    Point operator+(const Point &rhs) const { return {x + rhs.x, y + rhs.y}; }
    Point operator-(const Point &rhs) const { return {x - rhs.x, y - rhs.y}; }
    Point operator*(Double rhs) const { return {x * rhs, y * rhs}; }
    Point& operator+=(const Point &rhs) { return *this = *this + rhs; }
    Point& operator-=(const Point &rhs) { return *this = *this - rhs; }
    Point& operator*=(Double rhs) { return *this = *this * rhs; }
};

Point rotate_90(const Point &p) { return {-p.y, p.x}; }
Point rotate_180(const Point &p) { return {-p.x, -p.y}; }
Point rotate_270(const Point &p) { return {p.y, -p.x}; }
Double dot(const Point &p, const Point &q) { return p.x * q.x + p.y * q.y; }
Double cross(const Point &p, const Point &q) { return p.x * q.y - q.x * p.y; }
Double cross(const Point &o, const Point &p, const Point &q) { return cross(p - o, q - o); }
Double dis2(const Point &p, const Point &q) { return (p - q).len2(); }

using P=Point;
const int N=1e5+10;

void convex_hull( int &n, P p[] ) {
    sort(p,p+n);
    vector<P> q1,q2;
    REP(i,n) {
        while ( SZ(q1)>=2 && cross(q1[q1.size()-2],q1.back(),p[i])<=0 ) q1.pop_back();
        while ( SZ(q2)>=2 && cross(q2[q2.size()-2],q2.back(),p[i])>=0 ) q2.pop_back();
        q1.PB(p[i]);
        q2.PB(p[i]);
    }
    n=0;
    for ( auto i:q1 ) p[n++]=i;
    for ( int i=SZ(q2)-2; i>0; i-- ) p[n++]=q2[i];
    assert(n>=2);
    p[n]=p[0];
    p[n+1]=p[1];
}

template<class T>
void min_rotation(vector<T> &s) {
    int n=SZ(s);
    s.insert(s.end(),ALL(s));
    int i = 0, j = 1, k = 0;
    while (j < n && k < n) {
        if (s[i + k] == s[j + k]) k++;
        else {
            if (s[i + k] < s[j + k]) j += k + 1;
            else i += k + 1;
            k = 0;
        }
        if (i == j) j++;
    }
    rotate(s.begin(),s.begin()+i,s.end());
    s.resize(n);
}

vector<pair<LL,LL>> get_ls( int n, P p[] ) {
    vector<pair<LL,LL>> v;
    REP(i,n) {
        LL len=dis2(p[i],p[i+1]);
        LL area=cross(p[i],p[i+1],p[i+2]);
        assert(area>0);
        v.PB({len,area});
    }
    min_rotation(v);
    return v;
}

int n,m;
P a[N],b[N];

bool solve() {
    convex_hull(n,a);
    convex_hull(m,b);
    if ( n!=m ) return 0;
    if ( n==2 ) return dis2(a[0],a[1])==dis2(b[0],b[1]);
    auto al=get_ls(n,a);
    auto bl=get_ls(m,b);
    if ( al!=bl ) return 0;
    return 1;
}

void main() {
    R(n,m);
    REP(i,n) R(a[i].x,a[i].y);
    REP(i,m) R(b[i].x,b[i].y);
    W(solve() ? "YES" : "NO");
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}