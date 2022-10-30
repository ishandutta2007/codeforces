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
		scanf("%d %d", &n, &k);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		vector<vector<int>> idx;
		for(i=0; i<n; i++) {
			idx.push_back({a[i]+i, i});
		}
		sort(idx.begin(), idx.end());
		int take[n] = {};
		for(i=0; i<k; i++) {
			take[idx[n-1-i][1]] = 1;
		}
		long long answer = 0;
		int add = 0;
		for(i=0; i<n; i++) {
			if(take[i]) {
				add++;
			} else {
				answer += a[i]+add;
			}
		}
		printf("%lld\n", answer);
	}
}