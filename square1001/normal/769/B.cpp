#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int n, c, a[109];
int main() {
	scanf("%d", &n);
	int sum = 0;
	for (int i = 0; i < n; i++) scanf("%d", &a[i]), sum += a[i];
	if (a[0] == 0 || sum <= n - 2) printf("-1\n");
	else {
		printf("%d\n", n - 1);
		vector<int> x, y;
		for (int i = 0; i < n; i++) {
			if (a[i] >= 1) x.push_back(i);
			else y.push_back(i);
		}
		for (int i = 0; i < x.size() - 1; i++) {
			printf("%d %d\n", x[i] + 1, x[i + 1] + 1); a[x[i]]--;
		}
		int p = 0;
		for (int i = 0; i < x.size(); i++) {
			while (p < y.size() && a[x[i]] > 0) {
				printf("%d %d\n", x[i] + 1, y[p] + 1); p++; a[x[i]]--;
			}
		}
	}
	return 0;
}