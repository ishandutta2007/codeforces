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
#include <map>
#include <set>
#include <string>
#include <deque>
#include <queue>

#ifdef WIN32
#define LLD "%I64d"
#define LLU "%I64u"
#else
#define LLD "%lld"
#define LLU "%llu"
#endif

using namespace std;

typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector < vi > vvi;
typedef vector < pii > vpii;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef long double ld;

#define fill(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define mp make_pair
#define sz(a) (int)(a.size())
#define forn(i,a,b) for(int i = (a); i < (b); ++i)

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3fLL;
const double EPS = 1e-9;

int w, h;
int angle;

#define pi M_PI

int convert(double &x, double &y, double ang) {
	double tmp_x = x, tmp_y = y;
	x = tmp_x * cos(ang) - tmp_y * sin(ang);
	y = tmp_y * cos(ang) + tmp_x * sin(ang);
	return 0;
}

int main() {
	scanf("%d%d%d", &w, &h, &angle);
	if (w < h) swap(w, h);
	double dw = w, dh = h;
	if (angle > 90) angle = 180 - angle;
	double ans = dw * dh;
	if (angle == 0) {
		printf("%.15lf\n", ans);
		return 0;
	}
	if (angle == 90) {
		printf("%.15lf\n", dh * dh);
		return 0;
	}
	double ang = angle * 1.0 * pi / 180.0, dang = 2 * atan2(dh, dw);
	dw /= 2., dh /= 2.;
	if (ang <= dang) {
		double dx = dh * (cos(ang) - 1) / sin(ang), dy = -(dw * sin(ang) - dh) / cos(ang);
		double sub = (dx + dw) * (-dy + dh) / 2;
		dy = (dy + dh) * cos(ang) / (1 + cos(ang));
		sub += dy * dy * tan(ang) / 2;
		ans -= 2 * sub; 
	} else {
		double d1x = dh * (cos(ang) - 1) / sin(ang), d2x = -dh * (cos(ang) + 1) / sin(ang);
		double sub = (d1x + d2x + 2 * dw) * dh;
		ans -= 2 * sub;
	}
	printf("%.15lf\n", ans);
	return 0;
}