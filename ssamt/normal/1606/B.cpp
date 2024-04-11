#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k;
	int t, n, m, q;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		long long n, k;
		scanf("%lld %lld", &n, &k);
		long long a = 1;
		long long answer = 0;
		while(a <= k && a < n) {
			a *= 2;
			answer++;
		}
		if(n-a-1 >= 0) {
			answer += (n-a-1)/k+1;
		}
		printf("%lld\n", answer);
	}
}