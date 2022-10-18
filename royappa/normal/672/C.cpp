#include <bits/stdc++.h>

using namespace std;

using LL = long long;

#define SQR(x) ((x)*(x))
#define DIST(ax,ay,bx,by) sqrt(SQR((ax)-(bx))+SQR((ay)-(by)))

int main()
{
	LL w[2][2], tx, ty;
	cin >> w[0][0] >> w[0][1] >> w[1][0] >> w[1][1] >> tx >> ty;
	int n;
	cin >> n;
	vector<LL> x(n), y(n);
	double tot = 0.0;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		tot += 2*DIST(tx, ty, x[i], y[i]);
	}

	vector<vector<pair<double,int>>> s(2, vector<pair<double,int>>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			double d = DIST(tx, ty, x[i], y[i]) - DIST(w[j][0], w[j][1], x[i], y[i]);
			s[j][i] = {d,i};
		}
	}
	sort(s[0].rbegin(), s[0].rend());
	sort(s[1].rbegin(), s[1].rend());
	double best = -1.0e20;
	best = max(s[0][0].first, s[1][0].first);
	if (n > 1) {
		if (s[0][0].second != s[1][0].second) {
			best = max(best, s[0][0].first+s[1][0].first);
		}
		else {
			best = max(best, s[0][0].first+s[1][1].first);
			best = max(best, s[0][1].first+s[1][0].first);
		}
	}
	tot -= best;
	printf("%lf\n", tot);
	exit(0);
}