#include <bits/stdc++.h>

using namespace std;

int d[200000] = {};
class Graph {
	public:
		int n;
		std::vector<vector<vector<int>> > a;

		Graph(int nodes) {
		    int i;
            n = nodes;
            for(i=0; i<n; i++) {
                vector<vector<int>> e;
                a.push_back(e);
            }
		}

		void add(int i, int j, int k) {
			a[i].push_back({j, k});
			a[j].push_back({i, k});
		}
		
		bool connected() {
			int i;
			int visited[n] = {};
			queue<int> to;
			int count = 1;
			visited[0] = 1;
			to.push(0);
			while(!to.empty()) {
				int node = to.front();
				to.pop();
				for(vector<int> con:a[node]) {
					if(!d[con[1]]) {
						if(!visited[con[0]]) {
							visited[con[0]] = 1;
							count++;
							to.push(con[0]);
						}
					}
				}
			}
			return (count==n);
		}
};

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d %d", &n, &m);
		Graph g(n);
		int u[m], v[m], w[m];
		for(i=0; i<m; i++) {
			scanf("%d %d %d", &u[i], &v[i], &w[i]);
			u[i]--; v[i]--;
			g.add(u[i], v[i], i);
		}
		for(i=31; i>=0; i--) {
			vector<int> ret;
			for(j=0; j<m; j++) {
				if(w[j]&(1<<i) && !d[j]) {
					d[j] = 1;
					ret.push_back(j);
				}
			}
			if(ret.empty() || !g.connected()) {
				for(j=0; j<ret.size(); j++) {
					d[ret[j]] = 0;
				}
			}
		}
		int answer = 0;
		for(i=0; i<m; i++) {
			if(!d[i]) {
				answer |= w[i];
			}
			d[i] = 0;
		}
		printf("%d\n", answer);
	}
}