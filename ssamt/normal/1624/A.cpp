#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d", &n);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		int max_val = INT_MIN;
		int min_val = INT_MAX;
		for(i=0; i<n; i++) {
			max_val = max(max_val, a[i]);
			min_val = min(min_val, a[i]);
		}
		printf("%d\n", max_val-min_val);
	}
}