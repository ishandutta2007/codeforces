#include <bits/stdc++.h>

using namespace std;

int main() {
	int i, j, k, l;
	int t, n, m, q;
	scanf("%d", &t);
	for(int cl=0; cl<t; cl++) {
		scanf("%d", &n);
		vector<long long> a(n), b(n);
		for(i=0; i<n; i++) {
			scanf("%lld", &a[i]);
		}
		for(i=0; i<n; i++) {
			scanf("%lld", &b[i]);
		}
		long long answer = 0;
		for(i=0; i<n-1; i++) {
			answer += min(abs(a[i+1]-a[i])+abs(b[i+1]-b[i]), abs(a[i+1]-b[i])+abs(b[i+1]-a[i]));
		}
		printf("%lld\n", answer);
	}
}