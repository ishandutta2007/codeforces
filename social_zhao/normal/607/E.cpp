#include<bits/stdc++.h>
#define double long double
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 5e5 + 5 + 5;
const double eps = 1e-8;
int n, m;
struct Vector {
	double x, y;
	Vector() { x = y = 0; }
	Vector(double a, double b) { x = a, y = b; }
	Vector operator +(Vector b) { return Vector(x + b.x, y + b.y); }
	Vector operator -(Vector b) { return Vector(x - b.x, y - b.y); }
	Vector operator *(double b) { return Vector(x * b, y * b); }
	Vector operator /(double b) { return Vector(x / b, y / b); }
	double operator *(Vector b) { return x * b.x + y * b.y; }
	double operator &(Vector b) { return x * b.y - y * b.x; }
	double len() { return sqrt(x * x + y * y); }
	double angle() { return atan2(y, x); }
} O; 
double Sx, Sy, ans;

struct Line { 
	Vector p, v; 
	Line() { p = v = Vector(); }
	Line(int k, int b) { p = Vector(0, b), v = Vector(1000, k); }
} lin[N];

struct Segment { 
	double l, r; 
	int id;
	Segment() { l = r = 0; }
	Segment(double a, double b, int c) { l = a, r = b, id = c; }
} seg[N];

double bin[N];
int len, top;

namespace BIT {
	int sum[N];
	void clear() { memset(sum, 0, sizeof(sum)); }
	int lowbit(int x) { return x & (-x); }
	void add(int x, int v) { while(x <= len) sum[x] += v, x += lowbit(x); }
	int ask(int x) { int r(0); while(x) r += sum[x], x -= lowbit(x); return r; }
	int ask(int l, int r) { return ask(r) - ask(l - 1); }
}

double GetDis(Vector O, Line L) { return fabs(L.v & (O - L.p)) / L.v.len(); }
Vector Intersect(Line a, Line b) { return b.p + b.v * ((b.p - a.p) & a.v) / (a.v & b.v); }
double GetDis(Vector A, Vector B) { return (A - B).len(); }

void GetRange(double R) {
	top = 0, len = 0;
	for(int i = 1; i <= n; i++) {
		double dis = GetDis(O, lin[i]);
		if(dis <= R) {
			Vector e = lin[i].v / lin[i].v.len();
			Vector mid = lin[i].p + e * (e * (O - lin[i].p));
			double ln = sqrt(R * R - dis * dis);
			Vector p1 = mid - e * ln, p2 = mid + e * ln;
			double l = (p1 - O).angle(), r = (p2 - O).angle();
			if(l > r) swap(l, r);
			seg[++top] = Segment(l, r, i), bin[++len] = l, bin[++len] = r;
		}
	}
	sort(bin + 1, bin + 1 + len), len = unique(bin + 1, bin + 1 + len) - bin - 1;
	sort(seg + 1, seg + 1 + top, [](Segment a, Segment b) { return a.l < b.l; });
}

int chk(double R) {
	GetRange(R);
	int cnt = 0;
	BIT::clear();
	for(int i = 1; i <= top; i++) {
//		cout << l << " " << r << endl;
		int l = lower_bound(bin + 1, bin + 1 + len, seg[i].l) - bin;
		int r = lower_bound(bin + 1, bin + 1 + len, seg[i].r) - bin;
		cnt += BIT::ask(l, r), BIT::add(r, 1);
	}
	return cnt;
}

namespace SGT {
	#define lc (u << 1)
	#define rc (u << 1 | 1)
	vector<int> t[N << 2];
	
	void update(int u, int l, int r, int x, int v) {
		t[u].push_back(v);
		if(l == r) return;
		int mid = (l + r) >> 1;
		if(x <= mid) update(lc, l, mid, x, v);
		else update(rc, mid + 1, r, x, v);
	}
	
	void query(int u, int l, int r, int a, int b, int v) {
		if(a == l && r == b) {
			for(auto x : t[u]) ans += GetDis(Intersect(lin[x], lin[v]), O);
			return;
		}
		int mid = (l + r) >> 1;
		if(b <= mid) return query(lc, l, mid, a, b, v);
		else if(a > mid) return query(rc, mid + 1, r, a, b, v);
		else return query(lc, l, mid, a, mid, v), query(rc, mid + 1, r, mid + 1, b, v);
	}
}

void GetAns(double R) {
	GetRange(R);
	for(int i = 1; i <= top; i++) {
		int l = lower_bound(bin + 1, bin + 1 + len, seg[i].l) - bin;
		int r = lower_bound(bin + 1, bin + 1 + len, seg[i].r) - bin;
		SGT::query(1, 1, len, l, r, seg[i].id), SGT::update(1, 1, len, r, seg[i].id);
	}
}

int main() {
	n = get();
	Sx = get(), Sy = get(), m = get();
	O = Vector(Sx, Sy);
	for(int i = 1; i <= n; i++) {
		int k = get(), b = get();
		lin[i] = Line(k, b);
	}
	double l = 0, r = 1e18, res = 0;
//	double l = 7212.1, r = 7212.1, res = 0;
	for(int i = 1; i <= 100; i++) {
		double mid = (l + r) / 2.0;
		if(chk(mid) >= m) res = mid, r = mid;
		else l = mid;
	}
//	cout << r << endl;
	res = r;
	ans = res * (m - chk(res - 0.0001));
	GetAns(res - 0.0001);
	printf("%.10Lf", ans / 1000);
	return 0;
}