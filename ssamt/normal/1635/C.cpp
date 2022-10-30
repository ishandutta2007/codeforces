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
		scanf("%d", &n);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		int mx[n];
		mx[n-1] = n-1;
		for(i=n-2; i>=0; i--) {
			if(a[i] > a[mx[i+1]]) {
				mx[i] = i;
			} else {
				mx[i] = mx[i+1];
			}
		}
		int ch[n];
		ch[n-2] = n-2;
		for(i=n-3; i>=0; i--) {
			if(a[i]-a[mx[i+1]] < a[ch[i+1]]-a[mx[ch[i+1]+1]]) {
				ch[i] = i;
			} else {
				ch[i] = ch[i+1];
			}
		}
		vector<vector<int>> ans;
		for(i=0; i<n-2; i++) {
			int val = a[ch[i+1]]-a[mx[ch[i+1]+1]];
			if(val < a[i] || (i > 0 && a[i] < a[i-1])) {
				ans.push_back({i, ch[i+1], mx[ch[i+1]+1]});
				a[i] = val;
			}
		}
		int check = 1;
		for(i=0; i<n-1; i++) {
			if(a[i] > a[i+1]) {
				check = 0;
			}
		}
		if(check) {
			printf("%d\n", ans.size());
			for(i=0; i<ans.size(); i++) {
				for(j=0; j<ans[i].size(); j++) {
					printf("%d ", ans[i][j]+1);
				}
				printf("\n");
			}
		} else {
			printf("-1\n");
		}
	}
}