#include <bits/stdc++.h>

using namespace std;

int main() {
	double a, b, c, d;
	cin >> a >> b >> c >> d;
	double frac = a/b;

	double rat = (1-(a/b))*(1-(c/d));
	cout << fixed << setprecision(10);
	cout << (frac)/(1-rat) << endl;
	cin >> a;
}