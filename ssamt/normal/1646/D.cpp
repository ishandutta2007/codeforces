#include <bits/stdc++.h>

using namespace std;

class Graph {
	public:
		int n;
		std::vector<set<int> > a;

		Graph(int nodes) {
		    int i;
            n = nodes;
            for(i=0; i<n; i++) {
                set<int> e;
                a.push_back(e);
            }
		}
		
		void add(int i, int j) {
			a[i].insert(j);
		}

		void del(int i, int j) {
			a[i].erase(j);
		}

		void add_both(int i, int j) {
			add(i, j);
			add(j, i);
		}

		void del_both(int i, int j) {
			del(i, j);
			del(j, i);
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
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	scanf("%d", &n);
	Graph g(n);
	for(i=0; i<n-1; i++) {
		scanf("%d %d", &u, &v);
		u--, v--;
		g.add_both(u, v);
	}
	if(n == 2) {
		printf("2 2\n");
		printf("1 1\n");
	} else {
		int p[n] = {-1};
		vector<vector<int>> d[n];
		int visited[n] = {};
		visited[0] = 1;
		function<void(int)> dfs = [&](int node) {
			for(int con:g.a[node]) {
				if(!visited[con]) {
					p[con] = node;
					visited[con] = 1;
					dfs(con);
				}
			}
			vector<int> get = {0, -1};
			for(int con:g.a[node]) {
				if(con != p[node]) {
					vector<int> add = max(d[con][0], d[con][1]);
					get[0] += add[0];
					get[1] += add[1];
				}
			}
			d[node].push_back(get);
			get = {1, -g.a[node].size()};
			for(int con:g.a[node]) {
				if(con != p[node]) {
					vector<int> add = d[con][0];
					get[0] += add[0];
					get[1] += add[1];
				}
			}
			d[node].push_back(get);
		};
		dfs(0);
		int w[n];
		function<void(int)> dfs2 = [&](int node) {
			if(node == 0 || w[p[node]] != g.a[p[node]].size()) {
				if(d[node][0] > d[node][1]) {
					w[node] = 1;
				} else {
					w[node] = g.a[node].size();
				}
			} else {
				w[node] = 1;
			}
			for(int con:g.a[node]) {
				if(con != p[node]) {
					dfs2(con);
				}
			}
		};
		dfs2(0);
		vector<int> answer = max(d[0][0], d[0][1]);
		printf("%d %d\n", answer[0], -answer[1]);
		for(i=0; i<n; i++) {
			printf("%d ", w[i]);
		}
		printf("\n");
	}
}