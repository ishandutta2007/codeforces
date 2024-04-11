#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
using LB = long double;


struct Point { LB x, y; int id;};        // 
using Vec = Point;                    // 
struct Line { Point P; Vec v; };      // 
struct Seg { Point A, B; };           // 
struct Circle { Point O; LB r; }; // 
using Points = std::vector<Point>;

const Point O = {0, 0};                        // 
const Line Ox = {O, {1, 0}}, Oy = {O, {0, 1}}; // 
const LB PI = acos(-1), EPS = 1e-18;

// bool eq(LB a, LB b) { return abs(a - b) < EPS; } // ==
// bool gt(LB a, LB b) { return a - b > EPS; }      // >
bool lt(LB a, LB b) { return a - b < -EPS; }     // <
// bool ge(LB a, LB b) { return a - b > -EPS; }     // >=
// bool le(LB a, LB b) { return a - b < EPS; }      // <=

// Vec r90a(Vec v) { return {-v.y, v.x}; }                          // 90
// Vec r90c(Vec v) { return {v.y, -v.x}; }                          // 90
// Vec operator+(Vec u, Vec v) { return {u.x + v.x, u.y + v.y}; }   // 
Vec operator-(Vec u, Vec v) { return {u.x - v.x, u.y - v.y}; }   // 
// Vec operator*(LB k, Vec v) { return {k * v.x, k * v.y}; }    // 
// LB operator*(Vec u, Vec v) { return u.x * v.x + u.y * v.y; } // 
// LB operator^(Vec u, Vec v) { return u.x * v.y - u.y * v.x; } // 
// LB len(Vec v) { return sqrt(v.x * v.x + v.y * v.y); }        // 
// LB slope(Vec v) { return v.y / v.x; }                        //  // NOTE isinfparal_y

LB theta(Point p) {// 
	return atan2(p.y, p.x);
}

void psort(Points &ps, Point c = O) {// 
	sort(ps.begin(), ps.end(), [&](auto p1, auto p2) {
		return lt(theta(p1 - c), theta(p2 - c));
	});
}

// int qua(auto p) { return lt(p.y, 0) << 1 | lt(p.x, 0) ^ lt(p.y, 0); }    // 
// void psort(Points &ps, Point c = O) {  // 
//     sort(ps.begin(), ps.end(), [&](auto v1, auto v2) {
//         return qua(v1 - c) < qua(v2 - c) || qua(v1 - c) == qua(v2 - c) 
//         	&& lt(cross(v1 - c, v2 - c), 0);
//     });
// }


Points pts;

int main() {
	cin.tie(0)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int x, y, i = 1; i <= n; i ++) {
		cin >> x >> y;
		pts.push_back({(LB)x, (LB)y, i});
	}
	psort(pts);
	// for (int i = 0; i < n; i ++) {
	// 	cout << pts[i].x << " " << pts[i].y << " " << pts[i].id << "\n";
	// }
	int id1 = pts[0].id;
	int id2 = pts[n - 1].id;
	LB mn = 2 * PI - (theta(pts[n - 1]) - theta(pts[0]));
	// cout << mn << endl;
	for (int i = 0; i < n - 1; i ++) {
		// cout << mn << endl;
		LB t = theta(pts[i + 1]) - theta(pts[i]);
		if (t < mn) {
			mn = t;
			id1 = pts[i].id;
			id2 = pts[i + 1].id;
		}
 	}
 	cout << id1 << " " << id2;
	return 0;	
}