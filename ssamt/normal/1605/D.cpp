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
			a[j].insert(i);
		}

		void del(int i, int j) {
			a[i].erase(j);
			a[j].erase(i);
		}
		
		vector<int> path(int u, int v) {
			int i;
			int pred[n] = {};
			int visited[n] = {};
			queue<int> to;
			to.push(u);
			visited[u] = 1;
			while(!to.empty()) {
				int node = to.front();
				to.pop();
				for(int con:a[node]) {
					if(!visited[con]) {
						pred[con] = node;
						if(con == v) {
							vector<int> rev;
							while(v != u) {
								rev.push_back(v);
								v = pred[v];
							}
							rev.push_back(u);
							vector<int> answer;
							for(i=rev.size()-1; i>=0; i--) {
								answer.push_back(rev[i]);
							}
							return answer;
						}
						visited[con] = 1;
						to.push(con);
					}
				}
			}
			return vector<int>{};
		}
		
		vector<vector<int> > components() {
			int i;
			int visited[n] = {};
			queue<int> to;
			vector<vector<int> > answer;
			for(i=0; i<n; i++) {
				if(!visited[i]) {
					vector<int> e;
					visited[i] = 1;
					to.push(i);
					e.push_back(i);
					while(!to.empty()) {
						int node = to.front();
						to.pop();
						for(int con:a[node]) {
							if(!visited[con]) {
								visited[con] = 1;
								to.push(con);
								e.push_back(con);
							}
						}
					}
					answer.push_back(e);
				}
			}
			return answer;
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

class Tree : public Graph {
	public:
		using Graph::Graph;
		
		void bfs_tree(Graph& g, int r) {
			int visited[n] = {};
			queue<int> to;
			to.push(r);
			visited[r] = 1;
			while(!to.empty()) {
				int node = to.front();
				to.pop();
				for(int con:g.a[node]) {
					if(!visited[con]) {
						add(node, con);
						visited[con] = 1;
						to.push(con);
					}
				}
			}
		}
		
		vector<int> depth() {
			vector<int> d(n, 0);
			int visited[n] = {};
			queue<int> to;
			to.push(0);
			visited[0] = 1;
			while(!to.empty()) {
				int node = to.front();
				to.pop();
				for(int con:a[node]) {
					if(!visited[con]) {
						d[con] = d[node]+1;
						visited[con] = 1;
						to.push(con);
					}
				}
			}
			return d;
		}
};

int main() {
	int cl, ql;
	int i, j, k;
	int t, n, m, q;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d", &n);
		Tree g(n);
		int u, v;
		for(i=0; i<n-1; i++) {
			scanf("%d %d", &u, &v);
			g.add(u-1, v-1);
		}
		vector<int> d = g.depth();
		int even = 0;
		for(i=0; i<n; i++) {
			if(d[i]%2 == 0) {
				even++;
			}
		}
		int smaller[n] = {};
		int count = 0;
		if(2*even < n) {
			for(i=0; i<n; i++) {
				if(d[i]%2 == 0) {
					smaller[i] = 1;
					count++;
				}
			}
		} else {
			for(i=0; i<n; i++) {
				if(d[i]%2 == 1) {
					smaller[i] = 1;
					count++;
				}
			}
		}
		//printf("%d\n", even);
		vector<int> small, large;
		int log = 0;
		for(i=1; i<=n; i++) {
			if(i&(1<<(log+1))) {
				log++;
			}
			if(count&(1<<log)) {
				small.push_back(i);
			} else {
				large.push_back(i);
			}
		}
		j = k = 0;
		for(i=0; i<n; i++) {
			if(smaller[i]) {
				printf("%d ", small[j]);
				j++;
			} else {
				printf("%d ", large[k]);
				k++;
			}
		}
		printf("\n");
	}
}