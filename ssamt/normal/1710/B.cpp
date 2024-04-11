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
		long long x[n], p[n];
		vector<vector<int>> sc;
		int count[100] = {};
		for(i=0; i<n; i++) {
			scanf("%lld %lld", &x[i], &p[i]);
			sc.push_back({x[i]-p[i], 1});
			sc.push_back({x[i], -2});
			sc.push_back({x[i]+p[i], 1});
		}
		sort(sc.begin(), sc.end());
		long long a = sc[0][1], b = 0;
		long long l = INT_MIN, r = INT_MIN;
		long long val = 0;
		for(i=1; i<sc.size(); i++) {
			b += a*(sc[i][0]-sc[i-1][0]);
			//printf("%d %d\n", sc[i][0], b);
			a += sc[i][1];
			val = max(val, b);
			if(b > m) {
				l = max(l, b-sc[i][0]);
				r = max(r, b+sc[i][0]);
			}
		}
		//printf("%d %d %d\n", l, r, val);
		for(i=0; i<n; i++) {
			if(val <= m || (l <= m+p[i]-x[i] && r <= m+p[i]+x[i])) {
				printf("1");
			} else {
				printf("0");
			}
		}
		printf("\n");
	}
}