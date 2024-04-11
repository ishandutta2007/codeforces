#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double

ll aa, bb, cc, x1, y1, x2, y2;
ll ans;
ld a, b, c;

ld dist(ld mx, ld my, ld ox, ld oy) {
	return sqrt( (mx-ox)*(mx-ox) + (my-oy)*(my-oy));
}


ld mandist(ld mx, ld my, ld ox, ld oy) {
	ld res = 0;
	if (mx - ox >= 0) res += mx-ox;
	else res += ox-mx;
	if (my - oy >= 0) res += my-oy;
	else res += oy-my;
	return res;
	// return fabs(mx-ox) + fabs(my-oy);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> aa >> bb >> cc >> x1 >> y1 >> x2 >> y2;

	if (bb < 0) {
		aa*=-1;
		bb*=-1;
		cc*=-1;
	}
	cc*=-1;


	ld ans = mandist(x1, y1, x2, y2);
	cout << fixed << setprecision(15);
	if (aa == 0 || bb == 0) {
		cout << ans << endl;
		return 0;
	}

	a = aa;
	b = bb;
	c = cc;

	vector<ld> fx;
	fx.push_back(x1);
	fx.push_back((1.0*c - b*y1)/a);

	vector<ld> sx;
	sx.push_back(x2);
	sx.push_back((1.0*c - b*y2)/a);

	for (ld xs : fx) {
		for (ld xe : sx) {

			ld ys = (-1.0*a*xs + c)/b;
			ld ye = (-1.0*a*xe + c)/b;

			// cout << xs << " " << ys << " to " << xe << " " << ye << endl;

			ld cd = dist(xs, ys, xe, ye);
			cd += mandist(x1, y1, xs, ys);
			cd += mandist(x2, y2, xe, ye);
			ans = min(ans, cd);
		}
	}

	cout << ans << endl;



}