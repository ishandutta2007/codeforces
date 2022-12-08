#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int n;
	cin >> n;
	// x y v
	double x, y, v;
	double mi = 1000000000.0;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> v;
		double dist = sqrt(pow(a-x,2) + pow(b-y,2)) / v;
		mi = min(mi, dist);
	}
	cout << fixed;
	cout << setprecision(7);
	cout << mi << endl;
	// cin >> n;
}