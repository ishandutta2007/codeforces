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
	long long i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	cin >> t;
	for(cl=0; cl<t; cl++) {
		cin >> n;
		Graph g(n);
		for(i=0; i<n-1; i++) {
			cin >> u >> v;
			u--, v--;
			g.add_both(u, v);
		}
		int par[n];
		par[0] = 1;
		int visited[n] = {};
		visited[0] = 1;
		function<void(int)> dfs = [&](int node) {
			for(int con:g.a[node]) {
				if(!visited[con]) {
					visited[con] = 1;
					par[con] = 1-par[node];
					dfs(con);
				}
			}
		};
		dfs(0);
		for(i=0; i<n; i++) {
			if(par[i]) {
				cout << g.a[i].size() << " ";
			} else {
				cout << -(int)g.a[i].size() << " ";
			}
		}
		cout << endl;
	}
}