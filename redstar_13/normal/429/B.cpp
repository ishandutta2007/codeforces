#include <functional>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <bitset>
#include <string>
#include <vector>
#include <ctime>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>

using namespace std;

typedef long long INT;
typedef unsigned int uint;
typedef unsigned long long UINT;
typedef long double ldouble;
typedef pair <int, int> pii;
typedef pair <int, pii> p3i;
typedef pair <pii, pii> p4i;
typedef pair<double, double> pdd;

#define eps 1e-8
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define infL 1e100
#define MOD 1000000007
//#define MOD 1000000009

#define x first
#define y second
#define x1 _xalkdiegl
#define y1 _sdlkfeylg
#define x2 _dlkgegpfgoi
#define y2 _dogieltdgoe

#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) ((a)/gcd(a, b)*(b))
#define bit(x) (1<<(x))
#define bitL(x) (1LL<<(x))
#define mask(x) (bit(x)-1)
#define maskL(x) (bitL(x)-1)
#define contain(s, x) (((s)&bit(x))!=0)
#define containL(s, x) (((s)&bitL(x))!=0)
#define bcnt(x) (__builtin_popcount(x))
#define last(x) (__builtin_ctz(x))
#define mp(u, v) make_pair(u, v)
#define pb(x) push_back(x)
#define clr(a) memset(a, 0, sizeof(a))
#define cpy(a, b) memcpy(a, b, sizeof(a))
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, n) for (i=0; i<(n); i++)
#define rrep(i, n) for (i=(n)-1; i>=0; i--)
#define queue(n) int qf, qb, qu[(n)]

template <class T> inline void smax(T &a, T b) { if (a<b) a=b; }
template <class T> inline void smin(T &a, T b) { if (a>b) a=b; }
template <class T> inline T mmax(T a, T b) { if (a>b) return a; return b; }
template <class T> inline T mmin(T a, T b) { if (a>b) return b; return a; }
template <class T> inline T sqr(T x) { return x*x; }
template <class T> inline T mabs(T x) { if (x>=0) return x; return -x; }
template <class T> inline T cub(T x) { return x*x*x; }
template <class T> inline T Pow(T a, T b) { T t(a), r(1), k(0);
	while (b) { if (contain(b, k)) r=(INT)r*t%MOD, b-=bit(k); t=(INT)t*t%MOD; k++; }
	return r;
}

#define eprintf(...) {fprintf(stderr, __VA_ARGS__), fflush(stderr); }

#define beyond(r, c) (r<0 || c<0 || r>=R || c>=C)
const int dr[]={-1, 0, 1, 0};
const int dc[]={0, 1, 0, -1};

#define NN 1010

int a[NN][NN], b[NN][NN], c[NN][NN], d[NN][NN];
int aa[NN][NN], bb[NN][NN], cc[NN][NN], dd[NN][NN];
int v[NN][NN];

int main() {
//    freopen("b.in", "r", stdin);
//    freopen("out.out", "w", stdout);
	
	int i, j, R, C, res;
	
	scanf("%d %d ", &R, &C);
	rep(i, R) rep(j, C) scanf("%d ", &v[i][j]);
	
	rep(i, R) rep(j, C) {
		if (i==0 && j==0) { a[i][j]=b[i][j]=v[i][j]; continue; }
		if (i==0) a[i][j]=a[i][j-1]+v[i][j], b[i][j]=0;
		else if (j==0) a[i][j]=0, b[i][j]=b[i-1][j]+v[i][j];
		else {
			a[i][j]=mmax(a[i][j-1], b[i][j-1])+v[i][j];
			b[i][j]=mmax(a[i-1][j], b[i-1][j])+v[i][j];
		}
	}

	rrep(i, R) rep(j, C) {
		if (i==R-1 && j==0) { c[i][j]=d[i][j]=v[i][j]; continue; }
		if (i==R-1) c[i][j]=c[i][j-1]+v[i][j], d[i][j]=0;
		else if (j==0) c[i][j]=0, d[i][j]=d[i+1][j]+v[i][j];
		else {
			c[i][j]=mmax(c[i][j-1], d[i][j-1])+v[i][j];
			d[i][j]=mmax(c[i+1][j], d[i+1][j])+v[i][j];
		}
	}
	
	rrep(i, R) rrep(j, C) {
		if (i==R-1 && j==C-1) { aa[i][j]=bb[i][j]=v[i][j]; continue; }
		if (i==R-1) aa[i][j]=aa[i][j+1]+v[i][j], bb[i][j]=0;
		else if (j==C-1) aa[i][j]=0, bb[i][j]=bb[i+1][j]+v[i][j];
		else {
			aa[i][j]=mmax(aa[i][j+1], bb[i][j+1])+v[i][j];
			bb[i][j]=mmax(aa[i+1][j], bb[i+1][j])+v[i][j];
		}
	}

	rep(i, R) rrep(j, C) {
		if (i==0 && j==C-1) { cc[i][j]=dd[i][j]=v[i][j]; continue; }
		if (i==0) cc[i][j]=cc[i][j+1]+v[i][j], dd[i][j]=0;
		else if (j==C-1) cc[i][j]=0, dd[i][j]=dd[i-1][j]+v[i][j];
		else {
			cc[i][j]=mmax(cc[i][j+1], dd[i][j+1])+v[i][j];
			dd[i][j]=mmax(cc[i-1][j], dd[i-1][j])+v[i][j];
		}
	}

	res=0;
	for (i=1; i<R-1; i++) for (j=1; j<C-1; j++) {
		smax(res, a[i][j]+aa[i][j]+d[i][j]+dd[i][j]-4*v[i]	[j]);
		smax(res, b[i][j]+bb[i][j]+c[i][j]+cc[i][j]-4*v[i][j]);
	}
	
	printf("%d\n", res);

    return 0;
}