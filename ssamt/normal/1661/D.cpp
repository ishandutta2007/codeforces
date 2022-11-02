#include <bits/stdc++.h>

using namespace std;

int main() {
	int i, j, k, l;
	int t, n, m, q;
	scanf("%d %d", &n, &k);
	vector<long long> a(n, 0), b(n);
	for(i=0; i<n; i++) {
		scanf("%lld", &b[i]);
	}
	long long stack = 0, sum = 0;
	for(i=n-1; i>=0; i--) {
		stack -= sum;
		b[i] -= stack;
		if(i >= k) {
			if(b[i] > 0) {
				a[i] = max(a[i], (b[i]-1)/k+1);
			}
			stack += k*a[i];
			sum += a[i];
		} else {
			if(b[i] > 0) {
				a[k-1] = max(a[k-1], (b[i]-1)/(i+1)+1);
			}
		}
		if(i+k < n) {
			sum -= a[i+k];
		}
	}
	long long answer = 0;
	for(i=0; i<n; i++) {
		answer += a[i];
		//printf("%d ", a[i]);
	}
	//printf("\n");
	printf("%lld\n", answer);
}