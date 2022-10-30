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
		vector<vector<int>> a;
		for(i=0; i<n; i++) {
			int l, r;
			scanf("%d %d", &l, &r);
			a.push_back({l, r});
		}
		sort(a.begin(), a.end());
		for(i=0; i<n; i++) {
			int answer;
			if(a[i][0] == a[i][1]) {
				answer = a[i][0];
			} else if(i == 0 || a[i][0] != a[i-1][0]) {
				answer = a[i][0];
			} else {
				answer = a[i-1][1]+1;
			}
			printf("%d %d %d\n", a[i][0], a[i][1], answer);
		}
		printf("\n");
	}
}