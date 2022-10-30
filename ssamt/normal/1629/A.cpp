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
		int b[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		for(i=0; i<n; i++) {
			scanf("%d", &b[i]);
		}
		vector<vector<int>> s;
		for(i=0; i<n; i++) {
			s.push_back({a[i], b[i]});
		}
		sort(s.begin(), s.end());
		for(i=0; i<n; i++) {
			if(s[i][0] > k) {
				break;
			}
			k += s[i][1];
		}
		printf("%d\n", k);
	}
}