#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define SIZE(x) (int((x).size()))
#define rep(i,l,r) for (int i=(l); i<=(r); i++)
#define repd(i,r,l) for (int i=(r); i>=(l); i--)
#define rept(i,c) for (typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#ifndef ONLINE_JUDGE
#define debug(x) { cerr<<#x<<" = "<<(x)<<endl; }
#else
#define debug(x) {}
#endif
double inp[2][2];
double ans;
int fac[5];
void update(double na) {
	ans = min(ans,fabs(na));
}
void check() {
	int f = fac[0]*fac[1]*fac[2]*fac[3];
	double a = inp[0][0] * fac[0];
	double b = inp[0][1] * fac[1];
	double c = inp[1][0] * fac[2];
	double d = inp[1][1] * fac[3];
	if (f == 1) {
		double B = a+d-b-c;
		double C = a*d-b*c;
		if (abs(B) < 1e-30) return;
		update(-C/B);
	} else {
		double A = 2;
		double B = a+d+b+c;
		double C = a*d+b*c;
		double D = B*B - 4*A*C;
		if (D < -1e-9) return;
		if (D < 1e-30) D = 0;
		D = sqrt(D);
		update((-B-D) / (2*A));
		update((-B+D) / (2*A));
	}
}
void search(int lay) {
	if (lay == 4) {
		check();
		return;
	}
	fac[lay] = -1;
	search(lay+1);
	fac[lay] = 1;
	search(lay+1);
}
void lemon() {  
	rep(i,0,1) rep(j,0,1) scanf("%lf",&inp[i][j]);
	ans = 1e10;
	rep(i,0,1) {
		update(max(fabs(inp[0][i]),fabs(inp[1][i])));
		update(max(fabs(inp[i][0]),fabs(inp[i][1])));
	}
	search(0);
	printf("%.12lf\n", ans);
}
int main() {
  ios::sync_with_stdio(true);
  #ifndef ONLINE_JUDGE
  //  freopen("","r",stdin);
  #endif
  lemon();
  return 0;
}