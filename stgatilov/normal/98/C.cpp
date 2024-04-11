#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

double a, b, len;
double maxans;
double ans;

const double EPS = 1e-8;
const double DELTA = 1e-14;

double wid(double t) {
	double x = cos(t);
	double y = sin(t);
	double ret = (a/x + b/y - len) / sqrt(1 / (x*x) + 1 / (y*y));
	if (ans > ret) ans = ret;
	return ret;
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%lf%lf%lf", &a, &b, &len);
	if (a < b) swap(a, b);
	maxans = min(min(a, b), len);
	ans = maxans;

	if (len <= a + EPS && ans <= b + EPS) {
		printf("%0.15lf\n", ans);
		return 0;
	}

	double left = 0.0;
	double right = acos(0.0);
	int cc = 0;
	while (right - left > DELTA && ++cc < 1000) {
		double midm = (left + right) / 2.0;
		double midl = (left + midm) / 2.0;
		double midr = (right + midm) / 2.0;
		if (wid(midm) <= wid(midl) && wid(midm) <= wid(midr)) {
			left = midl;
			right = midr;
		}
		else {
			if (wid(midl) < wid(midr))
				right = midm;
			else
				left = midm;
		}
	}

	if (ans < EPS) printf("My poor head =(\n");
	else printf("%0.15lf\n", ans);

	return 0;
}