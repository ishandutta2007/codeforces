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
		scanf("%d %d", &n, &m);
		long long c[n][m];
		vector<vector<long long>> sum;
		for(i=0; i<n; i++) {
			long long val = 0;
			for(j=0; j<m; j++) {
				scanf("%lld", &c[i][j]);
				val += c[i][j]*j;
			}
			sum.push_back({val, i});
		}
		sort(sum.begin(), sum.end());
		printf("%lld %lld\n", sum.back()[1]+1, sum.back()[0]-sum[0][0]);
	}
}