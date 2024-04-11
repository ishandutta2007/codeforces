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

void getint(int &x) {
	char c;
	while (c=getchar(), (c<'0'||c>'9') && (c!='-')) ;
	bool sg=(c=='-');
	if (sg) c=getchar();
	x=0;
	while (c>='0' && c<='9') x=x*10+c-48, c=getchar();
	if (sg) x=-x;
}

void outint(int x) {
	if (x<0) putchar('-'), x=-x;
	int l=0, dt[10];
	while (x) dt[l++]=x%10, x/=10;
	if (!l) dt[l++]=0;
	while (l--) putchar(dt[l]+48);
}

void getINT(INT &x) {
	char c;
	while (c=getchar(), (c<'0'||c>'9') && (c!='-')) ;
	bool sg=(c=='-');
	if (sg) c=getchar();
	x=0;
	while (c>='0' && c<='9') x=x*10+c-48, c=getchar();
	if (sg) x=-x;
}

void outINT(INT x) {
	if (x<0) putchar('-'), x=-x;
	int l=0, dt[20];
	while (x) dt[l++]=x%10, x/=10;
	if (!l) dt[l++]=0;
	while (l--) putchar(dt[l]+48);
}

int main() {
   	int n, k, cnt, i, a;
	scanf("%d%d", &n, &k);
	cnt=0;
	rep(i, n) {
		scanf("%d", &a);
		if (a+k<=5) cnt++;
	}
	printf("%d\n", cnt/3);

    return 0;
}