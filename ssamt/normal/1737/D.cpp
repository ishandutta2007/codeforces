#include <bits/stdc++.h>

using namespace std;

class Graph {
	public:
		int n;
		vector<vector<int>> a;

		Graph(int nodes) {
		    int i;
            n = nodes;
            for(i=0; i<n; i++) {
                vector<int> e;
                a.push_back(e);
            }
		}
		
		void add(int i, int j) {
			a[i].push_back(j);
		}

		void add_both(int i, int j) {
			add(i, j);
			add(j, i);
		}
		
		void print() {
			int i, j;
			for(i=0; i<a.size(); i++) {
				printf("%d: ", i);
				for(int con:a[i]) {
					printf("%d ", con);
				}
				printf("\n");
			}
		}
};

int main() {
	int i, j, k, l;
	int t, n, m, q;
	scanf("%d", &t);
	for(int cl=0; cl<t; cl++) {
		scanf("%d %d", &n, &m);
		Graph g(n);
		vector<vector<int>> d(m, vector<int>(3));
		for(i=0; i<m; i++) {
			for(j=0; j<3; j++) {
				scanf("%d", &d[i][j]);
			}
			d[i][0]--, d[i][1]--;
			g.add_both(d[i][0], d[i][1]);
		}
		vector<vector<int>> r(n, vector<int>(n, INT_MAX));
		r[0][n-1] = 1;
		queue<vector<int>> to;
		to.push({0, n-1});
		while(!to.empty()) {
			vector<int> node = to.front();
			int u = node[0], v = node[1];
			to.pop();
			for(int con:g.a[u]) {
				int tu = min(con, v), tv = max(con, v);
				if(r[u][v]+1 < r[tu][tv]) {
					r[tu][tv] = r[u][v]+1;
					to.push({tu, tv});
				}
			}
			for(int con:g.a[v]) {
				int tu = min(con, u), tv = max(con, u);
				if(r[u][v]+1 < r[tu][tv]) {
					r[tu][tv] = r[u][v]+1;
					to.push({tu, tv});
				}
			}
			if(u == v) {
				for(i=0; i<n; i++) {
					int tu = min(i, u), tv = max(i, u);
					if(r[u][v]+1 < r[tu][tv]) {
						r[tu][tv] = r[u][v]+1;
						to.push({tu, tv});
					}
				}
			}
		}
		for(i=0; i<n; i++) {
			for(j=0; j<i; j++) {
				r[i][j] = r[j][i];
			}
		}
		/*for(i=0; i<n; i++) {
			for(j=0; j<n; j++) {
				printf("%d ", r[i][j]);
			}
			printf("\n");
		}*/
		long long answer = LLONG_MAX;
		for(i=0; i<m; i++) {
			answer = min(answer, (long long)d[i][2]*r[d[i][0]][d[i][1]]);
		}
		printf("%lld\n", answer);
	}
}