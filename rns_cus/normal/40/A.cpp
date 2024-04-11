///	A : Coded by Choe Kwang

#include <bits/stdc++.h>
using namespace std;
#define ep 1e-8

double dist(double x, double y) {
	return sqrt(x * x + y * y);
}

double x, y;

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%lf %lf", &x, &y);
	if (x < 0) x = -x, y = -y;
	double d = dist(x, y);
	int m = d;
	if (abs(d - m) < ep || abs(m + 1 - d) < ep) {
		puts("black"); return 0;
	}
	if (y >= 0 && (m % 2 == 0) || y < 0 && (m % 2 == 1)) puts("black");
	else puts("white");
	return 0;
}