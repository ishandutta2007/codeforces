#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

struct point{double x, y;};
struct vctr{double x, y;};

point null0;
point vv, vvp;
double vq, vpr;
double r_big, r_lit;

vctr v(const point &p1, const point &p2){
	vctr res;
	res.x = p2.x - p1.x;
	res.y = p2.y - p1.y;
	return res;
}

double CP(const vctr &v1, const vctr &v2){return(v1.x * v2.y - v1.y * v2.x);}
double DP(const vctr &v1, const vctr &v2){return(v1.x * v2.x + v1.y * v2.y);}

int turn_v(vctr &v1, const double &ang){
	vctr res = v1;
	v1.x = (res.x * cos(ang) - res.y * sin(ang));
	v1.y = (res.y * cos(ang) + res.x * sin(ang));
	return 0;
}

double len(const vctr &v){return(sqrt(v.x * v.x + v.y * v.y));}

double dist_to_points(const point &p, const point &p1, const point &p2){
	return(fabs(CP(v(p1, p2), v(p, p1)) / len(v(p1, p2))));
}

double dist_twp(const point &p1, const point &p2, const double &rmin){
	//cerr << "go\n";
	//cerr << p1.x << ' ' << p1.y << '\n';
	//cerr << p2.x << ' ' << p2.y << '\n';
	//cerr << fabs(p1.x - p2.x) << ' ' << fabs(p1.y - p2.y) << '\n';
	if(fabs(p1.x - p2.x) < 1e-8 && fabs(p1.y - p2.y) < 1e-8)return 0;
	//cerr << len(v(p1, p2)) << '\n';
	if(dist_to_points(null0, p1, p2) >= rmin || DP(v(p1, null0), v(p1, p2)) <= 0 || DP(v(p2, null0), v(p2, p1)) <= 0)
	return(len(v(p1, p2)));
	vctr vv1 = v(null0, p1), vv2 = v(null0, p2);
	double l1 = len(vv1), l2 = len(vv2);
	double a_p1 = acos(rmin / l1), a_p2 = acos(rmin / l2);
	double len1 = sqrt(l1 * l1 - rmin * rmin), len2 = sqrt(l2 * l2 - rmin * rmin);
	//cerr << a_p1 << ' ' << a_p2 << '\n';
	double cospp = (DP(vv1, vv2) / (l1 * l2));
	//cerr << acos(cospp) << '\n';
	cospp = acos(cospp) - a_p1 - a_p2;
	//cerr << cospp << '\n';
	return(len1 + len2 + cospp * rmin);
}

point to_go(const point &beg, const double &t_time, const double &rr, const double &vv){
	double ang = vv * t_time / rr;
	vctr cur_v = v(null0, beg);
	turn_v(cur_v, ang);
	point res;
	res.x = cur_v.x;
	res.y = cur_v.y;
	return res;
}

bool can_go(const double &tt){
	point go_now = to_go(vv, tt, r_big, vpr);
	double time_go = dist_twp(go_now, vvp, r_lit);
	return(time_go < tt * vq);
}

int main(){
	ios_base::sync_with_stdio(false);

	null0.x = null0.y = 0.0;
	int a, b, c, d, e, f, g;
	cin >> a >> b >> c >> d >> e >> f >> g;
	vv.x = double(a);
	vv.y = double(b);
	r_big = len(v(null0, vv));
	vpr = double(c);
	vvp.x = double(d);
	vvp.y = double(e);
	vq = double(f);
	r_lit = double(g);
	double l = 0.0, r = 1e10;
	for(int i = 0; i < 500; ++i){
		double m = (l + r) / 2;
		if(can_go(m))r = m;
		else l = m;
	}

	/*double r;

	point aa, bb;
	aa.x = bb.x = 0.0;
	aa.y = -100.0;
	bb.y = 100.0;
	r = dist_twp(aa, bb, 50.0);*/
	cout << fixed << setprecision(15) << l << '\n';

	return 0;
}