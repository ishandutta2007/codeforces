#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d", &n);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		int large = *max_element(a, a+n);
		long long sum = 0;
		for(i=0; i<n; i++) {
			sum += a[i];
		}
		if(sum == 0) {
			printf("0\n");
		} else if(large <= sum-large) {
			printf("1\n");
		} else {
			printf("%d\n", 2*large-sum);
		}
	}
}