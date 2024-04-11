#include <iostream>
#include <cmath>

using namespace std;

int main() {
	long long t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		double a, b;
		cin >> a >> b;
		cout << (long long)(ceil(abs(a - b) / 10)) << '\n';
	}
	return 0;
}