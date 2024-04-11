#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void PR(vi &v) { trav(x, v) cout << x << ' '; cout << endl; }

template<class F>
double gss(double a, double b, F f) {
	double r = (sqrt(5)-1)/2, eps = 1e-7;
	double x1 = b - r*(b-a), x2 = a + r*(b-a);
	double f1 = f(x1), f2 = f(x2);
	while (b-a > eps) {
		if (f1 < f2) { //change to > to find maximum
			b = x2; x2 = x1; f2 = f1;
			x1 = b - r*(b-a); f1 = f(x1);
		} else {
			a = x1; x1 = x2; f1 = f2;
			x2 = a + r*(b-a); f2 = f(x2);
		}
	}
	return f(a);
}

int main() {
	cin.sync_with_stdio(false);
	double x1, y1, X, Y;
	cin >> x1 >> y1 >> X >> Y;
	X -= x1; x1 = 0;
	Y -= y1; y1 = 0;
	double V, T;
	cin >> V >> T;
	double VX, VY, WX, WY;
	cin >> VX >> VY;
	cin >> WX >> WY;
	auto timeto = [V](double X, double Y, double VX, double VY) -> double {
		double n1 = sqrt(X*X + Y*Y);
		if (n1 == 0) return 0;

		double lo = 0, hi = 1e9;
		rep(it,0,100) {
			double mid = (lo + hi) / 2;
			double x = mid * X - VX;
			double y = mid * Y - VY;
			if (x*x + y*y > V*V)
				hi = mid;
			else
				lo = mid;
		}
		double v = lo;
		double x = v * X;
		double y = v * Y;
		return n1 / sqrt(x*x + y*y);
	};

	double t0 = timeto(X, Y, VX, VY);
	if (t0 <= T) {
		cout << setprecision(10) << fixed << t0 << endl;
		return 0;
	}

	double res = 1.0 / 0.0;
	rep(it,0,10) {
		double tpi = 2*3.14159265359;
		double lo = it * tpi / 10;
		double hi = (it+1) * tpi / 10;
		res = min(res, T + gss(lo, hi, [&](double ang) {
			double x = X - T * (V*cos(ang) + VX);
			double y = Y - T * (V*sin(ang) + VY);
			return timeto(x, y, WX, WY);
		}));
	}
	cout << setprecision(10) << fixed << res << endl;
}