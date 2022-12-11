#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int opt[5000][5000];

int main() {

	for (int i = 0; i < 5000; ++i) {
		for (int j = 0; j < 5000; ++j) {
			opt[i][j] = 500000000;
		}
	}

	int n; scanf("%d", &n);
	vector<int> arr;
	for (int i = 0; i < n; ++i) {
		int ci; scanf("%d", &ci);
		if (arr.empty() || arr.back() != ci) arr.push_back(ci);
	}	
	n = arr.size();
	for (int i = 0; i < n; ++i) opt[i][i] = 0;
	for (int k = 1; k < n; ++k) {
		for (int i = 0; i < n - k; ++i) {
			opt[i][i+k] = min(opt[i][i+k-1] + 1, opt[i+1][i+k] + 1);
			if (arr[i] == arr[i+k] && k > 1) opt[i][i+k] = min(opt[i][i+k], opt[i+1][i+k-1] + 1);
		}
	}
	printf("%d\n", opt[0][n-1]);
	return 0;
}