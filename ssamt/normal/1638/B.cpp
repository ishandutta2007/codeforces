#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	scanf("%d", &t);
	for(ql=0; ql<t; ql++) {
		scanf("%d", &n);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		vector<vector<int>> par{{}, {}};
		for(i=0; i<n; i++) {
			par[a[i]%2].push_back(a[i]);
		}
		int check = 1;
		for(i=0; i<2; i++) {
			for(j=1; j<par[i].size(); j++) {
				if(par[i][j-1] > par[i][j]) {
					check = 0;
				}
			}
		}
		if(check) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}