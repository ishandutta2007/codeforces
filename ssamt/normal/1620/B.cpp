#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		long long w, h;
		scanf("%lld %lld", &w, &h);
		long long answer = 0;
		for(i=0; i<2; i++) {
			scanf("%d", &k);
			int min_val = INT_MAX;
			int max_val = INT_MIN;
			for(j=0; j<k; j++) {
				scanf("%d", &in);
				min_val = min(min_val, in);
				max_val = max(max_val, in);
			}
			answer = max(answer, (max_val-min_val)*h);
		}
		for(i=0; i<2; i++) {
			scanf("%d", &k);
			int min_val = INT_MAX;
			int max_val = INT_MIN;
			for(j=0; j<k; j++) {
				scanf("%d", &in);
				min_val = min(min_val, in);
				max_val = max(max_val, in);
			}
			answer = max(answer, (max_val-min_val)*w);
		}
		printf("%lld\n", answer);
	}
}