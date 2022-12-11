#include <bits/stdc++.h>

using namespace std;

bool solve() {
	int n, k; scanf("%d %d", &n, &k);
	vector<int> arr(n); 
	for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
	if (n == 1) {
		return arr[0] == k;	
	}
	bool mayroongK = false;
	for (int x : arr) if (x == k) mayroongK = true;
	if (!mayroongK) return false;
	bool pwedeBa = false;
	for (int i = 0; i + 1 < n; ++i) {
		if (arr[i] >= k && arr[i+1] >= k) pwedeBa = true;
	}
	for (int i = 0; i + 2 < n; ++i) {
		if (arr[i] >= k && arr[i+2] >= k) pwedeBa = true;
	}
	return pwedeBa;
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		if (solve()) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}