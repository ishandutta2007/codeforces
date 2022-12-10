#include <bits/stdc++.h>

using namespace std;

int main() {
	double r;
	double d;
	cin >> r >> d;
	int n;
	cin >> n;
	int count = 0;
	double x, y, ri;
	for (int i = 0; i < n; i++) {
		cin >> x >> y>> ri;
		double dist = sqrt(x*x + y*y);
		if (dist - ri < 0) continue;
		if (dist - ri >= r-d && dist+ri <= r) count++;
	}
	cout << count << endl;
	cin >>  r;
}