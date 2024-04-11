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
const double inf = 1e12;
const double infans = 1e18;
const int it = 70;

int s, a, b, c;
double ans, bx, by, bz;

inline bool qq(double a, double b){
	return fabs(a - b) < eps;
}

inline double calc(double x, double y, double z){
	double res = 0;
	if(qq(x, 0)){
		res += a * -inf;
	}
	else{
		res += a * log(x);
	}
	if(qq(y, 0)){
		res += b * -inf;
	}
	else{
		res += b * log(y);
	}
	if(qq(z, 0)){
		res += c * -inf;
	}
	else{
		res += c * log(z);
	}
	return res;
}

inline double calcall(double x, double y, double z){
	double res = calc(x, y, z);
	if(res > ans){
		ans = res;
		bx = x;
		by = y;
		bz = z;
	}
	return res;
}

inline double calcz(double x, double y){
	double res = -infans, l = 0, r = s - x - y;
	for(int i = 0; i < it; i++){
		double m1 = l + (r - l) / 3;
		double f1 = calcall(x, y, m1);
		double m2 = r - (r - l) / 3;
		double f2 = calcall(x, y, m2);
		res = max(res, max(f1, f2));
		if(f1 < f2){
			l = m1;
		}
		else{
			r = m2;
		}
	}
	return res;
}

inline double calcyz(double x){
	double res = -infans, l = 0, r = s - x;
	for(int i = 0; i < it; i++){
		double m1 = l + (r - l) / 3;
		double f1 = calcz(x, m1);
		double m2 = r - (r - l) / 3;
		double f2 = calcz(x, m2);
		res = max(res, max(f1, f2));
		if(f1 < f2){
			l = m1;
		}
		else{
			r = m2;
		}
	}
	return res;
}

int main(){
	//freopen("chess.in", "r", stdin);
	//freopen("chess.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d %d %d %d", &s, &a, &b, &c);
	/*ans = calc(0, 0, 0), bx = 0, by = 0, bz = 0;
	double res = calc(s, 0, 0);
	if(res > ans){
		ans = res;
		bx = s;
		by = 0;
		bz = 0;
	}
	res = calc(0, s, 0);
	if(res > ans){
		ans = res;
		bx = 0;
		by = s;
		bz = 0;
	}
	res = calc(0, 0, s);
	if(res > ans){
		ans = res;
		bx = 0;
		by = 0;
		bz = s;
	}
	if(a + b > 0){
		double h = -((double)s) / (a + b);
		double x = -a / h, y = -b / h;
		double res = calc(x, y, 0);
		if(res > ans){
			ans = res;
			bx = x;
			by = y;
			bz = 0;
		}
	}
	if(a + c > 0){
		double h = -((double)s) / (a + c);
		double x = -a / h, z = -c / h;
		double res = calc(x, 0, z);
		if(res > ans){
			ans = res;
			bx = x;
			by = 0;
			bz = z;
		}
	}
	if(b + c > 0){
		double h = -((double)s) / (b + c);
		double y = -b / h, z = -c / h;
		double res = calc(0, y, z);
		if(res > ans){
			ans = res;
			bx = 0;
			by = y;
			bz = z;
		}
	}
	if(a + b + c > 0){
		double h = -((double)s) / (a + b + c);
		double x = -a / h, y = -b / h, z = -c / h;
		double res = calc(x, y, z);
		if(res > ans){
			ans = res;
			bx = x;
			by = y;
			bz = z;
		}
	}*/
	ans = -infans;
	double l = 0, r = s;
	for(int i = 0; i < it; i++){
		double m1 = l + (r - l) / 3;
		double f1 = calcyz(m1);
		double m2 = r - (r - l) / 3;
		double f2 = calcyz(m2);
		if(f1 < f2){
			l = m1;
		}
		else{
			r = m2;
		}
	}
	printf("%.10lf %.10lf %.10lf\n", bx, by, bz);
	return 0;
}