#include <bits/stdc++.h>

using namespace std;
#define int long long
#define double long double
int n;
vector<double> x, v;
void read() {
	cin >> n;
	x.resize(n);
	for (auto &i : x)
		cin >> i;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
}

bool check(double t) {
	double l = x[0] - t * v[0], r = x[0] + t * v[0];
	for (int i = 1; i < n; i++) {
		double lx = x[i] - t * v[i], rx = x[i] + t * v[i];
		if (lx > r || rx < l)
			return false;
		l = max(l, lx);
		r = min(r, rx);
	}
	return r >= l;
}

double ans;
void run() {
	double l = -1, r = 1e9 + 10;
	while (abs(r - l) > 1e-7) {
		double mid = (l + r) / 2;
		if (check(mid))
			r = mid;
		else
			l = mid;
	}
	ans = r;
} 

void write() {
	cout.precision(20);
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}