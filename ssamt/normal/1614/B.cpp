#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		int l, r;
		scanf("%d", &n);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		vector<vector<int>> idx;
		for(i=0; i<n; i++) {
			idx.push_back({a[i], i});
		}
		sort(idx.begin(), idx.end(), greater<vector<int>>());
		int x[n];
		long long answer = 0;
		for(i=0; i<n; i++) {
			if(i%2 == 0) {
				x[idx[i][1]] = i/2+1;
			} else {
				x[idx[i][1]] = -i/2-1;
			}
			answer += (long long)2*idx[i][0]*(i/2+1);
		}
		printf("%lld\n", answer);
		printf("0 ");
		for(i=0; i<n; i++) {
			printf("%d ", x[i]);
		}
		printf("\n");
	}
}