#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	int n; scanf("%d", &n);
	vector<int> kid(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &kid[i]);
	}
	sort(kid.begin(), kid.end());
	for (int i = 0; i < n; i += 2) {
		printf("%d ", kid[i]);
	}
	vector<int> oddk;
	for (int i = 1; i < n; i += 2) {
		oddk.push_back(kid[i]);
	}
	reverse(oddk.begin(), oddk.end());
	for (int x : oddk) printf("%d ", x);
	printf("\n");
	return 0;
}