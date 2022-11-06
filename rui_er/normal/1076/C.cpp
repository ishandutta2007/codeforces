//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const double eps = 1e-9, epss = 1e-6;

int T, x;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
double calc(double a, double b, double c, double tg) { // ax^2+bx+c=0
	double delta = 1.0 * x * x - 4.0 * x;
	double ans = (-b + tg * sqrt(delta)) / (2.0 * a);
	return ans;
}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &x);
		int delta = x * x - 4 * x;
		if(delta < 0) puts("N");
		else printf("Y %.9lf %.9lf\n", calc(1, -x, x, -1), calc(1, -x, x, 1));
	}
	return 0;
}