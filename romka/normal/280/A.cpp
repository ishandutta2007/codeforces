#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ld, ld> pdd;

const ld pi = acos(ld(-1.0));

void intersect(ld y, ld xa, ld ya, ld xb, ld yb, ld& rx, ld& ry) {
	ld A = yb - ya;
	ld B = xa - xb;
	ld C = -xa * A - ya * B;
	rx = (-C - B*y) / A;
	ry = y;
}

int w, h, a;
ld ux, uy, rx, ry, t1x, t1y, t2x, t2y, t3x, t3y, t4x, t4y;
vector<pdd> vp;

int main() {
	scanf("%d %d %d", &w, &h, &a);
	if (a > 90) a = 180 - a;
	if (a == 0) {
		printf("%.8f\n", double(w) * double(h));
		return 0;
	}
	if (h > w) {
		swap(h, w);
	}
	ld mxa = atan2(ld(h), ld(w));
	ld na = ld(a) / 180.0 * pi;
	ld d = sqrt(ld(w) * w / 4 + ld(h) * h / 4);
	ld ww = w * 0.5;
	ld hh = h * 0.5;
	ux = d * cos(mxa + na);
	uy = d * sin(mxa + na);
	rx = d * cos(na - mxa);
	ry = d * sin(na - mxa);
		
	if (na < 2 * mxa) {
		intersect(hh, ux, uy, rx, ry, t1x, t1y);
		intersect(ww, ry, rx, uy, ux, t2y, t2x);
		intersect(hh, ux, uy, -rx, -ry, t3x, t3y);
		intersect(ww, ry, rx, -uy, -ux, t4y, t4x);
		vp.pb(pdd(t3x, t3y));
		vp.pb(pdd(t1x, t1y));
		vp.pb(pdd(t2x, t2y));
		vp.pb(pdd(t4x, t4y));
		vp.pb(pdd(-t3x, -t3y));
		vp.pb(pdd(-t1x, -t1y));
		vp.pb(pdd(-t2x, -t2y));
		vp.pb(pdd(-t4x, -t4y));
	} else {
		intersect(hh, ux, uy, -rx, -ry, t1x, t1y);
		intersect(hh, -ux, -uy, rx, ry, t2x, t2y);
		vp.pb(pdd(t1x, t1y));
		vp.pb(pdd(t2x, t2y));
		vp.pb(pdd(-t1x, -t1y));
		vp.pb(pdd(-t2x, -t2y));
	}
	ld ans = 0;
	vp.pb(vp[0]);

	ld miny = vp[0].second;
	forn(i, vp.size())
		miny = min(miny, vp[i].second);

	forn(i, vp.size()) vp[i].second -= miny;

	forn(i, vp.size() - 1) {
		ans += (vp[i+1].first - vp[i].first) * (vp[i].second + vp[i+1].second);
	}

	if (ans < 0) ans = -ans;

	printf("%.8f\n", double(ans * 0.5));
	return 0;
}