#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex <double> tc;

const double eps = 1e-9;
const int it = 40;
const double inf = 1e9;
const double dlt = (3 + sqrt(5)) / 2;

struct tp{
	double x, y, z;
};

struct tq{
	double a, b, c;
};

int n;
double lt, rt;
tp cp;
tq q;
tp p[1000], pp[1000];

inline bool qq(double a, double b){
	return fabs(a - b) < eps;
}

inline double sqr(double a){
	return a * a;
}

inline double dist(const tp &a, const tp &b){
	return sqr(a.x - b.x) + sqr(a.y - b.y) + sqr(a.z - b.z);
}

inline double solve3(const tq &q, double a, double b){
	if(!qq(q.a, 0)){
		cp.y = a;
		cp.z = b;
		cp.x = (-q.b * cp.y - q.c * cp.z) / q.a;
	}
	else{
		if(!qq(q.b, 0)){
			cp.x = a;
			cp.z = b;
			cp.y = (-q.a * cp.x - q.c * cp.z) / q.b;
		}
		else{
			cp.x = a;
			cp.y = b;
			cp.z = (-q.a * cp.x - q.b * cp.y) / q.c;
		}
	}
	double res = 0;
	for(int i = 0; i < n; i++){
		res = max(res, dist(cp, pp[i]));
	}
	return res;
}

inline double solve2(const tq &q, double a){
	double l = lt;
	double r = rt;
	double m1 = l + (r - l) / dlt;
	double f1 = solve3(q, a, m1);
	double m2 = r - (r - l) / dlt;
	double f2 = solve3(q, a, m2);
	double res = min(f1, f2);
	for(int i = 0; i < it; i++){
		if(f1 < f2){
			r = m2;
			m2 = m1;
			f2 = f1;
			m1 = l + (r - l) / dlt;
			f1 = solve3(q, a, m1);
			res = min(res, f1);
		}
		else{
			l = m1;
			m1 = m2;
			f1 = f2;
			m2 = r - (r - l) / dlt;
			f2 = solve3(q, a, m2);
			res = min(res, f2);
		}
	}
	return res;
}

inline double solve1(const tq &q){
	double d = sqr(q.a) + sqr(q.b) + sqr(q.c);
	lt = inf;
	rt = -inf;
	for(int i = 0; i < n; i++){
		double k = (-q.a * p[i].x - q.b * p[i].y - q.c * p[i].z) / d;
		pp[i].x = p[i].x + k * q.a;
		pp[i].y = p[i].y + k * q.b;
		pp[i].z = p[i].z + k * q.c;
		lt = min(lt, pp[i].x);
		lt = min(lt, pp[i].y);
		lt = min(lt, pp[i].z);
		rt = max(rt, pp[i].x);
		rt = max(rt, pp[i].y);
		rt = max(rt, pp[i].z);
	}
	double l = lt;
	double r = rt;
	double m1 = l + (r - l) / dlt;
	double f1 = solve2(q, m1);
	double m2 = r - (r - l) / dlt;
	double f2 = solve2(q, m2);
	double res = min(f1, f2);
	for(int i = 0; i < it; i++){
		if(f1 < f2){
			r = m2;
			m2 = m1;
			f2 = f1;
			m1 = l + (r - l) / dlt;
			f1 = solve2(q, m1);
			res = min(res, f1);
		}
		else{
			l = m1;
			m1 = m2;
			f1 = f2;
			m2 = r - (r - l) / dlt;
			f2 = solve2(q, m2);
			res = min(res, f2);
		}
	}
	res = sqrt(res);
	return res;
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
  int m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%lf %lf %lf", &p[i].x, &p[i].y, &p[i].z);
	}
	for(int i = 0; i < m; i++){
		scanf("%lf %lf %lf", &q.a, &q.b, &q.c);
		printf("%.18lf\n", solve1(q));
	}
	return 0;
}