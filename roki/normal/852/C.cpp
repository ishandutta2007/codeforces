#include<bits/stdc++.h>

using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define for1(i, n) for(int i = 1; i < int(n); ++i)
#define fork(i, k, n) for(int i = int(k); i <= int(n); ++i)
#define forft(i, from, to) for(int i = int(from); i < int(to); ++i)
#define forr(i, n) for(int i = int(n) - 1; i >= 0; --i)
#define pb push_back
#define mp make_pair
#define mnp(a, b) make_pair((a) < (b) ? (a) : (b), (a) < (b) ? (b) : (a))
#define sz(d) int(d.size())
#define all(a) a.begin(), a.end()
#define ms(a, v) memset(a, v, sizeof(a))
#define msn(a, v, n) memset(a, v, n * sizeof(a[0]))
#define mcn(dst, src, n) memcpy(dst, src, n * sizeof(src[0]))
#define X first
#define Y second
#define correct(x, y, xmax, ymax) ((x) >= 0 && (x) < (xmax) && (y) >= 0 && (y) < (ymax))

template<typename T> T sqr(const T &x) {
	return x * x;
}

template<typename T> T my_abs(const T &x) {
	return x < 0 ? -x : x;
}

typedef long long li;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long long uli;
typedef long double ld;
typedef pair<ld,ld> pt;
typedef pair<li,li> pli;
typedef pair<ld,ld> pd;

const int INF = (int)1e9;
const li LINF = (li)6e18;
const li INF64 = LINF;
const li INFLL = LINF;
const ld EPS = 1e-9;
const ld PI = 3.1415926535897932384626433832795;

int n;

const int N = (int)5e4 + 10;

int a[N];

bool read() {
	scanf("%d", &n);
	forn(i, n) {
		scanf("%d", &a[i]);
	}
	return true;
}

vector<pair<ld, int> > c;

pt p[4];

pt operator +(const pt& a, const pt& b) {
	return pt(a.X + b.X, a.Y + b.Y);
}

pt operator -(const pt& a, const pt& b) {
	return pt(a.X - b.X, a.Y - b.Y);
}

pt operator *(const pt& a, const ld& d) {
	return pt(a.X * d, a.Y * d);
}

pt operator /(const pt& a, const ld& d) {
	return pt(a.X / d, a.Y / d);
}

ld dist(const pt& a, const pt& b) {
	return sqrt(sqr(a.X - b.X) + sqr(a.Y - b.Y));
}

ld dist(const pt& p, const pt& q, const pt& a) {
	ld A = p.Y - q.Y;
	ld B = q.X - p.X;
	ld C = -A * p.X - B * p.Y;
	return abs(A * a.X + B * a.Y + C) / sqrt(sqr(A) + sqr(B));
}

ld calc(int i, int j) {
	pt p1 = p[0] + (p[1] - p[0]) * i / (ld)n;
	pt p2 = p[2] + (p[3] - p[2]) * j / (ld)n;
	ld l = dist(p1, p2);
	ld h1 = dist(p1, p2, p[1]);
	ld h2 = dist(p1, p2, p[2]);
	return (h2 - h1) * l;
}

int ans[N];

void solve() {
	ld an = PI / n;
	forn(i, 4) {
		p[i] = pt(cos(i * an), sin(i * an));
	}
	forn(i, n) {
		c.pb(mp(calc(a[i], a[(i + 1)% n]), i));
	}
	sort(all(c));
	forn(i, n) {
		ans[c[i].Y] = i;
	}
	forn(i, n) {
		printf("%d ", ans[i]);
	}
}

//#define FILES

#define TASK "taskname"

int main() {

#ifdef SU2_PROJ
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
#ifdef FILES	
	freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);
#endif
#endif
	
	srand((unsigned int)time(NULL));

	cout << setprecision(15) << fixed;

	read();
	solve();
	
#ifdef SU2_PROJ
	cerr << "time: " << clock() << " ms" << endl;
#endif

	return 0;
}