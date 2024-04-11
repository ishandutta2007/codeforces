#include <bits/stdc++.h>
using namespace std;

int n, k;
double l, v1, v2, t;

int main() {
//	freopen("d.in", "r", stdin);
	cin >> n >> l >> v1 >> v2 >> k;
	n = (n + k - 1) / k;
	t = l / ((v1 + (v2 - v1) * v1 / (v1 + v2)) * (n - 1) + v2);
	printf("%.12lf\n", t * n + t * (v2 - v1) / (v1 + v2) * (n - 1));
	return 0;
}