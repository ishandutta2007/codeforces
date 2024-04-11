#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
const long double PI = 3.14159265358979323846264L;
int n, a[100009], c[100009]; vector<pair<long double, int>>X;
int main() {
	cin >> n; for (int i = 0; i < n; i++)cin >> a[i];
	long double I = cos(PI / n);
	for (int i = 0; i < n; i++) {
		int V = (n - a[i]), W = a[(i + 1) % n]; long double F = -1; if (V > W) { F = 1; swap(V, W); }
		long double I1 = 1.0L*n + (2.0L*I*V);
		long double I2 = 1.0L*n + (2.0L*I*W); I2 *= (1.0L*V / W);
		X.push_back(make_pair((F*(I2 - I1))*max(V, W), i));
	}
	sort(X.begin(), X.end());
	for (int i = 0; i < X.size(); i++) {
		c[X[i].second] = i;
	}
	for (int i = 0; i < n; i++) { if (i)cout << ' '; cout << c[i]; }
	cout << endl;
	return 0;
}