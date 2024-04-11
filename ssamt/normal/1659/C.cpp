#include <bits/stdc++.h>

using namespace std;

int main() {
	int i, j, k, l;
	int t, n, m, q;
	scanf("%d", &t);
	for(int cl=0; cl<t; cl++) {
		long long a, b;
		scanf("%d %lld %lld", &n, &a, &b);
		n++;
		vector<int> x(n);
		x[0] = 0;
		for(i=1; i<n; i++) {
			scanf("%d", &x[i]);
		}
		long long cost = 0;
		long long answer = LLONG_MAX;
		for(i=1; i<n; i++) {
			cost += b*(x[i]-x[0]);
		}
		for(i=0; i<n; i++) {
			answer = min(answer, cost);
			if(i != n-1) {
				cost += a*(x[i+1]-x[i]);
				cost -= b*(n-2-i)*(x[i+1]-x[i]);
			}
		}
		printf("%lld\n", answer);
	}
}