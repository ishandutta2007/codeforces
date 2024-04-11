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
		vector<vector<int>> a[n];
		for(i=0; i<n-1; i++) {
			scanf("%d %d", &u, &v);
			u--, v--;
			a[u].push_back({v, i});
			a[v].push_back({u, i});
		}
		int pos = 1;
		int start;
		for(i=0; i<n; i++) {
			if(a[i].size() > 2) {
				pos = 0;
			}
			if(a[i].size() == 1) {
				start = i;
			}
		}
		if(pos) {
			int state = 2;
			int answer[n-1];
			int visited[n] = {};
			queue<int> to;
			to.push(start);
			visited[start] = 1;
			while(!to.empty()) {
				int node = to.front();
				to.pop();
				for(vector<int> con:a[node]) {
					if(!visited[con[0]]) {
						visited[con[0]] = 1;
						to.push(con[0]);
						answer[con[1]] = state;
						state = 5-state;
					}
				}
			}
			for(i=0; i<n-1; i++) {
				printf("%d ", answer[i]);
			}
			printf("\n");
		} else {
			printf("-1\n");
		}
	}
}