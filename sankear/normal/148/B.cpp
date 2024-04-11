#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>

using namespace std;

const double eps = 1e-12;

inline bool qq(double a, double b){
	return fabs(a - b) < eps;
}

inline bool lq(double a, double b){
	return b - a > -eps;
}

int main(){
	//freopen("cobweb.in", "r", stdin);
	//freopen("cobweb.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	double vp, vd, t, f, c;
	scanf("%lf %lf %lf %lf %lf", &vp, &vd, &t, &f, &c);
	int ans = 0;
	double x = 0, dt = t;
	while(x < c){
		if(qq(vd, vp)){
			x = c;
			continue;
		}
		double needt = vd * dt / (vd - vp);
		if(needt < dt || lq(c, vp * needt)){
			x = c;
			continue;
		}
		ans++;
		dt = needt + vp * needt / vd + f;
	}
	printf("%d\n", ans);
	return 0;
}