#include<bits/stdc++.h>
const int maxn = 1010;
typedef long double db;
const db pi = std::acos(-1);
using std::cin;
using std::cout;
int w, h, n;
int a[maxn], b[maxn];

inline void up(db & x, db y) { if(x < y) x = y; }

inline db calc(const db & x, const db & y) {
	db min = 1. / 0, semin = 1. / 0;
	for(int i = 0;i < n;++i) {
		db dist = (x - a[i]) * (x - a[i]) + (y - b[i]) * (y - b[i]);
		if(dist < min) semin = min, min = dist;
		else if(dist < semin) semin = dist;
	}
	return semin;
}

inline db rd() {
	static std::mt19937 mt(time(0));
	return (db) mt() / mt.max();
}
inline db test() {
	db sx = rd() * w, sy = rd() * h, v = calc(sx, sy);
	for(db t = 0.4;t >= 1e-10;t *= 0.995) {
		db tx = sx + (rd() - 0.5) * t * w;
		db ty = sy + (rd() - 0.5) * t * h;
		if(tx < 0) tx = 0; if(tx > w) tx = w;
		if(ty < 0) ty = 0; if(ty > h) ty = h;
		db vv = calc(tx, ty);
		if(vv > v || exp((vv - v) / t) > rd()) 
			sx = tx, sy = ty, v = vv;
	}
	return v;
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> w >> h >> n;
	for(int i = 0;i < n;++i) {
		cin >> a[i] >> b[i];
	}
	db ans = 0;
	for(int i = 0;i < 100;++i) up(ans, test());
	printf("%.12Lf\n", sqrtl(ans));
}