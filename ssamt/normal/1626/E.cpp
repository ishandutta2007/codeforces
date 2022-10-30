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
		vector<int> parent;
		vector<int> order;
		
		void bfs_tree(Graph& g, int r) {
			int i;
			for(i=0; i<n; i++) {
				parent.push_back(0);
			}
			int visited[n] = {};
			queue<int> to;
			parent[r] = -1;
			order.push_back(r);
			to.push(r);
			visited[r] = 1;
			while(!to.empty()) {
				int node = to.front();
				to.pop();
				for(int con:g.a[node]) {
					if(!visited[con]) {
						parent[con] = node;
						order.push_back(con);
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
	int i, j, k, l;
	int t, n, q;
	int u, v;
	int in;
	scanf("%d", &n);
	int b[n];
	int total = 0;
	for(i=0; i<n; i++) {
		scanf("%d", &b[i]);
		total += b[i];
	}
	Graph g(n);
	for(i=0; i<n-1; i++) {
		scanf("%d %d", &u, &v);
		u--; v--;
		g.add(u, v);
	}
	Tree tr(n);
	tr.bfs_tree(g, 0);
	int cb[n] = {};
	for(i=n-1; i>=0; i--) {
		if(b[tr.order[i]]) {
			cb[tr.order[i]]++;
		}
		cb[tr.parent[tr.order[i]]] += cb[tr.order[i]];
	}
	vector<int> nb;
	for(i=0; i<n; i++) {
		for(int con:tr.a[i]) {
			if(b[con]) {
				nb.push_back(i);
			}
		}
	}
	for(i=0; i<nb.size(); i++) {
		b[nb[i]] = 1;
	}
	int visited[n] = {};
	queue<int> to;
	for(i=0; i<n; i++) {
		if(b[i]) {
			to.push(i);
			visited[i] = 1;
		}
	}
	while(!to.empty()) {
		int node = to.front();
		to.pop();
		for(int con:tr.a[node]) {
			if(!visited[con]) {
				if((con == tr.parent[node] && cb[node] >= 2) || (con != tr.parent[node] && total-cb[con] >= 2)) {
					b[con] = 1;
					visited[con] = 1;
					to.push(con);
				}
			}
		}
	}
	for(i=0; i<n; i++) {
		printf("%d ", b[i]);
	}
	printf("\n");
}