#include <bits/stdc++.h>
const double eps = 1e-12;
using namespace std;
typedef long long ll;
template<typename T> inline void in(T &x){ //Read Positive Integer.
	register char ch; x = 0;
	// register int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}
double rad(double x){return 3.1415926535898 * x / 180.0;}

int main(){
	// freopen("c.in", "r", stdin);
	// freopen("c.out", "w", stdout);
	int n;
	double r;
	scanf("%d%lf", &n, &r);
	double ag = (180.0 - (360.0 / n)) / 2;
	// double L = 0, R = 100000000.0, d, x;
	double rat = 1.0 / cos(rad(ag));
	printf("%.10lf\n", r / (rat - 1));
	return 0;
}