#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#pragma warning(disable : 4996)
using namespace std;
int n, x[60009], v[60009];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &x[i]);
	for (int i = 0; i < n; i++) scanf("%d", &v[i]);
	double l = 0.0, r = 1.0e+10;
	for (int i = 0; i < 100; i++) {
		double m = (l + r) * 0.5;
		double pl = -1.0e+20, pr = 1.0e+20;
		for (int j = 0; j < n; j++) {
			pl = max(pl, x[j] - m * v[j]);
			pr = min(pr, x[j] + m * v[j]);
		}
		if (pl > pr) l = m;
		else r = m;
	}
	printf("%.9f\n", l);
	return 0;
}