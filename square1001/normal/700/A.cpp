#include <iomanip>
#include <iostream>
using namespace std;
int n, l, v1, v2, m;
int main() {
	cin >> n >> l >> v1 >> v2 >> m;
	n = (n + m - 1) / m;
	double p = 1.0 * l * (v1 + v2) / (2.0 * n * v1 + v2 - v1);
	cout << fixed << setprecision(15) << p / v2 + (l - p) / v1 << endl;
	return 0;
}