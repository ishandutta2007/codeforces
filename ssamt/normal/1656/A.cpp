#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d", &n);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		vector<vector<int>> idx;
		for(i=0; i<n; i++) {
			idx.push_back({a[i], i});
		}
		sort(idx.begin(), idx.end());
		printf("%d %d\n", idx[0][1]+1, idx.back()[1]+1);
	}
}