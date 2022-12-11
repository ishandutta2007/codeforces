#include <bits/stdc++.h>

using namespace std;

int main() {
	double PI = 2 * acos(0);
	int t; scanf("%d", &t);
	while (t--) {
		int n;	scanf("%d", &n);
		printf("%.8lf\n", 1 / (tan(PI / (n*2))));
	}
	return 0;
}