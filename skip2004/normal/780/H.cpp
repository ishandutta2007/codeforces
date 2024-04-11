#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 200200;
typedef long double db;
struct pt { db x, y; };
int x[maxn], y[maxn];
pt node[maxn];
int n, m;
db T, S;
inline pt sub(const pt & x, const pt & y) { return (pt) {x.x - y.x, x.y - y.y}; }
inline pt add(const pt & x, const pt & y) { return (pt) {x.x + y.x, x.y + y.y}; }
inline pt mul(const pt & x, db y){ return (pt) {x.x * y, x.y * y}; }
inline db sqr(db x){ return x * x; }

inline db dis(const pt&x) { return sqrt(abs(x.x) + abs(x.y)); }
inline db dis2(const pt&x) { return abs(x.x) + abs(x.y); }
inline db dis(const pt&x, const pt&y) { return sqrt(sqr(x.x - y.x) + sqr(x.y - y.y)); }
inline db dis2(const pt&x, const pt&y) { return sqr(x.x - y.x) + sqr(x.y - y.y); }

typedef std::pair<db, db> pr;
std::vector<pr> vc;
struct func { db a, b, c; };
static const db eps = 1e-12, inf = 1. / 0;
inline pr getroot(func fc) {
	static const pr nosol = {- inf, inf};
	static const pr allsol = {inf, -inf};
	if(fc.a < eps) return fc.c <= 0 ? nosol : allsol;
	const db delta = fc.b * fc.b - 4 * fc.a * fc.c;
	if(delta < 0) return allsol;
	const db x = sqrt(delta);
	return { (-fc.b - x) / fc.a / 2, (-fc.b + x) / fc.a / 2,};
}
inline void push(db l, db r) {
	l = fmod(l, T);
	r = fmod(r, T);
	if(r < l) {
		if(r < 0 || l > T) exit(1);
		vc.emplace_back(0, r);
		vc.emplace_back(l, T);
	} else {
		if(l > r || l < 0 || r > T) {
			exit(2);
		}
		vc.emplace_back(l, r);
	}
}
inline void push(pt a0, pt b0, pt a1, pt b1, db x, db su) {
	const db d = dis(a0, b0);
	if(d < eps) return ;
	a0 = sub(a0, a1), b0 = sub(b0, b1);
	pt dt = mul(sub(b0, a0), 1. / d);
	// (a0 + k * dt) ^ 2 = (a0.x + k * dt.x) ^ 2
	pr T = getroot((func){
		dt.x * dt.x + dt.y * dt.y,
		2 * (a0.x * dt.x + a0.y * dt.y),
		a0.x * a0.x + a0.y * a0.y - x * x
	});
	if(0 <= T.first) push(su, su + std::min<db>(d, T.first));
	if(T.second <= d) push(su + std::max<db>(0, T.second), su + d);
}
inline db can(db x) {
	pt x0 = node[0]; int id0 = 1;
	pt x1 = node[0]; int id1 = 1;
	db rem = T;
	for(;rem >= dis(x1, node[id1]);++id1 %= n)
		rem -= dis(x1, node[id1]), x1 = node[id1];
	x1 = add(x1, mul(sub(node[id1], x1), rem / dis(x1, node[id1])));
	db su = 0;
	vc.clear();
	for(int i = 0;i < n + n;++i) {
		if(dis(x0, node[id0]) > dis(x1, node[id1])) std::swap(id0, id1), std::swap(x0, x1);
		const db d = dis(x0, node[id0]);
		const pt t0 = node[id0];
		const pt t1 = add(x1, mul(sub(node[id1], x1), d / dis(x1, node[id1])));
		push(x0, t0, x1, t1, x, su);
		su += d;
		if(su >= T) su -= T;
		x0 = t0;
		if(++id0 == n) id0 = 0;
		x1 = t1;
	}
	sort(vc.begin(), vc.end());
	db max = 0, sum = 0;
	for(const pr& i : vc) {
		if(max < i.first) {
			sum += i.second - i.first;
			max = i.second;
		} else {
			if(i.second > max) {
				sum += i.second - max;
				max = i.second;
			}
		}
	}
	return std::fabs(sum - T) > eps;
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 0;i < n;++i) {
		cin >> x[i] >> y[i];
		node[i] = (pt) {(db) x[i], (db) y[i]};
	}
	for(int i = 0;i < n;++i) {
		S += dis(node[i], node[(i + 1) % n]);
	}
	T = S / m;
	db l = 0, r = 2e4;
	for(int c = 0;c < 50;++c) {
		db mid = (l + r) / 2;
		if(can(mid)) {
			r = mid;
		} else {
			l = mid;
		}
	}
	printf("%.10lf\n", double(r));
}