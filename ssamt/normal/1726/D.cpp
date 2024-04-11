#include <bits/stdc++.h>

using namespace std;

int main() {
	int i, j, k, l;
	int t, n, m, q;
	cin >> t;
	for(int cl=0; cl<t; cl++) {
		scanf("%d %d", &n, &m);
		vector<vector<int>> a;
		vector<vector<int>> b(n);
		for(i=0; i<m; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			u--, v--;
			if(u > v) {
				swap(u, v);
			}
			a.push_back({u, v});
			b[u].push_back(i);
			b[v].push_back(i);
		}
		vector<int> answer(m, 0);
		vector<int> visited(n, 0);
		queue<int> to;
		to.push(0);
		visited[0] = 1;
		while(!to.empty()) {
			int node = to.front();
			to.pop();
			for(int idx:b[node]) {
				int con = a[idx][0]+a[idx][1]-node;
				if(!visited[con]) {
					answer[idx] = 1;
					visited[con] = 1;
					to.push(con);
				}
			}
		}
		set<int> nodes;
		int shift;
		int edge;
		for(i=0; i<m; i++) {
			if(!answer[i]) {
				shift = a[i][0];
				edge = i;
				nodes.insert(a[i][0]);
				nodes.insert(a[i][1]);
			}
		}
		if(nodes.size() == 3) {
			for(int idx:b[shift]) {
				if(answer[idx]) {
					answer[idx] = 0;
					answer[edge] = 1;
				}
			}
		}
		for(i=0; i<m; i++) {
			printf("%d", answer[i]);
		}
		printf("\n");
	}
}