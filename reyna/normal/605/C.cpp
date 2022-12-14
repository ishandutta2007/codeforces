//In the name of God
// ...

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin (P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax (P &a, Q b) { if (a < b) a = b; return a; }



const int N = 1e5 + 5;
const int mod = 0;
const int base = 1000 * 1000 + 3;
const int oo = 1e9 + 9;

int read() { int x; cin >> x; return x; }
int n, m;
double p, q;
pair<double, double> a[N], b[N], lastb[N], lasta[N];

double reach(double x, double y) {
	if (x >= 0)
		return 0;
	if (y < 0)
		return 2;
	return 1 - (y / (y - x));
}

bool check(double x, int i, int j) {
	if (i > j)
		swap(i, j);
	if (a[j].first * x < p)
		return 0;
	if (a[i].second * x < q)
		return 0;
	if (reach(a[i].first - p / x, a[j].first - p / x) + reach(a[j].second - q / x, a[i].second - q / x) <= 1)
		return 1;
	return 0;
}

double f(int i, int j) {
	double bl = 0, br = 1e6 + 6;
	for (int x = 0; x < 60; ++x) {
		double bm = (bl + br) / 2;
		if (check(bm, i, j))
			br = bm;
		else
			bl = bm;
	}
	return br;
}

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	n = read(), p = (double) read(), q = (double) read();
	for (int i = 0; i < n; ++i)
		lasta[i] = {(double) read(), (double) read()};
	sort(lasta, lasta + n);
	double mx = 0;
	for (int i = n - 1; ~i; --i) {
		if (mx < lasta[i].second)
			b[m] = {lasta[i].second, lasta[i].first}, a[m++] = lasta[i];
		mx = max(mx, lasta[i].second);
	}
	n = m;
	sort(a, a + n);
	double best = 1e6 + 6;
	int pt = 0;
	for (int i = n - 1; i >= 0; --i) {
		best = min(best, max(p / a[i].first, q / a[i].second));
		while (pt < n - 1 && f(i, pt) >= f(i, pt + 1))
			pt++;
		for (int j = max(0, pt - 8); j <= min(n - 1, pt); j++)
			best = min(best, f(i, j));
	}
	cout << setprecision(9) << fixed << best << endl;
	
}