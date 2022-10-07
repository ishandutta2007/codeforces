#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double L, D, V, G, R;

double mod (double a, double b) {
	return a - b * int(a / b);
}

int main() {
	cin >> L >> D >> V >> G >> R;
	double t1 = D / V;
	double period = G + R;
	double tpart = mod(t1, period);

	if (tpart >= G) {
		t1 = t1 - tpart + period;
	}
	double t2 = (L - D) / V;
	double t = t1 + t2;

	cout << setprecision(12) << t << endl;
	return 0;
}