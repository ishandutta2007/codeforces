#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, xa, ya, xb, yb, xt, yt, x[100009], y[100009]; double l[100009], a[100009], b[100009];
int main() {
	scanf("%d %d %d %d %d %d", &xa, &ya, &xb, &yb, &xt, &yt);
	scanf("%d", &n);
	vector<pair<double, int> > la, lb;
	la.push_back(make_pair(0.0, -1));
	lb.push_back(make_pair(0.0, -1));
	double sum = 0.0;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x[i], &y[i]);
		l[i] = hypot(1.0 * (xt - x[i]), 1.0 * (yt - y[i]));
		a[i] = hypot(1.0 * (xa - x[i]), 1.0 * (ya - y[i]));
		b[i] = hypot(1.0 * (xb - x[i]), 1.0 * (yb - y[i]));
		la.push_back(make_pair(a[i] - l[i], i));
		lb.push_back(make_pair(b[i] - l[i], i));
		sum += l[i];
	}
	sort(la.begin(), la.end());
	sort(lb.begin(), lb.end());
	double ret = 1.0e+30;
	for (int i = 0; i < 3 && i < la.size(); i++) {
		for (int j = 0; j < 3 && j < lb.size(); j++) {
			if (la[i].second != lb[j].second) ret = min(ret, 2 * sum + la[i].first + lb[j].first);
		}
	}
	printf("%.9lf\n", ret);
	return 0;
}