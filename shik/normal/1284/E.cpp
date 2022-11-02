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

// {{{ Bitwise
#define F(name) \
    template<class T, typename enable_if<is_integral<T>::value>::type* = nullptr> \
    constexpr int name(T x) { return sizeof(T) <= sizeof(int) ? __builtin_ ## name(x) : __builtin_ ## name ## ll(x); }

F(clz) F(ctz) F(ffs) F(parity) F(popcount)

#undef F
#define popcnt popcount

template<class T>
T has_bit(T x, int i) { return (x >> i) & 1; }

template<class T>
constexpr int lg2(T x) { return sizeof(T) * CHAR_BIT - 1 - clz(x); }
// }}}
// {{{ gcd
template<class T>
T gcd(T u, T v) {
    u = abs(u); v = abs(v);
    if (!u || !v) return u + v;
    int shift = ctz(u | v);
    u >>= ctz(u);
    while (v) {
        v >>= ctz(v);
        if (u > v) swap(u, v);
        v -= u;
    }
    return u << shift;
}
// }}}

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

LL C(int n, int m) {
    if (m > n) return 0;
    LL ans = 1;
    for (int i = 0; i < m; i++)
        ans = ans * (n - i) / (i + 1);
     return ans;
}

using Double = long double;

const Double eps = 1e-19;
const Double pi = acosl(-1.0L);
const int N = 2510;

int n;
struct Point {
	int x, y;
	void read() {
        R(x, y);
 	}
} p[N];

Double r[2 * N];

Double cal(const Point& a, const Point& b) {
    int dy=b.y - a.y;
    int dx=b.x - a.x;
    int g=gcd(dx,dy);
    return atan2l(dy/g,dx/g);
}

LL solve(int num) {
	int tn = 0;
	LL ans = 0;
	for (int i = 0; i < n; i++) {
		if (i == num) continue;
		r[tn++] = cal(p[num], p[i]);
 	}
 	sort(r, r + tn);
	int j = 1;
	for (int i = 0; i < tn; i++)
		r[i + tn] = r[i] + 2 * pi;
  	for (int i = 0; i < tn; i++) {
	  	while (fabs(r[j] - r[i]) - pi < -eps) j++;
  		ans += C(j - i - 1, 2);
	}
	return C(tn, 3) - ans;
}

void main() {
    // Point p;
    // p.read();
    // Double a=cal(p,Point{0,0});
    // printf("%.20Lf\n",a);
    R(n);
    for (int i = 0; i < n; i++) p[i].read();
    LL ans = 0;
    for (int i = 0; i < n; i++) ans += solve(i);
    ans *= n - 4;
    ans /= 2;
    W(ans);
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}