#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		getchar();
		scanf("%d %d", &n, &m);
		int a[n][2];
		long long sum[2] = {};
		for(i=0; i<n; i++) {
			for(j=0; j<2; j++) {
				scanf("%d", &a[i][j]);
				sum[j] += a[i][j];
			}
		}
		int low[n], high[n];
		long long low_sum = 0, high_sum = 0;
		for(i=0; i<n; i++) {
			low[i] = max(0, m-a[i][1]);
			low_sum += low[i];
			high[i] = min(m, a[i][0]);
			high_sum += high[i];
		}
		long long opt = (sum[0]-sum[1]+(long long)n*m)/2;
		long long take = min(high_sum, max(low_sum, opt))-low_sum;
		printf("%lld\n", abs((sum[0]-(take+low_sum))-(sum[1]-((long long)n*m-(take+low_sum)))));
		for(i=0; i<n; i++) {
			if(take > 0) {
				int answer = min(take+low[i], (long long)high[i]);
				printf("%d %d\n", answer, m-answer);
				take -= answer-low[i];
			} else {
				printf("%d %d\n", low[i], m-low[i]);
			}
		}
	}
}