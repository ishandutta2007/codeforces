#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d", &n);
		int a[n];
		long long sum = 0;
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
			sum += a[i];
		}
		if(sum%n == 0) {
			printf("0\n");
		} else {
			printf("1\n");
		}
	}
}