#include <bits/stdc++.h>

using namespace std;
#define maxn 100010

#define double long double

#define pt pair<double, double>
#define mp make_pair
int n;

const double eps = 1e-9;

double inf = 1.0 * (1LL << 30);
double xs[maxn];
double ys[maxn];

bool go(double mid) {

	// cout << "mid:  " << mid << endl;
	double clo = -mid*2.0 - inf;
	double chi = mid*2.0 + inf;

	for (int i = 0; i < n; i++) {
		double rhs = (mid - (mid-ys[i])) * (mid + (mid-ys[i]));
		// cout << "   " << rhs << endl;
		if (rhs < 0) return false;
		rhs = sqrt(rhs);
		double op1 = rhs + xs[i];
		double op2 = -rhs + xs[i];
		// cout << "   "  << op1 << " " << op2 << endl;

		clo = max(clo, op2);
		chi = min(chi, op1);

	}

	return clo <= chi + eps;
}

int main() {
	srand(23);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	int x, y;
	bool haspos = false;
	bool hasneg = false;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		if (y > 0) haspos = true;
		if (y < 0) hasneg  = true;
		xs[i] = x;
		ys[i] = y;
	}

	if (hasneg) {
		for (int i = 0; i < n; i++) {
			ys[i] = 0-ys[i];
		}
	}

	if (hasneg && haspos) {
		cout << -1 << endl;
		return 0;
	}

	cout << fixed << setprecision(15);

	double lo = 0;
	double hi = 1e16;


	// while (!go(hi)) hi*= 2.0;
	for (int i = 0; i <= 150; i++) {
		double mid = (lo+hi)/2.0;
		if (go(mid)) hi = mid;
		else lo = mid;
	}

	cout << lo << endl;


}