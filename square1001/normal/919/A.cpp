#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int n, m, a, b;
int main() {
	cin >> n >> m;
	double x = 1.0e+13;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		x = min(x, 1.0 * a / b);
	}
	cout << fixed << setprecision(15) << x * m << endl;
	return 0;
}