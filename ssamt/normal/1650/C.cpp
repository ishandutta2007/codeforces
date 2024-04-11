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
		int x[m], w[m];
		for(i=0; i<m; i++) {
			scanf("%d %d", &x[i], &w[i]);
		}
		vector<vector<int>> s;
		for(i=0; i<m; i++) {
			s.push_back({w[i], i});
		}
		sort(s.begin(), s.end());
		vector<vector<int>> idx;
		long long sum = 0;
		for(i=0; i<2*n; i++) {
			sum += s[i][0];
			int ix = s[i][1];
			idx.push_back({x[ix], ix});
		}
		sort(idx.begin(), idx.end());
		printf("%lld\n", sum);
		for(i=0; i<n; i++) {
			printf("%d %d\n", idx[i][1]+1, idx[2*n-1-i][1]+1);
		}
	}
}