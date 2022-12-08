#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	double R, x1, y1, x2, y2;
	cin >> R >> x1 >> y1 >> x2 >> y2;
	cout << fixed << setprecision(10);
	double dist = sqrt((y2-y1)*(y2-y1) + (x2-x1)*(x2-x1));
	// cout << "dist   " << dist << endl;
	if (dist >= R) {
		cout << x1 << " " << y1 << " " << R << endl;
		return 0;
	}
	if (dist == 0) {
		cout << (2.0*x1+R)/2.0 << " " << (y1+y2)/2.0 << " " << R/2.0 << endl;
		return 0;
	}

	double x = ((x1-x2)*(dist+R)/dist + 2.0*x2)/2.0;
	double y = ((y1-y2)*(dist+R)/dist + 2.0*y2)/2.0;
	double r = sqrt((x-x2)*(x-x2)+(y-y2)*(y-y2));
	cout << x << " " << y << " " << r << endl;
	cin >> x1;

}