#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <complex>
#define X(x) (real(x))
#define Y(x) (imag(x))
using namespace std;

typedef long long LL;
struct Q {
	LL t;
	LL x, y;
	LL tr, tn;

	bool operator < (const Q & b) const{
		return tr < b.tr;
	}
} inp[1000010];

int n, l;
int ans;

typedef complex<LL> P;
P mi, mx;

P div1(P x, LL d) {
	P r;
	X(r) = X(x) >= 0 ? X(x)/d : -(-X(x)+d-1)/d;
	Y(r) = Y(x) >= 0 ? Y(x)/d : -(-Y(x)+d-1)/d;
	return r;
}
P div2(P x, LL d) {
	P r;
	X(r) = X(x) >= 0 ? (X(x)+d-1)/d : -(-X(x))/d;
	Y(r) = Y(x) >= 0 ? (Y(x)+d-1)/d : -(-Y(x))/d;
	return r;
}
void update(P d, LL dr, LL dn) {
	if (!dn) {
		if (abs(X(d)) > dr || abs(Y(d)) > dr) ans = 0;
	} else {
		if (dn < 0) {
			d = -d;
			dn = -dn;
		}
		P d1 = div2(d - P(dr, dr) , dn), d2 = div1(d + P(dr, dr), dn);
		X(mi) = max(X(mi), X(d1));
		Y(mi) =max(Y(mi), Y(d1));
		X(mx) = min(X(mx), X(d2));
		Y(mx) =min(Y(mx), Y(d2));
	}
}

LL gx, gy;
char out[3000010];
int main() {
	scanf("%d%d", &n, &l);
	ans = 1;
	for (int i=1; i<=n; i++) {
		scanf("%I64d%I64d%I64d", &inp[i].t, &inp[i].x, &inp[i].y);
		inp[i].tr = inp[i].t % l;
		inp[i].tn = inp[i].t / l;
		if ((inp[i].x + inp[i].y + inp[i].t) & 1 != 0) ans = 0;
	}
	if (!ans) {
		puts("NO");
		return 0;
	}
	mi = P(-l, -l);
	mx = P(l, l);
	std::sort(inp+1, inp+n+1);
	for (int i=0; i<n; i++) {
		P p0(inp[i].x + inp[i].y, inp[i].x - inp[i].y), p1(inp[i+1].x+inp[i+1].y, inp[i+1].x - inp[i+1].y);
			update(p1-p0, inp[i+1].tr - inp[i].tr, inp[i+1].tn - inp[i].tn);
	}

		P p0(inp[n].x + inp[n].y, inp[n].x - inp[n].y), p1(inp[0].x+inp[0].y, inp[0].x - inp[0].y);
		update(p0, l - inp[n].tr, inp[n].tn+1);


	if (X(mi) > X(mx) || Y(mi) > Y(mx)) ans = 0;
	else if (X(mi) == X(mx) && Y(mi) == Y(mx) && (X(mi) + Y(mi)) % 2 != 0) ans = 0;
	else {
		LL xx = X(mi), yy = Y(mi);
		if ((X(mi) + Y(mi)) % 2) {
			if (X(mx)-X(mi) > Y(mx)-Y(mi)) xx++;
			else yy++;
		}
		gx = (xx + yy )/2;
		gy = (xx - yy )/ 2;
		if ((gx + gy + l) % 2) {
			if (xx < X(mx) && yy < Y(mx)) xx++, yy++;
			else if (xx < X(mx) && yy > Y(mi)) xx++, yy--;
			else if (xx > X(mi) && yy < Y(mx)) xx--, yy++;
			else ans = 0;

		gx = (xx + yy )/2;
		gy = (xx - yy )/ 2;
		}
	}
	if (!ans) {
		puts("NO");
		return 0;
	}

	inp[n+1].x = gx;
	inp[n+1].y = gy;
	inp[n+1].tr = l;
	inp[n+1].tn = 0;
	for (int i=0; i<=n; i++) {
		inp[i].x -= inp[i].tn * gx;
		inp[i].y -= inp[i].tn * gy;
	}
	for (int i=0; i<=n; i++) {

		LL dx = inp[i+1].x - inp[i].x, dy = inp[i+1].y - inp[i].y;
		assert(abs(dx)+abs(dy) <= inp[i+1].tr - inp[i].tr);
		for (int j=inp[i].tr; j < inp[i+1].tr; j++) {
			if (dx < 0) {
				dx++;
				out[j] = 'L';
			} else if (dx > 0) {
				dx--;
				out[j] = 'R';
			} else if (dy < 0) {
				dy++;
				out[j] = 'D';
			} else if (dy > 0) {
				dy--;
				out[j] = 'U';
			} else {
				dx++;
								out[j] = 'L';
			}
		}
	}
	puts(out);
	return 0;

}