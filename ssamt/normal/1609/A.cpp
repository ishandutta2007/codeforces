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
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		long long answer = 1;
		for(i=0; i<n; i++) {
			while(a[i]%2 == 0) {
				a[i] /= 2;
				answer *= 2;
			}
		}
		int max_val = a[0];
		for(i=1; i<n; i++) {
			max_val = max(max_val, a[i]);
		}
		answer *= max_val;
		for(i=0; i<n; i++) {
			answer += a[i];
		}
		answer -= max_val;
		printf("%lld\n", answer);
	}
}